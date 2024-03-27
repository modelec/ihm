#include <iostream>
#include <QApplication>
#include <QObject>
#include <QThread>

#include "MainWindow.h"
#include "tcp/TCPServer.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    auto* main = new MainWindow;

    MainWindow::connect(main, &MainWindow::replierRobot, [=]()
    {
        qInfo() << "replier";
    });

    MainWindow::connect(main, &MainWindow::deplierRobot, [=]()
    {
        qInfo() << "deplier";
    });

    MainWindow::connect(main, &MainWindow::moveRobot, [=](int x, int y, int theta)
    {
            qInfo() << "move" << x << y << theta;
    });

    main->show();
    // main->showFullScreen();

    int port = 8080;
    if (argc == 2)
    {
        port = std::stoi(argv[1]);
    }

    auto* server = new TCPServer(port);
    server->start();

    QObject::connect(server, &TCPServer::messageReceived, main, &MainWindow::onTCPMesssageReceived);
    QObject::connect(main, &MainWindow::broadcastTCPMessage, [server](const std::string& message)
    {
        server->broadcastMessage(message.c_str());
    });

    // Create a new thread for the server
    QThread serverThread;
    server->moveToThread(&serverThread);
    serverThread.start();

    // Create a lambda function to run the while loop
    auto runServerLoop = [&]() {
        while (true) {
            std::string message;
            std::cout << "Enter message ('quit' to exit): ";
            std::getline(std::cin, message);

            if (message == "quit") {
                // Stop the server and exit the loop
                server->stop();
                break;
            }

            // Broadcast the message from the server
            server->broadcastMessage(message.c_str());
        }
    };

    // Move the lambda function to the new thread
    QObject::connect(&serverThread, &QThread::started, runServerLoop);

    // Connect aboutToQuit signal to stop the thread and wait for it to finish
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [&]() {
        server->stop(); // Stop the server
        serverThread.quit(); // Quit the thread event loop
        serverThread.wait(); // Wait for the thread to finish
    });

    return QApplication::exec();
}
