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
        this->stateLabel = new QLabel("1 : ", this);
        this->stateButton = new QPushButton("Get state", this);
        this->tiretteStateLayout->addWidget(stateLabel);
        this->tiretteStateLayout->addWidget(stateButton);

        this->mainLayout->addWidget(this->title, 0, Qt::AlignCenter);
        this->mainLayout->addLayout(this->tiretteStateLayout);
    }

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* tiretteStateLayout;
    QLabel* stateLabel;
    QPushButton* stateButton;
};
