//
// Created by breizhhardware on 1/25/24.
//

#ifndef HOMEBUTTON_H
#define HOMEBUTTON_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


class homeButton : public QWidget {
    Q_OBJECT
    public:
        homeButton(QWidget* parent = nullptr) : QWidget(parent) {
            this->window = new QWidget(this);

            this->mainLayout = new QVBoxLayout(window);

            this->homologation = new QPushButton("Mode Homologation", this);
            this->homologation->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
            this->homologation->setBaseSize(378, 46);

            this->jeu = new QPushButton("Mode Jeu", this);
            this->jeu->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
            this->jeu->setBaseSize(378, 46);

            this->test = new QPushButton("Mode Test", this);
            this->test->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 378px; margin-top: 20px;");
            this->test->setBaseSize(378, 46);

            this->mainLayout->addWidget(this->homologation);
            this->mainLayout->addWidget(this->jeu);
            this->mainLayout->addWidget(this->test);


        }
    private:
        QVBoxLayout* mainLayout;
        QPushButton* homologation;
        QPushButton* jeu;
        QPushButton* test;
        QWidget* window;
};



#endif //HOMEBUTTON_H
