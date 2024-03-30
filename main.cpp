#include <iostream>
#include <QApplication>
#include <QObject>
#include <QThread>

#include "MainWindow.h"

int main(int argc, char* argv[]) {
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

    main->setDisplayMode(mode);

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

    return QApplication::exec();
}
