#include "MyTCPClient.h"

MyTCPClient::MyTCPClient(const char *address, int port, QObject *parent) : TCPClient(address, port), QObject(parent) {
    this->start();
}

void MyTCPClient::handleMessage(const std::string &message) {
    emit messageReceived(message);
}
