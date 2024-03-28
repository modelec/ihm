#include "TCPClient.h"
#include <QHostAddress>

TCPSocket::TCPSocket(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &TCPSocket::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &TCPSocket::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &TCPSocket::onReadyRead);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
            this, &TCPSocket::onErrorOccurred);
}

void TCPSocket::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void TCPSocket::sendMessage(const QByteArray &message)
{
    if (socket->state() == QTcpSocket::ConnectedState) {
        socket->write(message);
    }
}

void TCPSocket::onReadyRead()
{
    QByteArray message = socket->readAll();
    emit messageReceived(message);
}

void TCPSocket::onConnected()
{
    emit connected();
}

void TCPSocket::onDisconnected()
{
    emit disconnected();
}

void TCPSocket::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)
    emit errorOccurred(socket->errorString());
}
