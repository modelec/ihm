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
        this->x = new QLabel("X : 0", this);
        this->y = new QLabel("Y : 0", this);
        this->time = new QLabel("Time : 0m0s", this);

        this->mainLayout->addWidget(pts);

        this->posAndTime = new QWidget(this);
        this->posAndTimeLayout = new QHBoxLayout(posAndTime);

        this->mainLayout->addWidget(posAndTime);

        this->posAndTimeLayout->addWidget(time);

        this->posWidget = new QWidget(this);
        this->posLayout = new QVBoxLayout(posWidget);

        this->posLayout->addWidget(x);
        this->posLayout->addWidget(y);

        this->posAndTimeLayout->addWidget(posWidget);

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
    QWidget* posAndTime;
    QVBoxLayout* mainLayout;
    QHBoxLayout* posAndTimeLayout;
    QWidget* posWidget;
    QVBoxLayout* posLayout;

};
