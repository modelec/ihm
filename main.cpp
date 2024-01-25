#include <QApplication>
#include <QPushButton>


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(480, 320);
    button.show();
    return QApplication::exec();
}
