#pragma once

#include <QObject>
#include <QTcpSocket>

class MyTCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTCPSocket(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void sendMessage(const QByteArray &message);

signals:
    void connected();
    void disconnected();
    void errorOccurred(const QString &errorString);
    void messageReceived(const QByteArray &message);

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
};
