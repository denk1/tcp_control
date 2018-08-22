#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "server could not start!";
    }
    else
    {
        qDebug() << "Server started";
    }
}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);
    socket->waitForReadyRead(3000);
    qDebug() << "test";
    qDebug() << socket->bytesAvailable();
    QString recieveBytes = socket->readAll();
    qDebug() << recieveBytes;
    socket->close();
    emit commandRecieve(recieveBytes);
}


