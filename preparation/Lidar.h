#pragma once
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class Lidar : public QWidget {
    Q_OBJECT

public:
    Lidar(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->mainLayout = new QVBoxLayout(this);
        this->mainLayout->setAlignment(Qt::AlignTop);
        this->title = new QLabel("Lidar", this);
        this->title->setStyleSheet("font-size: 24px; color: black;");

        this->startLidar = new QPushButton("Start", this);
        this->startLidar->setStyleSheet("height: 46px; color: black; font-size: 24px;");

        this->position = new QHBoxLayout();
        this->postionTitle = new QLabel("x: 0, y : 0, r: 0", this);
        this->postionTitle->setStyleSheet("font-size: 24px; color: black;");
        this->positionButton = new QPushButton("Get pos", this);
        this->positionButton->setStyleSheet("height: 46px; color: black; font-size: 24px;");

        this->position->addWidget(postionTitle);
        this->position->addWidget(positionButton);

        this->health = new QHBoxLayout();
        this->healthTitle = new QLabel("Health : OK", this);
        this->healthTitle->setStyleSheet("font-size: 24px; color: black;");
        this->healthButton = new QPushButton("Get health", this);
        this->healthButton->setStyleSheet("height: 46px; color: black; font-size: 24px;");

        this->health->addWidget(healthTitle);
        this->health->addWidget(healthButton);

        this->mainLayout->addWidget(title, 0, Qt::AlignCenter);
        this->mainLayout->addWidget(startLidar, 0, Qt::AlignCenter);
        this->mainLayout->addLayout(position);
        this->mainLayout->addLayout(health);

        connect(this->startLidar, &QPushButton::clicked, this, &Lidar::onStartButtonClicked);
        connect(this->positionButton, &QPushButton::clicked, this, &Lidar::onPositionButtonClicked);
        connect(this->healthButton, &QPushButton::clicked, this, &Lidar::onHealthButtonClicked);
    }

    void TCPMessage(const QString& message)
    {
        auto list = message.split(";");

        if (list[2] == "set health")
        {
            if (list[3] == "1")
            {
                this->healthTitle->setText("Health : OK");
            } else if (list[3] == "0")
            {
                this->healthTitle->setText("Health : KO");
            }
        } else if (list[2] == "set avoidance")
        {
            auto pos = list[3].split(",");
            this->postionTitle->setText("x: " + pos[0] + ", y: " + pos[1] + ", r: " + pos[2]);
        }
    }

signals:
    void askTCPServer(const std::string& message);

public slots:
    void onStartButtonClicked()
    {
        emit askTCPServer("ihm;lidar;start;0");
    }

    void onHealthButtonClicked()
    {
        emit askTCPServer("ihm;lidar;get health;0");
    }

    void onPositionButtonClicked()
    {
        emit askTCPServer("ihm;lidar;get data;0");
    }

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* position;
    QHBoxLayout* health;

    QPushButton* startLidar;

    QLabel* postionTitle;
    QPushButton* positionButton;

    QLabel* healthTitle;
    QPushButton* healthButton;
};
