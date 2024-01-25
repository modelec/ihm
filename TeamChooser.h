#pragma once
#include <qboxlayout.h>
#include <QPushButton>
#include <QWidget>

class TeamChooser : public QWidget {
    Q_OBJECT
public:
    TeamChooser(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->mainLayout = new QHBoxLayout(this);
        this->blueTeam = new QPushButton("Equipe Bleue", this);
        this->blueTeam->setStyleSheet("background-color: #4D83A1; border-radius: 40px; margin-top: 20px; color: black;");
        this->yellowTeam = new QPushButton("Equipe Jaune", this);
        this->yellowTeam->setStyleSheet("background-color: #FFBF00; border-radius: 40px; margin-top: 20px; color: black;");

        this->mainLayout->addWidget(this->blueTeam);
        this->mainLayout->addWidget(this->yellowTeam);

        connect(this->blueTeam, &QPushButton::pressed, this, &TeamChooser::onBlueTeamClicked);
        connect(this->yellowTeam, &QPushButton::pressed, this, &TeamChooser::onYellowTeamClicked);
    }

signals:
    void blueTeamClicked();
    void yellowTeamClicked();

private slots:
    void onBlueTeamClicked()
    {
        emit blueTeamClicked();
    }

    void onYellowTeamClicked()
    {
        emit yellowTeamClicked();
    }

private:
    QHBoxLayout* mainLayout;
    QPushButton* blueTeam;
    QPushButton* yellowTeam;
};
