#pragma once
#include <qboxlayout.h>
#include <QPushButton>
#include <QWidget>

class TeamChooser : public QWidget {
    Q_OBJECT
public:
    TeamChooser(QWidget* parent = nullptr) : QWidget(parent)
    {
        // set a border
        // this->setStyleSheet("border: 10px solid black;");

        this->mainLayout = new QVBoxLayout(this);

        this->topLayout = new QHBoxLayout();
        this->middleLayout = new QHBoxLayout();
        this->bottomLayout = new QHBoxLayout();

        this->spawnPoint1 = new QPushButton("1", this);
        this->spawnPoint1->setFixedSize(50, 50);
        this->spawnPoint1->setStyleSheet("border: 1px solid black; color: white; background-color: rgba(0, 0, 255, 200);");
        this->spawnPoint2 = new QPushButton("2", this);
        this->spawnPoint2->setFixedSize(50, 50);
        this->spawnPoint2->setStyleSheet("border: 1px solid black; color: black; background-color: rgba(255, 255, 0, 200);");
        this->spawnPoint3 = new QPushButton("3", this);
        this->spawnPoint3->setFixedSize(50, 50);
        this->spawnPoint3->setStyleSheet("border: 1px solid black; color: white; background-color: rgba(0, 0, 255, 200);");
        this->spawnPoint4 = new QPushButton("4", this);
        this->spawnPoint4->setFixedSize(50, 50);
        this->spawnPoint4->setStyleSheet("border: 1px solid black; color: black; background-color: rgba(255, 255, 0, 200);");
        this->spawnPoint5 = new QPushButton("5", this);
        this->spawnPoint5->setFixedSize(50, 50);
        this->spawnPoint5->setStyleSheet("border: 1px solid black; color: white; background-color: rgba(0, 0, 255, 200);");
        this->spawnPoint6 = new QPushButton("6", this);
        this->spawnPoint6->setFixedSize(50, 50);
        this->spawnPoint6->setStyleSheet("border: 1px solid black; color: black; background-color: rgba(255, 255, 0, 200);");

        this->mainLayout->addLayout(topLayout);
        this->mainLayout->addLayout(middleLayout);
        this->mainLayout->addLayout(bottomLayout);

        this->topLayout->addWidget(spawnPoint1, 0, Qt::AlignTop | Qt::AlignLeft);
        this->middleLayout->addWidget(spawnPoint2, 0, Qt::AlignCenter | Qt::AlignLeft);
        this->bottomLayout->addWidget(spawnPoint3, 0, Qt::AlignBottom | Qt::AlignLeft);
        this->topLayout->addWidget(spawnPoint4, 0, Qt::AlignTop | Qt::AlignRight);
        this->middleLayout->addWidget(spawnPoint5, 0, Qt::AlignCenter | Qt::AlignRight);
        this->bottomLayout->addWidget(spawnPoint6, 0, Qt::AlignBottom | Qt::AlignRight);

        connect(this->spawnPoint1, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(1);
        });

        connect(this->spawnPoint2, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(2);
        });

        connect(this->spawnPoint3, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(3);
        });

        connect(this->spawnPoint4, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(4);
        });

        connect(this->spawnPoint5, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(5);
        });

        connect(this->spawnPoint6, &QPushButton::pressed, this, [=]() {
            spawnPointClicked(6);
        });
    }

signals:
    void spawnPointChoose(int nb);

private slots:
    void spawnPointClicked(int nb)
    {
        emit spawnPointChoose(nb);
    }

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* middleLayout;
    QHBoxLayout* bottomLayout;

    QPushButton* spawnPoint1;
    QPushButton* spawnPoint2;
    QPushButton* spawnPoint3;
    QPushButton* spawnPoint4;
    QPushButton* spawnPoint5;
    QPushButton* spawnPoint6;

};
