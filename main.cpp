#include <QApplication>
#include <QObject>

#include "MainWindow.h"

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

    main->show();

    return QApplication::exec();
}
