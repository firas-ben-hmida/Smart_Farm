#include <QTcpServer>
#include <QTcpSocket>

#include "serverclass.h"

ServerClass::ServerClass(QObject *parent)
	: QObject(parent)
{
	server = new QTcpServer(this);
	socket = new QTcpSocket(this);
}

ServerClass::~ServerClass()
{
	delete socket;
}

bool ServerClass::startServer(QString ipAddress, quint16 port)
{
	QHostAddress ip(ipAddress);
	if (!server->listen(ip, port)) {
		return false;
	}
	connect(server, SIGNAL(newConnection()), this, SLOT(connection()));
	return true;
}

void ServerClass::connection()
{
	socket = server->nextPendingConnection();
	connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void ServerClass::receiveMessage()
{
	QByteArray data = socket->readAll();
	QString message = QString::fromUtf8(data);
	emit messageReceived(message, 0);
}
void ServerClass::sendMessage(QString message)
{
	QByteArray data = message.toUtf8();
	socket->write(data);
}
