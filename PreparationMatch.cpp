#include "PreparationMatch.h"

PreparationMatch::PreparationMatch(QWidget* parent) : QWidget(parent)
{
    this->mainLayout = new QVBoxLayout(this);
    this->gridLayout = new QHBoxLayout();

    this->startButton = new QPushButton("Play", this);
    this->startButton->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");

    this->leftLayout = new QVBoxLayout();
    this->lidar = new Lidar(this);
    this->leftLayout->addWidget(lidar);
    connect(this->lidar, &Lidar::askTCPServer, this, &PreparationMatch::askTCPServer);

    this->tiretteState = new TiretteState(this);
    this->leftLayout->addWidget(tiretteState);
    connect(this->tiretteState, &TiretteState::askTCPServer, this, &PreparationMatch::askTCPServer);

    this->rightLayout = new QVBoxLayout();
    this->ledVerte = new OneItemPreparation("Led verte", "Check", this);
    connect(this->ledVerte, &OneItemPreparation::buttonClicked, this, [=]() {
        this->ledVerte->toggleChecked();
    });

    this->arduino = new OneItemPreparation("Arduino", "Ping", this);
    connect(this->arduino, &OneItemPreparation::buttonClicked, this, [=]() {
        emit askTCPServer("start;arduino;ping;0");
    });

    this->aruco = new OneItemPreparation("Aruco", "Ping", this);
    connect(this->aruco, &OneItemPreparation::buttonClicked, this, [=]() {
        emit askTCPServer("ihm;aruco;ping;1");
    });

    this->lidarPing = new OneItemPreparation("Lidar", "Ping", this);
    connect(this->lidarPing, &OneItemPreparation::buttonClicked, this, [=]() {
        emit askTCPServer("ihm;lidar;ping;1");
    });

    this->tirette = new OneItemPreparation("Tirette", "Ping", this);
    connect(this->tirette, &OneItemPreparation::buttonClicked, this, [=]() {
        emit askTCPServer("ihm;tirette;ping;1");
    });

    this->rightLayout->addWidget(ledVerte);
    this->rightLayout->addWidget(arduino);
    this->rightLayout->addWidget(aruco);
    this->rightLayout->addWidget(lidarPing);
    this->rightLayout->addWidget(tirette);

    this->gridLayout->addLayout(leftLayout);
    this->gridLayout->addLayout(rightLayout);

    this->mainLayout->addLayout(gridLayout);
    this->mainLayout->addWidget(startButton);

    connect(this->startButton, &QPushButton::pressed, [&]()
    {
        if (ledVerte->isChecked() && arduino->isChecked() && aruco->isChecked() && lidarPing->isChecked() && tirette->isChecked())
        {
            emit startGame();
        }
    });
}

void PreparationMatch::responseFromPing(const QString& message)
{
    auto list = message.split(";");

    if (list[0] == "tirette") {
        this->tirette->setChecked(true);
    } else if (list[0] == "lidar") {
        this->lidarPing->setChecked(true);
    } else if (list[0] == "aruco") {
        this->aruco->setChecked(true);
    }
    else if (list[0] == "arduino") {
        this->arduino->setChecked(true);
    }
}

void PreparationMatch::responseTiretteState(const QString& message)
{
    std::string state = message.split(";")[3].toStdString();
    this->tiretteState->setState(state);
}

void PreparationMatch::responseLidar(const QString& message)
{
    this->lidar->TCPMessage(message);
}

void PreparationMatch::clearCheckboxes()
{
    this->ledVerte->setChecked(false);
    this->arduino->setChecked(false);
    this->aruco->setChecked(false);
    this->lidarPing->setChecked(false);
    this->tirette->setChecked(false);
}