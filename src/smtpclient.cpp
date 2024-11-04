#include "smtpclient.h"
#include <QSslSocket>
#include <QObject>
#include <QCoreApplication>
SMTPClient::SMTPClient(const QString & host, int port, ConnectionType connectionType) :
    socket(NULL),
    name("localhost"),
    authMethod(AuthPlain),
    connectionTimeout(5000),
    responseTimeout(5000),
    sendMessageTimeout(60000)
{
    setConnectionType(connectionType);

    this->host = host;
    this->port = port;

    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(socketReadyRead()));
}

SMTPClient::~SMTPClient() {
    if (socket)
        delete socket;
}

/* [1] --- */


/* [2] Getters and Setters */

void SMTPClient::setUser(const QString &user)
{
    this->user = user;
}

void SMTPClient::setPassword(const QString &password)
{
    this->password = password;
}

void SMTPClient::setAuthMethod(AuthMethod method)
{
    this->authMethod = method;
}

void SMTPClient::setHost(const QString &host)
{
    this->host = host;
}

void SMTPClient::setPort(int port)
{
    this->port = port;
}

void SMTPClient::setConnectionType(ConnectionType ct)
{
    this->connectionType = ct;

    if (socket)
        delete socket;

    switch (connectionType)
    {
    case TcpConnection:
        socket = new QTcpSocket(this);
        break;
    case SslConnection:
    case TlsConnection:
        socket = new QSslSocket(this);
    }
}

const QString& SMTPClient::getHost() const
{
    return this->host;
}

const QString& SMTPClient::getUser() const
{
    return this->user;
}

const QString& SMTPClient::getPassword() const
{
    return this->password;
}

SMTPClient::AuthMethod SMTPClient::getAuthMethod() const
{
    return this->authMethod;
}

int SMTPClient::getPort() const
{
    return this->port;
}

SMTPClient::ConnectionType SMTPClient::getConnectionType() const
{
    return connectionType;
}

const QString& SMTPClient::getName() const
{
    return this->name;
}

void SMTPClient::setName(const QString &name)
{
    this->name = name;
}

const QString & SMTPClient::getResponseText() const
{
    return responseText;
}

int SMTPClient::getResponseCode() const
{
    return responseCode;
}

QTcpSocket* SMTPClient::getSocket() {
    return socket;
}

int SMTPClient::getConnectionTimeout() const
{
    return connectionTimeout;
}

void SMTPClient::setConnectionTimeout(int msec)
{
    connectionTimeout = msec;
}

int SMTPClient::getResponseTimeout() const
{
    return responseTimeout;
}

void SMTPClient::setResponseTimeout(int msec)
{
    responseTimeout = msec;
}
int SMTPClient::getSendMessageTimeout() const
{
  return sendMessageTimeout;
}
void SMTPClient::setSendMessageTimeout(int msec)
{
  sendMessageTimeout = msec;
}

/* [2] --- */


/* [3] Public methods */

