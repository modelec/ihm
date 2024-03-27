#pragma once
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class TiretteState : public QWidget {
    Q_OBJECT

public:
    TiretteState(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->mainLayout = new QVBoxLayout(this);
        this->title = new QLabel("Tirette", this);
        this->title->setStyleSheet("font-size: 24px; color: black;");

        this->tiretteStateLayout = new QHBoxLayout();
        this->stateLabel = new QLabel(" ", this);
        this->stateButton = new QPushButton("Get state", this);
        this->tiretteStateLayout->addWidget(stateLabel);
        this->tiretteStateLayout->addWidget(stateButton);

        this->mainLayout->addWidget(this->title, 0, Qt::AlignCenter);
        this->mainLayout->addLayout(this->tiretteStateLayout);

        connect(this->stateButton, &QPushButton::clicked, this, &TiretteState::onStateButtonClicked);
    }

    void setState(const std::string& state)
    {
        if (state == "1")
        {
            this->stateLabel->setText("1 : Tirette en place");
        } else if (state == "0")
        {
            this->stateLabel->setText("0 : Tirette absente");
        }
    }

signals:
    void askTCPServer(const std::string& message);

public slots:
    void onStateButtonClicked()
    {
        emit askTCPServer("strat;tirette;ping;0");
    }

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* tiretteStateLayout;
    QLabel* stateLabel;
    QPushButton* stateButton;
};
