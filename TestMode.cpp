#include "TestMode.h"

TestMode::TestMode(QWidget *parent) : QWidget(parent) {
    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->setAlignment(Qt::AlignCenter);

    this->text = new QLabel("Mode Test Position", this);
    text->setStyleSheet("font-size: 20px; font-weight: bold; color: black;");
    this->text->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(text);

    this->textcm = new QLabel("(en mm)", this);
    textcm->setStyleSheet("font-size: 14px; font-weight: bold; color: black;");
    this->textcm->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(textcm);
    this->textrad = new QLabel("(en rad)", this);
    textrad->setStyleSheet("font-size: 14px; font-weight: bold; color: black;");
    this->textrad->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(textrad);

    this->X = new TestModeBtn("X", 0, 1500, this);
    this->mainLayout->addWidget(X);
    this->Y = new TestModeBtn("Y", 0, 3000, this);
    this->mainLayout->addWidget(Y);
    this->Theta = new TestModeBtn("θ", -180, 180, this);
    this->mainLayout->addWidget(Theta);

    this->go = new QPushButton("Go", this);
    go->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 36px; width: 378px; color: black;");
    go->setBaseSize(378, 46);
    this->mainLayout->addWidget(go);

    connect(this->go, &QPushButton::pressed, this, &TestMode::onGoPressed);
}

void TestMode::onGoPressed() {
    emit goPressed(this->X->getValue(), this->Y->getValue(), this->Theta->getValue());
}

