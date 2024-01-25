#pragma once
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class Homologation : public QWidget {
    Q_OBJECT
public:
    Homologation(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->layout = new QVBoxLayout(this);

        this->text = new QLabel("Mode Homologation", this);
        text->setStyleSheet("font-size: 20px; font-weight: bold; margin-top: 20px; color: black;");
        this->text->setAlignment(Qt::AlignCenter);
        layout->addWidget(text);

        this->deplier = new QPushButton("Déplier", this);
        deplier->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px; color: black;");
        deplier->setBaseSize(378, 46);
        layout->addWidget(deplier);

        this->replier = new QPushButton("Replier", this);
        replier->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px; color: black;");
        replier->setBaseSize(378, 46);
        layout->addWidget(replier);

        connect(this->deplier, &QPushButton::pressed, this, [=]()
        {
            qInfo() << "deplier le robot !";
        });

        connect(this->replier, &QPushButton::pressed, this, [=]()
        {
            qInfo() << "replier le robot !";
        });

    }

private:
    QLayout* layout;
    QLabel* text;
    QPushButton* deplier;
    QPushButton* replier;

};
