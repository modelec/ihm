#include "TiretteState.h"

TiretteState::TiretteState(QWidget *parent) : QWidget(parent)
{
    this->mainLayout = new QVBoxLayout(this);
    this->title = new QLabel("Tirette", this);
    this->title->setStyleSheet("font-size: 24px; color: black;");

    this->tiretteStateLayout = new QHBoxLayout();
    this->stateLabel = new QLabel(" ", this);
    this->stateButton = new QPushButton("Get state", this);
    this->stateButton->setStyleSheet("height: 46px; color: black; font-size: 24px;");
    this->tiretteStateLayout->addWidget(stateLabel);
    this->tiretteStateLayout->addWidget(stateButton);

    this->mainLayout->addWidget(this->title, 0, Qt::AlignCenter);
    this->mainLayout->addLayout(this->tiretteStateLayout);

    connect(this->stateButton, &QPushButton::clicked, this, &TiretteState::onStateButtonClicked);
}

void TiretteState::setState(const std::string &state) {
    if (state == "1")
    {
        this->stateLabel->setText("1 : Tirette en place");
    } else if (state == "0")
    {
        this->stateLabel->setText("0 : Tirette absente");
    }
}

void TiretteState::onStateButtonClicked() {
    emit askTCPServer("strat;tirette;get state;1");
}
