#include "HomePage.h"

HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    this->mainLayout = new QVBoxLayout(this);

    this->homologation = new QPushButton("Mode Homologation", this);
    this->homologation->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; margin-top: 10px; color: black; font-size: 33px;");
    this->homologation->setBaseSize(378, 66);
    this->homologation->setCursor(Qt::PointingHandCursor);

    this->jeu = new QPushButton("Mode Jeu", this);
    this->jeu->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 66px; width: 378px; color: white; margin-top: 10px; font-size: 33px;");
    this->jeu->setBaseSize(378, 66);
    this->jeu->setCursor(Qt::PointingHandCursor);

    this->test = new QPushButton("Mode Test", this);
    this->test->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; color: black; margin-top: 10px; font-size: 33px;");
    this->test->setBaseSize(378, 66);
    this->test->setCursor(Qt::PointingHandCursor);

    this->mainLayout->addWidget(this->homologation);
    this->mainLayout->addWidget(this->jeu);
    this->mainLayout->addWidget(this->test);

    connect(this->homologation, &QPushButton::pressed, this, [=]() {
        emit homologationClicked();
    });

    connect(this->jeu, &QPushButton::pressed, this, [=]() {
        emit jeuClicked();
    });

    connect(this->test, &QPushButton::pressed, this, [=]() {
        emit testClicked();
    });
}
