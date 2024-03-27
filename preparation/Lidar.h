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

        this->position = new QHBoxLayout();
        this->postionTitle = new QLabel("x: 0, y : 0, r: 0", this);
        this->positionButton = new QPushButton("Get pos", this);

        this->position->addWidget(postionTitle);
        this->position->addWidget(positionButton);

        this->health = new QHBoxLayout();
        this->healthTitle = new QLabel("Health : OK", this);
        this->healthButton = new QPushButton("Get health", this);

        this->health->addWidget(healthTitle);
        this->health->addWidget(healthButton);

        this->mainLayout->addWidget(title, 0, Qt::AlignCenter);
        this->mainLayout->addLayout(position);
        this->mainLayout->addLayout(health);
    }

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* position;
    QHBoxLayout* health;

    QLabel* postionTitle;
    QPushButton* positionButton;

    QLabel* healthTitle;
    QPushButton* healthButton;
};
