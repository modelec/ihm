#pragma once
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class InGame : public QWidget {
    Q_OBJECT
public:
    InGame(QWidget* parent = nullptr) : QWidget(parent)
    {
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

        this->mainLayout->addWidget(pts);

        this->posAndTimeLayout = new QHBoxLayout();

        this->mainLayout->addLayout(this->posAndTimeLayout);

        this->posAndTimeLayout->addWidget(time);

        this->posLayout = new QVBoxLayout();

        this->posLayout->addWidget(x);
        this->posLayout->addWidget(y);
        this->posLayout->setAlignment(Qt::AlignCenter);

        this->posAndTimeLayout->addLayout(this->posLayout);

        this->setLayout(mainLayout);
    }

    void updateScode(const int score) const
    {
        this->pts->setText("Points : " + QString::number(score));
    }

    void updatePos(const int x, const int y) const
    {
        this->x->setText("X : " + QString::number(x));
        this->y->setText("Y : " + QString::number(y));
    }

    void updateTime(const int min, const int sec) const
    {
        this->time->setText("Time : " + QString::number(min) + "m" + QString::number(sec) + "s");
    }

private:
    QLabel* pts;
    QLabel* x;
    QLabel* y;
    QLabel* time;
    QVBoxLayout* mainLayout;
    QHBoxLayout* posAndTimeLayout;
    QVBoxLayout* posLayout;

};
