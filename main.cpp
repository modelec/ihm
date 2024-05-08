#include <iostream>
#include <QApplication>
#include <QObject>
#include <QThread>
#include <atomic>
#include <csignal>

#include "MainWindow.h"

MainWindow* mainWindowPtr = nullptr;

void signalHandler(int signum) {
    if(mainWindowPtr != nullptr){
        mainWindowPtr->setShouldStop(true);
    }
}

int main(int argc, char* argv[]) {

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    QApplication a(argc, argv);

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
    mainWindowPtr = main;

    try{
        main->setDisplayMode(mode);

        while(!main->shouldStop()){
            usleep(100'000);
        }

        delete main;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        delete main;
        return 1;
    }

    main->setDisplayMode(mode);

    return QApplication::exec();
}
