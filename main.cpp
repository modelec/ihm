#include <QApplication>

#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow main;

    main.show();

/*    QMainWindow window;
    window.setFixedSize(480, 320);

    auto *centralWidget = new QWidget(&window);
    window.setCentralWidget(centralWidget);

    auto *layout = new QVBoxLayout(centralWidget);

    QPixmap pic(":/img/logo_without_background.png", "PNG");
    QPushButton button("", nullptr);
    button.setIcon(pic);
    button.setIconSize(QSize(249, 51));
    layout->addWidget(&button);

    QPushButton homologation("Mode Homologation", nullptr);
    homologation.setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    homologation.setBaseSize(378, 46);
    layout->addWidget(&homologation);

    QPushButton jeu("Mode Jeu", nullptr);
    jeu.setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    jeu.setBaseSize(378, 46);
    layout->addWidget(&jeu);

    QPushButton test("Mode Test", nullptr);
    test.setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    test.setBaseSize(378, 46);
    layout->addWidget(&test);

    window.show();*/
    return QApplication::exec();
}
