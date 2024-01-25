#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

#include "homeButton.h"
#include "Homologation.h"
#include "InGame.h"
#include "TeamChooser.h"
#include "TestMode.h"

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

        connect(this->homeBtn, &QPushButton::pressed, this, [=]() {
            this->setWidgetNb(0);
        });

        this->mainLayout->addWidget(this->homeBtn);

        this->setFixedSize(QSize(480, 320));

        this->setLayout(mainLayout);

        this->home = new homeButton(this);

        connect(this->home, &homeButton::homologationClicked, this, [=]() {
            this->setWidgetNb(1);
        });

        connect(this->home, &homeButton::jeuClicked, this, [=]() {
            this->setWidgetNb(2);
        });

        connect(this->home, &homeButton::testClicked, this, [=]() {
            this->setWidgetNb(3);
        });

        this->homologation = new Homologation(this);

        this->teamChooser = new TeamChooser(this);
        connect(this->teamChooser, &TeamChooser::blueTeamClicked, this, [=]() {
            this->setWidgetNb(4);
        });

        connect(this->teamChooser, &TeamChooser::yellowTeamClicked, this, [=]() {
            this->setWidgetNb(4);
        });

        this->testMode = new TestMode(this);

        this->inGame = new InGame(this);

        this->stackedWidget = new QStackedWidget(this);
        this->stackedWidget->addWidget(this->home);
        this->stackedWidget->addWidget(this->homologation);
        this->stackedWidget->addWidget(this->teamChooser);
        this->stackedWidget->addWidget(this->testMode);
        this->stackedWidget->addWidget(this->inGame);

        this->mainLayout->addWidget(this->stackedWidget);

        this->setWidgetNb(0);
    }

    void setWidgetNb(const int index)
    {
        if (index == 2)
        {
            QPixmap pic(":/img/table.jpg", "JPG");
            pic = pic.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(pic));
            this->setPalette(palette);
        } else
        {
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(Qt::white));
            this->setPalette(palette);
        }
        this->stackedWidget->setCurrentIndex(index);
    }

private:
    QVBoxLayout* mainLayout;
    QPushButton* homeBtn;
    QWidget* centralWidget;
    QStackedWidget* stackedWidget;

    homeButton* home;
    Homologation* homologation;
    TeamChooser* teamChooser;
    TestMode* testMode;
    InGame* inGame;
};
