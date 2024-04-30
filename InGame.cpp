#include "InGame.h"

InGame::InGame(QWidget *parent) : QWidget(parent) {
    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->setAlignment(Qt::AlignCenter);
    this->pts = new QLabel("Points : 0", this);
    this->pts->setStyleSheet("font-size: 96px; color: black;");
    this->x = new QLabel("X : 0", this);
    this->x->setStyleSheet("font-size: 32px; color: black;");
    this->y = new QLabel("Y : 0", this);
    this->y->setStyleSheet("font-size: 32px; color: black;");
    this->time = new QLabel("Time : 0m0s", this);
    this->time->setStyleSheet("font-size: 32px; color: black;");
    this->speed = new QLabel("Vitesse : 0", this);
    this->speed->setStyleSheet("font-size: 32px; color: black;");
    this->angle = new QLabel("Angle : 0", this);
    this->angle->setStyleSheet("font-size: 32px; color: black;");

    this->mainLayout->addWidget(pts);

    this->posAndTimeLayout = new QHBoxLayout();

    this->mainLayout->addLayout(this->posAndTimeLayout);

    this->posAndTimeLayout->addWidget(time);

    this->posLayout = new QVBoxLayout();

    this->posLayout->addWidget(x);
    this->posLayout->addWidget(y);
    this->posLayout->addWidget(speed);
    this->posLayout->addWidget(angle);
    this->posLayout->setAlignment(Qt::AlignCenter);

    this->posAndTimeLayout->addLayout(this->posLayout);

    this->setLayout(mainLayout);

    this->timer = new QTimer(this);
    this->timer->setInterval(1000); // 1 second
    connect(this->timer, &QTimer::timeout, this, &InGame::updateTime);
}

void InGame::updateScode(const int score) const
{
    this->pts->setText("Points : " + QString::number(score));
}

void InGame::updatePos(const std::string& x, const std::string &y) const
{
    this->x->setText("X : " + QString::fromStdString(x));
    this->y->setText("Y : " + QString::fromStdString(y));
}

void InGame::updateSpeed(const std::string& speed) const
{
    this->speed->setText("Vitesse : " + QString::fromStdString(speed));
}

void InGame::updateAngle(const std::string& angle) const
{
    this->angle->setText("Angle : " + QString::fromStdString(angle));
}


void InGame::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    this->timer->start();
}

void InGame::updateTime()
{
    this->timeCounter++;
    int min = this->timeCounter / 60;
    int sec = this->timeCounter % 60;
    this->time->setText("Time : " + QString::number(min) + "m" + QString::number(sec) + "s");
    emit askTCPServer("ihm;strat;get pos;1");
    emit askTCPServer("ihm;strat;get speed;1");
    emit askTCPServer("ihm;strat;get angle;1");
}

void InGame::stopTimer() const {
    this->timer->stop();
}
