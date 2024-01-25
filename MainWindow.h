#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        this->centralWidget = new QWidget(this);
        this->setCentralWidget(centralWidget);

        this->mainLayout = new QVBoxLayout(centralWidget);
        this->homeButton = new QPushButton("", this);
        QPixmap pic(":/img/logo_without_background.png", "PNG");
        this->homeButton->setIcon(pic);
        this->homeButton->setIconSize(QSize(249, 51));

        this->mainLayout->addWidget(this->homeButton);

        this->setFixedSize(QSize(480, 320));

        this->setLayout(mainLayout);
    }

private:
    QVBoxLayout* mainLayout;
    QPushButton* homeButton;
    QWidget* centralWidget;
};