bool SMTPClient::connectToHost()
{
    switch (connectionType)
    {
    case TlsConnection:
    case TcpConnection:
        socket->connectToHost(host, port);
        break;
    case SslConnection:
        ((QSslSocket*) socket)->connectToHostEncrypted(host, port);
        break;

    }

    // Tries to connect to server
    if (!socket->waitForConnected(connectionTimeout))
    {
        emit smtpError(ConnectionTimeoutError);
        return false;
    }

    try
    {
        // Wait for the server's response
        waitForResponse();

        // If the response code is not 220 (Service ready)
        // means that is something wrong with the server
        if (responseCode != 220)
        {
            emit smtpError(ServerError);
            return false;
        }

        // Send a EHLO/HELO message to the server
        // The client's first command must be EHLO/HELO
        sendMessage("EHLO " + name);

        // Wait for the server's response
        waitForResponse();

        // The response code needs to be 250.
        if (responseCode != 250) {
            emit smtpError(ServerError);
            return false;
        }

        if (connectionType == TlsConnection) {
            // send a request to start TLS handshake
            sendMessage("STARTTLS");

            // Wait for the server's response
            waitForResponse();

            // The response code needs to be 220.
            if (responseCode != 220) {
                emit smtpError(ServerError);
                return false;
            };

            ((QSslSocket*) socket)->startClientEncryption();

            if (!((QSslSocket*) socket)->waitForEncrypted(connectionTimeout)) {
                qDebug() << ((QSslSocket*) socket)->errorString();
                emit smtpError(ConnectionTimeoutError);
                return false;
            }

            // Send ELHO one more time
            sendMessage("EHLO " + name);

            // Wait for the server's response
            waitForResponse();

            // The response code needs to be 250.
            if (responseCode != 250) {
                emit smtpError(ServerError);
                return false;
            }
        }
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    // If no errors occured the function returns true.
    return true;
}

bool SMTPClient::login()
{
    return login(user, password, authMethod);
}

bool SMTPClient::login(const QString &user, const QString &password, AuthMethod method)
{
    try {
        if (method == AuthPlain)
        {
            // Sending command: AUTH PLAIN base64('\0' + username + '\0' + password)
            sendMessage("AUTH PLAIN " + QByteArray().append((char) 0).append(user).append((char) 0).append(password).toBase64());

            // Wait for the server's response
            waitForResponse();

            // If the response is not 235 then the authentication was faild
            if (responseCode != 235)
            {

                emit smtpError(AuthenticationFailedError);
                return false;
            }
        }
        else if (method == AuthLogin)
        {
            // Sending command: AUTH LOGIN
            sendMessage("AUTH LOGIN");

            // Wait for 334 response code
            waitForResponse();
            if (responseCode != 334) { emit smtpError(AuthenticationFailedError); return false; }

            // Send the username in base64
            sendMessage(QByteArray().append(user).toBase64());

            // Wait for 334
            waitForResponse();
            if (responseCode != 334) { emit smtpError(AuthenticationFailedError); return false; }

            // Send the password in base64
            sendMessage(QByteArray().append(password).toBase64());

            // Wait for the server's responce
            waitForResponse();

            // If the response is not 235 then the authentication was faild
            if (responseCode != 235)
            {
                emit smtpError(AuthenticationFailedError);
                return false;
            }
        }
    }
    catch (ResponseTimeoutException)
    {
        // Responce Timeout exceeded
        emit smtpError(AuthenticationFailedError);
        return false;
    }
    catch (SendMessageTimeoutException)
    {
    // Send Timeout exceeded
        emit smtpError(AuthenticationFailedError);
        return false;
    }

    return true;
}

bool SMTPClient::sendMail(MimeMessage& email)
{
    try
    {
        // Send the MAIL command with the sender
        sendMessage("MAIL FROM:<" + email.getSender().getAddress() + ">");

        waitForResponse();

        if (responseCode != 250) return false;

        // Send RCPT command for each recipient
        QList<EmailAddress*>::const_iterator it, itEnd;
        // To (primary recipients)
        for (it = email.getRecipients().begin(), itEnd = email.getRecipients().end();
             it != itEnd; ++it)
        {

            sendMessage("RCPT TO:<" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Cc (carbon copy)
        for (it = email.getRecipients(MimeMessage::Cc).begin(), itEnd = email.getRecipients(MimeMessage::Cc).end();
             it != itEnd; ++it)
        {
            sendMessage("RCPT TO:<" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Bcc (blind carbon copy)
        for (it = email.getRecipients(MimeMessage::Bcc).begin(), itEnd = email.getRecipients(MimeMessage::Bcc).end();
             it != itEnd; ++it)
        {
            sendMessage("RCPT TO:<" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Send DATA command
        sendMessage("DATA");
        waitForResponse();

        if (responseCode != 354) return false;

        sendMessage(email.toString());

        // Send \r\n.\r\n to end the mail data
        sendMessage(".");

        waitForResponse();

        if (responseCode != 250) return false;
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    return true;
}

void SMTPClient::quit()
{
    try
    {
        sendMessage("QUIT");
    }
    catch(SMTPClient::SendMessageTimeoutException)
    {
    //Manually close the connection to the smtp server if message "QUIT" wasn't received by the smtp server
        if(socket->state() == QAbstractSocket::ConnectedState || socket->state() == QAbstractSocket::ConnectingState || socket->state() == QAbstractSocket::HostLookupState)
            socket->disconnectFromHost();
    }
}

/* [3] --- */


/* [4] Protected methods */

void SMTPClient::waitForResponse()
{
    do {
        if (!socket->waitForReadyRead(responseTimeout))
        {
            emit smtpError(ResponseTimeoutError);
            throw ResponseTimeoutException();
        }

        if (!socket->isOpen()) {
            emit smtpError(ResponseTimeoutError);
            throw ResponseTimeoutException();
        }

        while (socket->canReadLine()) {
            // Save the server's response
            responseText = socket->readLine();

            // Extract the respose code from the server's responce (first 3 digits)
            responseCode = responseText.left(3).toInt();

            if (responseCode / 100 == 4)
                emit smtpError(ServerError);

            if (responseCode / 100 == 5)
                emit smtpError(ClientError);

            if (responseText[3] == ' ') { return; }
        }
    } while (true);
}

void SMTPClient::sendMessage(const QString &text)
{
    socket->write(text.toUtf8() + "\r\n");
    if (! socket->waitForBytesWritten(sendMessageTimeout))
    {
      emit smtpError(SendDataTimeoutError);
      throw SendMessageTimeoutException();
    }
}

/* [4] --- */


/* [5] Slots for the socket's signals */

void SMTPClient::socketStateChanged(QAbstractSocket::SocketState /*state*/)
{
}

void SMTPClient::socketError(QAbstractSocket::SocketError /*socketError*/)
{
}

void SMTPClient::socketReadyRead()
{
}

/* [5] --- */

/*SMTPClient::SMTPClient(const QString &user, const QString &pass,
           int timeout, const QString &host, int port)
    : timeout(timeout), from(user), user(user), pass(pass), host(host), port(port), state(Init)
{
    socket = new QSslSocket(this);
    t = new QTextStream(socket);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorReceived(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    qDebug() << "Connecting...";
    socket->connectToHostEncrypted(host, port);
    if (!socket->waitForConnected(timeout)) {
        qDebug() << "Error: " << socket->errorString();
        emit status(tr("Error: ") + socket->errorString());
    }
}


void SMTPClient::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body)
{
    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append(body);
    message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ),
    QString::fromLatin1( "\r\n..\r\n" ) );
    this->from = from;
    rcpt = to;
    state = Init;
    socket->connectToHostEncrypted(host, port); //"smtp.gmail.com" and 465 for gmail TLS
    if (!socket->waitForConnected(timeout)) {
         qDebug() << socket->errorString();
     }

    t = new QTextStream( socket );



}

SMTPClient::~SMTPClient()
{
    delete t;
    delete socket;
}
void SMTPClient::stateChanged(QAbstractSocket::SocketState socketState)
{

    qDebug() <<"stateChanged " << socketState;
}

void SMTPClient::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error " <<socketError;
}

void SMTPClient::disconnected()
{

    qDebug() <<"disconneted";
    qDebug() << "error "  << socket->errorString();
}

void SMTPClient::connected()
{
    qDebug() << "Connected ";
}

void SMTPClient::readyRead()
{

     qDebug() <<"readyRead";
    // SMTP is line-oriented

    QString responseLine;
    do
    {
        responseLine = socket->readLine();
        response += responseLine;
    }
    while ( socket->canReadLine() && responseLine[3] != ' ' );

    responseLine.truncate( 3 );

    qDebug() << "Server response code:" <<  responseLine;
    qDebug() << "Server response: " << response;

    if ( state == Init && responseLine == "220" )
    {
        // banner was okay, let's go on
        *t << "EHLO localhost" <<"\r\n";
        t->flush();

        state = HandShake;
    }
    //No need, because I'm using socket->startClienEncryption() which makes the SSL handshake for you
    else if (state == Tls && responseLine == "250")
    {
        // Trying AUTH
        qDebug() << "STarting Tls";
        *t << "STARTTLS" << "\r\n";
        t->flush();
        state = HandShake;
    }
    else if (state == HandShake && responseLine == "250")
    {
        socket->startClientEncryption();
        if(!socket->waitForEncrypted(timeout))
        {
            qDebug() << socket->errorString();
            state = Close;
        }


        //Send EHLO once again but now encrypted

        *t << "EHLO localhost" << "\r\n";
        t->flush();
        state = Auth;
    }
    else if (state == Auth && responseLine == "250")
    {
        // Trying AUTH
        qDebug() << "Auth";
        *t << "AUTH LOGIN" << "\r\n";
        t->flush();
        state = User;
    }
    else if (state == User && responseLine == "334")
    {
        //Trying User
        qDebug() << "Username";
        //GMAIL is using XOAUTH2 protocol, which basically means that password and username has to be sent in base64 coding
        //https://developers.google.com/gmail/xoauth2_protocol
        *t << QByteArray().append(user).toBase64()  << "\r\n";
        t->flush();

        state = Pass;
    }
    else if (state == Pass && responseLine == "334")
    {
        //Trying pass
        qDebug() << "Pass";
        *t << QByteArray().append(pass).toBase64() << "\r\n";
        t->flush();

        state = Mail;
    }
    else if ( state == Mail && responseLine == "235" )
    {
        // HELO response was okay (well, it has to be)

        //Apperantly for Google it is mandatory to have MAIL FROM and RCPT email formated the following way -> <email@gmail.com>
        qDebug() << "MAIL FROM:<" << from << ">";
        *t << "MAIL FROM:<" << from << ">\r\n";
        t->flush();
        state = Rcpt;
    }
    else if ( state == Rcpt && responseLine == "250" )
    {
        //Apperantly for Google it is mandatory to have MAIL FROM and RCPT email formated the following way -> <email@gmail.com>
        *t << "RCPT TO:<" << rcpt << ">\r\n"; //r
        t->flush();
        state = Data;
    }
    else if ( state == Data && responseLine == "250" )
    {

        *t << "DATA\r\n";
        t->flush();
        state = Body;
    }
    else if ( state == Body && responseLine == "354" )
    {

        *t << message << "\r\n.\r\n";
        t->flush();
        state = Quit;
    }
    else if ( state == Quit && responseLine == "250" )
    {

        *t << "QUIT\r\n";
        t->flush();
        // here, we just close.
        state = Close;
        emit status( tr( "Message sent" ) );
    }
    else if ( state == Close )
    {
        deleteLater();
        return;
    }
    else
    {
        // something broke.
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Unexpected reply from SMTP server:\n\n" ) + response );
        state = Close;
        emit status( tr( "Failed to send message" ) );
    }
    response = "";
}*/

