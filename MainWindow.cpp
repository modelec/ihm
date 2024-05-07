#include "MainWindow.h"

MainWindow::MainWindow(const char *address, int port, QWidget *parent) : QMainWindow(parent) {
    this->settings = new QSettings("settings.ini", QSettings::IniFormat);

    this->tcpClient = new MyTCPClient(address, port, this);
    connect(this->tcpClient, &MyTCPClient::messageReceived, this, &MainWindow::handleMessage);

    this->centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    this->mainLayout = new QVBoxLayout(centralWidget);
    this->homeBtn = new QPushButton("", this);
    this->homeBtn->setIcon(QPixmap(":/img/logo_without_background.png", "PNG"));
    this->homeBtn->setStyleSheet("background-color: transparent; border: none;");
    this->homeBtn->setIconSize(QSize(249, 51));
    this->homeBtn->setFixedSize(QSize(400, 51));
    this->homeBtn->setCursor(Qt::PointingHandCursor);

    connect(this->homeBtn, &QPushButton::pressed, this, &MainWindow::onHomePressed);

    this->topLayout = new QHBoxLayout;

    this->quit = new QPushButton("", this);
    this->quit->setIcon(QPixmap(":/img/close.png", "PNG"));
    this->quit->setIconSize(QSize(51, 51));
    this->quit->setStyleSheet("background-color: transparent; border: none;");
    this->quit->setCursor(Qt::PointingHandCursor);

    connect(this->quit, &QPushButton::pressed, this, [=]() {
        this->close();
    });

    this->topLayout->addWidget(this->homeBtn);
    this->topLayout->addWidget(this->quit, 1, Qt::AlignTop | Qt::AlignRight);

    this->mainLayout->addLayout(this->topLayout);

    this->setFixedSize(QSize(800, 480));

    this->home = new HomePage(centralWidget);

    connect(this->home, &HomePage::homologationClicked, this, &MainWindow::onHomologationPressed);

    connect(this->home, &HomePage::jeuClicked, this, &MainWindow::onTeamChooserPressed);

    connect(this->home, &HomePage::testClicked, this, &MainWindow::onTestModePressed);

    this->homologation = new Homologation(centralWidget);
    connect(this->homologation, &Homologation::deplierClicked, this, [&]() {
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;0");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;1");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;2");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;lever bras;1");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;ouvrir pince;0");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;ouvrir pince;2");
    });

    connect(this->homologation, &Homologation::replierClicked, [&]() {
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;0");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;1");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;fermer pince;2");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->tcpClient->sendMessage("ihm;servo_moteur;baisser bras;1");
    });

    connect(this->homologation, &Homologation::panneauGaucheClicked, [&]() {
        this->tcpClient->sendMessage("ihm;servo_moteur;check panneau;6");
    });

    connect(this->homologation, &Homologation::panneauDroitClicked, [&]() {
        this->tcpClient->sendMessage("ihm;servo_moteur;check panneau;7");
    });

    this->teamChooser = new TeamChooser(centralWidget);
    connect(this->teamChooser, &TeamChooser::spawnPointChoose, this, &MainWindow::onSpawnPointChoose);

    this->preparationMatch = new PreparationMatch(centralWidget);
    connect(this->preparationMatch, &PreparationMatch::startGame, [&]()
    {
        this->waitingForTiretteValue = true;
        this->waintingForTirette->startWaiting();
        emit this->onWaitingForTirette();
    });
    connect(this->preparationMatch, &PreparationMatch::askTCPServer, [&](const std::string& message) {
        this->tcpClient->sendMessage(message);
    });

    this->waintingForTirette = new WaintingForTirette(centralWidget);
    connect(this->waintingForTirette, &WaintingForTirette::startGame, this, &MainWindow::onStartGame);
    connect(this->waintingForTirette, &WaintingForTirette::disarmePressed, [&]()
    {
        this->waitingForTiretteValue = false;
        this->setWidgetNb(0);
    });

    this->testMode = new TestMode(centralWidget);
    connect(this->testMode, &TestMode::goPressed, [&](int x, int y, int theta) {
        this->tcpClient->sendMessage("ihm;arduino;go;" + std::to_string(x) + "," + std::to_string(y));
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // this->tcpClient->sendMessage("ihm;arduino;angle;" + std::to_string(theta));
    });

    this->inGame = new InGame(centralWidget);
    connect(this->inGame, &InGame::askTCPServer, [&](const std::string& message) {
        this->tcpClient->sendMessage(message);
    });

    this->stackedWidget = new QStackedWidget(centralWidget);
    this->stackedWidget->addWidget(this->home);
    this->stackedWidget->addWidget(this->homologation);
    this->stackedWidget->addWidget(this->teamChooser);
    this->stackedWidget->addWidget(this->preparationMatch);
    this->stackedWidget->addWidget(this->testMode);
    this->stackedWidget->addWidget(this->waintingForTirette);
    this->stackedWidget->addWidget(this->inGame);

    this->mainLayout->addWidget(this->stackedWidget);

    this->setWidgetNb(0);

    this->tcpClient->sendMessage("ihm;strat;ready;1");
}

