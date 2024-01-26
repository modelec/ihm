#pragma once

#include <QLabel>
#include <QWidget>
#include "TestModeBtn.h"

class TestMode : public QWidget {
    Q_OBJECT
public:
    TestMode(QWidget* parent = nullptr) : QWidget(parent) {
        this->mainLayout = new QVBoxLayout(this);
        this->mainLayout->setAlignment(Qt::AlignCenter);

        this->text = new QLabel("Mode Test Position", this);
        text->setStyleSheet("font-size: 20px; font-weight: bold; color: black;");
        this->text->setAlignment(Qt::AlignCenter);
        this->mainLayout->addWidget(text);

        this->textcm = new QLabel("(en cm)", this);
        textcm->setStyleSheet("font-size: 14px; font-weight: bold; color: black;");
        this->textcm->setAlignment(Qt::AlignCenter);
        this->mainLayout->addWidget(textcm);

        this->X = new TestModeBtn("X", 0, 150, this);
        this->mainLayout->addWidget(X);
        this->Y = new TestModeBtn("Y", 0, 300, this);
        this->mainLayout->addWidget(Y);
        this->Theta = new TestModeBtn("θ", -180, 180, this);
        this->mainLayout->addWidget(Theta);

        this->go = new QPushButton("Go", this);
        go->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 36px; width: 378px; color: black;");
        go->setBaseSize(378, 46);
        this->mainLayout->addWidget(go);

        connect(this->go, &QPushButton::pressed, this, &TestMode::onGoPressed);
    }

private slots:
    void onGoPressed()
    {
        qInfo() << "go !";

        // Récupérer les valeurs des TestModeBtn
        int xValue = X->getValue();
        int yValue = Y->getValue();
        int thetaValue = Theta->getValue();

        // Utiliser les valeurs comme nécessaire
        qInfo() << "Valeur de X : " << xValue;
        qInfo() << "Valeur de Y : " << yValue;
        qInfo() << "Valeur de Theta : " << thetaValue;
    }


private:
    QVBoxLayout* mainLayout;
    QLabel* text;
    TestModeBtn* X;
    TestModeBtn* Y;
    TestModeBtn* Theta;
    QPushButton* go;
    QLabel* textcm;
};