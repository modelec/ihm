#include <iostream>
#include <QApplication>
#include <QObject>
#include <QThread>
#include <csignal>
#include <Modelec/CLParser.h>

#include "MainWindow.h"

void signalHandler(int sigmum) {
    std::cout << "Inteerupt signal (" << sigmum << ") received.\n";

    QApplication::quit();
}

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    CLParser clParser(argc, argv);

    std::string dMode = clParser.getOption("window-mode", "windowed");

    DisplayMode mode = DisplayMode::WINDOWED;

    if (dMode == "windowed") {
        mode = DisplayMode::WINDOWED;
    }
    else if (dMode == "fullscreen") {
        mode = DisplayMode::FULLSCREEN;
    }

    int port = clParser.getOption<int>("port", 8080);

    auto host = clParser.getOption("host", "127.0.0.1");

    auto* main = new MainWindow(host, port);

    main->setDisplayMode(mode);

    return QApplication::exec();
}
