#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QStackedWidget>

class ModeWidget : public QWidget {
public:
    ModeWidget(QWidget *parent = nullptr) : QWidget(parent) {
        auto *layout = new QVBoxLayout(this);
        QPixmap pic(":/img/logo_without_background.png", "PNG");

        QPushButton button("", nullptr);
        button.setIcon(pic);
        button.setIconSize(QSize(249, 51));
        layout->addWidget(&button);


        auto *text = new QLabel("Mode Homologation", this);
        text->setStyleSheet("font-size: 20px; font-weight: bold; margin-top: 20px;");
        layout->addWidget(text);

        QPushButton deplier("Déplier", nullptr);
        deplier.setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
        deplier.setBaseSize(378, 46);
        layout->addWidget(&deplier);

        QPushButton replier("Replier", nullptr);
        replier.setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
        replier.setBaseSize(378, 46);
        layout->addWidget(&replier);
    }
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QMainWindow window;

    QWidget *centralWidget = new QWidget(&window);
    window.setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPixmap pic(":/img/logo_without_background.png", "PNG");
    QPushButton button("", nullptr);
    button.setIcon(pic);
    button.setIconSize(QSize(249, 51));
    layout->addWidget(&button);

    QStackedWidget stackedWidget;
    layout->addWidget(&stackedWidget);

    QPushButton homologation("Mode Homologation", nullptr);
    homologation.setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    homologation.setBaseSize(378, 46);
    layout->addWidget(&homologation);

    ModeWidget homologationWidget;
    stackedWidget.addWidget(&homologationWidget);

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        stackedWidget.setCurrentWidget(&homologationWidget);
    });

    QPushButton jeu("Mode Jeu", nullptr);
    jeu.setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    jeu.setBaseSize(378, 46);
    layout->addWidget(&jeu);

    QPushButton test("Mode Test", nullptr);
    test.setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
    test.setBaseSize(378, 46);
    layout->addWidget(&test);

    window.show();
    return QApplication::exec();
}
