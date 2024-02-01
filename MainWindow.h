#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QIcon>

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
        this->homeBtn->setIcon(QPixmap(":/img/logo_without_background.png", "PNG"));
        this->homeBtn->setStyleSheet("background-color: transparent; border: none;");
        this->homeBtn->setIconSize(QSize(249, 51));
        this->homeBtn->setFixedSize(QSize(400, 51));

        connect(this->homeBtn, &QPushButton::pressed, this, &MainWindow::onHomePressed);

        this->topLayout = new QHBoxLayout;

        this->quit = new QPushButton("", this);
        this->quit->setIcon(QPixmap(":/img/close.png", "PNG"));
        this->quit->setStyleSheet("background-color: red; border: none;");

        connect(this->quit, &QPushButton::pressed, this, [=]() {
            this->close();
        });

        this->topLayout->addWidget(this->homeBtn);
        this->topLayout->addWidget(this->quit, 1, Qt::AlignTop | Qt::AlignRight);

        this->mainLayout->addLayout(this->topLayout);

        this->setFixedSize(QSize(480, 320));

        this->home = new homeButton(centralWidget);

        connect(this->home, &homeButton::homologationClicked, this, &MainWindow::onHomologationPressed);

        connect(this->home, &homeButton::jeuClicked, this, &MainWindow::onTeamChooserPressed);

        connect(this->home, &homeButton::testClicked, this, &MainWindow::onTestModePressed);

        this->homologation = new Homologation(centralWidget);
        connect(this->homologation, &Homologation::deplierClicked, this, &MainWindow::deplierRobot);
        connect(this->homologation, &Homologation::replierClicked, this, &MainWindow::replierRobot);

        this->teamChooser = new TeamChooser(centralWidget);
        connect(this->teamChooser, &TeamChooser::blueTeamClicked, this, &MainWindow::onInGamePressed);

        connect(this->teamChooser, &TeamChooser::yellowTeamClicked, this, &MainWindow::onInGamePressed);

        this->testMode = new TestMode(centralWidget);
        connect(this->testMode, &TestMode::goPressed, this, &MainWindow::moveRobot);

        this->inGame = new InGame(teamChooser);

        this->stackedWidget = new QStackedWidget(centralWidget);
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
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/img/table.jpg", "JPG").scaled(this->size(), Qt::IgnoreAspectRatio)));
            this->setPalette(palette);
        } else
        {
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(Qt::white));
            this->setPalette(palette);
        }
        this->stackedWidget->setCurrentIndex(index);
    }

protected slots:
    void onHomePressed()
    {
        this->setWidgetNb(0);
    }

    void onHomologationPressed()
    {
        this->setWidgetNb(1);
    }

    void onTeamChooserPressed()
    {
        this->setWidgetNb(2);
    }

    void onTestModePressed()
    {
        this->setWidgetNb(3);
    }

    void onInGamePressed()
    {
        this->setWidgetNb(4);
    }

    void onDeplierRobot()
    {
        emit deplierRobot();
    }

    void onReplierRobot()
    {
        emit replierRobot();
    }

signals:
    void deplierRobot();
    void replierRobot();
    void moveRobot(int x, int y, int theta);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QPushButton* homeBtn;
    QWidget* centralWidget;
    QStackedWidget* stackedWidget;
    QPushButton* quit;

    homeButton* home;
    Homologation* homologation;
    TeamChooser* teamChooser;
    TestMode* testMode;
    InGame* inGame;
};
