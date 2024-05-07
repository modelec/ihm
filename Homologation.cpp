#include "Homologation.h"

Homologation::Homologation(QWidget *parent) : QWidget(parent) {
    this->layout = new QVBoxLayout(this);

    this->text = new QLabel("Mode Homologation", this);
    text->setStyleSheet("font-size: 66px; font-weight: bold; margin-top: 20px; color: black;");
    this->text->setAlignment(Qt::AlignCenter);
    layout->addWidget(text);

    this->deplier = new QPushButton("Déplier", this);
    deplier->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
    deplier->setBaseSize(378, 66);
    layout->addWidget(deplier);

    this->replier = new QPushButton("Replier", this);
    replier->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
    replier->setBaseSize(378, 66);
    layout->addWidget(replier);

    this->panneauGauche = new QPushButton("Panneau gauche", this);
    panneauGauche->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
    panneauGauche->setBaseSize(378, 66);
    layout->addWidget(panneauGauche);

    this->panneauDroit = new QPushButton("Panneau droit", this);
    panneauDroit->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
    panneauDroit->setBaseSize(378, 66);
    layout->addWidget(panneauDroit);

    connect(this->deplier, &QPushButton::pressed, this, &Homologation::onDeplierClicked);

    connect(this->replier, &QPushButton::pressed, this, &Homologation::onReplierClicked);

    connect(this->panneauGauche, &QPushButton::pressed, this, &Homologation::onPanneauGaucheClicked);

    connect(this->panneauDroit, &QPushButton::pressed, this, &Homologation::onPanneauDroitClicked);
}

void Homologation::onDeplierClicked()
{
    emit deplierClicked();
}

void Homologation::onReplierClicked()
{
    emit replierClicked();
}

void Homologation::onPanneauDroitClicked()
{
    emit panneauDroitClicked();
}

void Homologation::onPanneauGaucheClicked()
{
    emit panneauGaucheClicked();
}
