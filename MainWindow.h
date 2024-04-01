#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QPixmap>
#include <QSettings>

#include "HomePage.h"
#include "Homologation.h"
#include "InGame.h"
#include "PreparationMatch.h"
#include "TeamChooser.h"
#include "TestMode.h"
#include "WaintingForTirette.h"
#include "tcp/MyTCPClient.h"

enum class DisplayMode
{
    FULLSCREEN,
    WINDOWED
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(const char* address = "127.0.0.1", int port = 8080, QWidget* parent = nullptr);

    void setWidgetNb(int index);

    void setDisplayMode(DisplayMode mode);

    void turnOnTheWindow();

protected slots:
    void onHomePressed();

    void onHomologationPressed();

    void onTeamChooserPressed();

    void onTestModePressed();

    void onSpawnPointChoose(int nb);

    void onWaitingForTirette();

    void onStartGame();

    void handleMessage(const std::string& message);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QPushButton* homeBtn;
    QWidget* centralWidget;
    QStackedWidget* stackedWidget;
    QPushButton* quit;

    HomePage* home;
    Homologation* homologation;
    TeamChooser* teamChooser;
    PreparationMatch* preparationMatch;
    TestMode* testMode;
    WaintingForTirette* waintingForTirette;
    InGame* inGame;

    bool waitingForTiretteValue = false;
    DisplayMode displayMode = DisplayMode::WINDOWED;

    MyTCPClient* tcpClient;
    QSettings* settings;
};
