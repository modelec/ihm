#include "MyTCPClient.h"
#include <QHostAddress>

MyTCPSocket::MyTCPSocket(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &MyTCPSocket::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &MyTCPSocket::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &MyTCPSocket::onReadyRead);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
            this, &MyTCPSocket::onErrorOccurred);
}

void MyTCPSocket::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void MyTCPSocket::sendMessage(const QByteArray &message)
{
    if (socket->state() == QTcpSocket::ConnectedState) {
        socket->write(message);
    }
}

void MyTCPSocket::onReadyRead()
{
    QByteArray message = socket->readAll();
    emit messageReceived(message);
}

void MyTCPSocket::onConnected()
{
    emit connected();
}

void MyTCPSocket::onDisconnected()
{
    emit disconnected();
}

void MyTCPSocket::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)
    emit errorOccurred(socket->errorString());
}
