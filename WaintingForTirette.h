#pragma once

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <TCPSocket/TCPUtils.hpp>

#include "homeButton.h"


class WaintingForTirette : public QWidget {
    Q_OBJECT
public:

    WaintingForTirette(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->mainLayout = new QVBoxLayout(this);
        this->title = new QLabel("Wainting for tirette", this);
        this->title->setStyleSheet("font-size: 30px; color: black;");
        this->wating = new QLabel("Waiting", this);
        this->wating->setStyleSheet("font-size: 24px; color: black;");

        this->mainLayout->addWidget(this->title, 0, Qt::AlignCenter | Qt::AlignTop);
        this->mainLayout->addWidget(this->wating, 0, Qt::AlignCenter | Qt::AlignTop);

        this->timer = new QTimer(this);

        connect(this->timer, &QTimer::timeout, this, [=]() {
            this->i = (this->i + 1) % 3;
            QString message = "Waiting";
            for (int j = 0; j < this->i; j++)
            {
                message += ".";
            }
            this->wating->setText(message);
        });

        this->disarme = new QPushButton("Disarme", this);
        this->disarme->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 66px; width: 378px; color: black; font-size: 33px;");
        this->disarme->setBaseSize(378, 66);
        this->mainLayout->addWidget(this->disarme);
        connect(this->disarme, &QPushButton::pressed, this, &WaintingForTirette::disarmePressed);

    }

    ~WaintingForTirette()
    {
        delete this->title;
        delete this->wating;
        delete this->timer;
        delete this->mainLayout;
    }

    void responseFromTirette(const std::string& response)
    {
        std::vector<std::string> list = TCPSocket::split(response, ";");

        if (list[3] == "0")
        {
            emit startGame();
        }
    }

    void startWaiting()
    {
        this->timer->start(1000);
    }

signals:
    void startGame();
    void disarmePressed();


private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QLabel* wating;
    QTimer* timer;
    QPushButton* disarme;

    int i = 0;
};
