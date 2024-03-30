#include "WaintingForTirette.h"

WaintingForTirette::WaintingForTirette(QWidget *parent) : QWidget(parent) {
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

WaintingForTirette::~WaintingForTirette() {
    delete this->title;
    delete this->wating;
    delete this->timer;
    delete this->mainLayout;
}

void WaintingForTirette::responseFromTirette(const std::string& response)
{
    std::vector<std::string> list = TCPSocket::split(response, ";");

    if (list[3] == "0")
    {
        emit startGame();
    }
}

void WaintingForTirette::startWaiting() const {
    this->timer->start(1000);
}
