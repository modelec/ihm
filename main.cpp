#include <iostream>
#include <QApplication>
#include <QObject>
#include <QThread>
#include <csignal>

#include "MainWindow.h"

void signalHandler(int sigmum) {
    std::cout << "Inteerupt signal (" << sigmum << ") received.\n";

    QApplication::quit();
}

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    DisplayMode mode;

    if (argc >= 2)
    {
        if (argv[1] == std::string("fullscreen"))
        {
            mode = DisplayMode::FULLSCREEN;
        } else
        {
            mode = DisplayMode::WINDOWED;
        }
    } else
    {
        mode = DisplayMode::WINDOWED;
    }

    int port = 8080;
    if (argc >= 3)
    {
        port = std::stoi(argv[2]);
    }

    auto* main = new MainWindow("127.0.0.1", port);

    main->setDisplayMode(mode);

    return QApplication::exec();
}
