#pragma once

#include <QObject>
#include <TCPSocket/TCPClient.hpp>
#include <TCPSocket/TCPUtils.hpp>

class MyTCPClient : public QObject, public TCPClient {
    Q_OBJECT
public:
    explicit MyTCPClient(const char* address = "127.0.0.1", int port = 8080, QObject* parent = nullptr) : TCPClient(address, port), QObject(parent) {
        this->start();
    }

    void handleMessage(const std::string &message) override {
        emit messageReceived(message);
    };

signals:
    void messageReceived(const std::string &message);
};
