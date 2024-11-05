#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include "STMP/src/mimemessage.h"
#include "STMP/src/smtpexports.h"
#include "STMP/src/SmtpMime"

class SMTP_EXPORT SMTPClient : public QObject
{
    Q_OBJECT
public:

    /* [0] Enumerations */

    enum AuthMethod
    {
        AuthPlain,
        AuthLogin
    };

    enum SmtpError
    {
        ConnectionTimeoutError,
        ResponseTimeoutError,
        SendDataTimeoutError,
        AuthenticationFailedError,
        ServerError,    // 4xx smtp error
        ClientError     // 5xx smtp error
    };

    enum ConnectionType
    {
        TcpConnection,
        SslConnection,
        TlsConnection       // STARTTLS
    };

    /* [0] --- */


    /* [1] Constructors and Destructors */

    SMTPClient(const QString & host = "localhost", int port = 25, ConnectionType ct = TcpConnection);

    ~SMTPClient();

    /* [1] --- */


    /* [2] Getters and Setters */

    const QString& getHost() const;
    void setHost(const QString &host);

    int getPort() const;
    void setPort(int port);

    const QString& getName() const;
    void setName(const QString &name);

    ConnectionType getConnectionType() const;
    void setConnectionType(ConnectionType ct);

    const QString & getUser() const;
    void setUser(const QString &user);

    const QString & getPassword() const;
    void setPassword(const QString &password);

    SMTPClient::AuthMethod getAuthMethod() const;
    void setAuthMethod(AuthMethod method);

    const QString & getResponseText() const;
    int getResponseCode() const;

    int getConnectionTimeout() const;
    void setConnectionTimeout(int msec);

    int getResponseTimeout() const;
    void setResponseTimeout(int msec);

    int getSendMessageTimeout() const;
    void setSendMessageTimeout(int msec);

    QTcpSocket* getSocket();


    /* [2] --- */


    /* [3] Public methods */

    bool connectToHost();

    bool login();
    bool login(const QString &user, const QString &password, AuthMethod method = AuthLogin);

    bool sendMail(MimeMessage& email);

    void quit();


    /* [3] --- */

protected:

    /* [4] Protected members */

    QTcpSocket *socket;

    QString host;
    int port;
    ConnectionType connectionType;
    QString name;

    QString user;
    QString password;
    AuthMethod authMethod;

    int connectionTimeout;
    int responseTimeout;
    int sendMessageTimeout;


    QString responseText;
    int responseCode;


    class ResponseTimeoutException {};
    class SendMessageTimeoutException {};

    /* [4] --- */


    /* [5] Protected methods */

    void waitForResponse();

    void sendMessage(const QString &text);

    /* [5] --- */

protected slots:

    /* [6] Protected slots */

    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketError(QAbstractSocket::SocketError error);
    void socketReadyRead();

    /* [6] --- */


signals:

    /* [7] Signals */

    void smtpError(SMTPClient::SmtpError e);

    /* [7] --- */

};
/*class SMTPClient : public QObject  // Added to inherit from QObject
{
    Q_OBJECT  // Added for signals and slots support

public:
    SMTPClient(const QString &user, const QString &pass,
               int timeout = 30000, const QString &host = "smtp.gmail.com", int port = 465);
    ~SMTPClient();
    void sendMail(const QString &from, const QString &to,
                  const QString &subject, const QString &body);

signals:
    void status(const QString &);

private slots:
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorReceived(QAbstractSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();

private:
    int timeout;
    QString message;
    QTextStream *t;
    QSslSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString host;
    int port;
    enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
    int state;
};*/

#endif // SMTPCLIENT_H
