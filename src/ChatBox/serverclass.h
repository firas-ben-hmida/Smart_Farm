#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerClass  : public QObject
{
	Q_OBJECT

public:
	ServerClass(QObject *parent);
	~ServerClass();
    bool startServer(QString, quint16);
    void sendMessage(QString);

protected slots:
    void connection();
    void receiveMessage();

private:
	QTcpServer *server;
	QTcpSocket* socket;

signals:
    void messageReceived(QString, int);
};