void MainWindow::setWidgetNb(const int index) {
    if (index == 2)
    {
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/img/table.jpg", "JPG").scaled(this->size(), Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
        this->homeBtn->hide();
        this->quit->hide();
    } else
    {
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(Qt::white));
        this->setPalette(palette);
        this->homeBtn->show();
        this->quit->show();
    }
    this->stackedWidget->setCurrentIndex(index);
}

void MainWindow::setDisplayMode(DisplayMode mode) {
    this->displayMode = mode;
}

void MainWindow::turnOnTheWindow() {
    if (this->displayMode == DisplayMode::FULLSCREEN)
    {
        this->showFullScreen();
    } else
    {
        this->show();
    }
}


void MainWindow::onHomePressed()
{
    this->waitingForTiretteValue = false;
    this->setWidgetNb(0);
}

void MainWindow::onHomologationPressed()
{
    this->setWidgetNb(1);
}

void MainWindow::onTeamChooserPressed()
{
    this->setWidgetNb(2);
}

void MainWindow::onTestModePressed()
{
    this->setWidgetNb(4);
}

void MainWindow::onSpawnPointChoose(int nb)
{
    this->settings->setValue("spawnPoint", nb);
    this->tcpClient->sendMessage("ihm;strat;spawn;" + std::to_string(nb));
    this->preparationMatch->clearCheckboxes();
    this->setWidgetNb(3);
}

void MainWindow::onWaitingForTirette()
{
    this->setWidgetNb(5);
}

void MainWindow::onStartGame()
{
    this->setWidgetNb(6);
    this->tcpClient->sendMessage("ihm;strat;start;1");
}


void MainWindow::handleMessage(const std::string& message)
{
    std::vector<std::string> list = TCPSocket::split(message, ";");

    if (list[2] == "pong")
    {
        preparationMatch->responseFromPing(QString::fromStdString(message));
    }
    else if (list[0] == "tirette" && list[2] == "set state")
    {
        if (waitingForTiretteValue)
        {
            waintingForTirette->responseFromTirette(message);
        } else
        {
            preparationMatch->responseTiretteState(QString::fromStdString(message));
        }
    }
    else if (list[0] == "lidar")
    {
        preparationMatch->responseLidar(QString::fromStdString(message));
    }
    else if (message == "strat;all;ready;1")
    {
        this->turnOnTheWindow();
    }
    else if (list[2] == "set pos")
    {
        std::vector<std::string> msg = TCPSocket::split(list[3], ",");
        this->inGame->updatePos(std::to_string(std::stoi(msg[0])), std::to_string(std::stoi(msg[1])));
        this->inGame->updateAngle(std::to_string(static_cast<int>(std::stoi(msg[2]) * 0.57325)));
    }
    else if (list[2] == "set speed")
    {
        this->inGame->updateSpeed(list[3]);
    }
    else if (list[2] == "end") {
        this->inGame->stopTimer();
    }
    else if (list[2] == "set points") {
        this->inGame->setScore(std::stoi(list[3]));
    }
    else if (list[2] == "add point") {
        this->inGame->addScore(std::stoi(list[3]));
    }
}
