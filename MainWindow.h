#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "homeButton.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        this->centralWidget = new QWidget(this);
        this->setCentralWidget(centralWidget);

        this->mainLayout = new QVBoxLayout(centralWidget);
        this->homeBtn = new QPushButton("", this);
        QPixmap pic(":/img/logo_without_background.png", "PNG");
        this->homeBtn->setIcon(pic);
        this->homeBtn->setIconSize(QSize(249, 51));

        this->mainLayout->addWidget(this->homeBtn);

        this->setFixedSize(QSize(480, 320));

        this->setLayout(mainLayout);

        this->home = new homeButton(this);
        this->mainLayout->addWidget(this->home);
    }

private:
    QVBoxLayout* mainLayout;
    QPushButton* homeBtn;
    QWidget* centralWidget;
    homeButton* home;
};
