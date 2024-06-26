#include "TestModeBtn.h"

TestModeBtn::TestModeBtn(const QString &name, const int min, const int max, QWidget *parent) : QWidget(parent), borne({min, max}) {
    this->layout = new QHBoxLayout(this);
    this->layout->setAlignment(Qt::AlignCenter);

    this->textLabel = new QLabel(name, this);
    textLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

    this->valueLabel = new QLabel(QString::number(this->value), this);
    this->valueLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

    this->increment10 = new QPushButton("+10", this);
    this->increment10->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
    this->increment10->setBaseSize(46, 46);

    this->decrement10 = new QPushButton("-10", this);
    this->decrement10->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
    this->decrement10->setBaseSize(46, 46);

    this->increment100 = new QPushButton("+100", this);
    this->increment100->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
    this->increment100->setBaseSize(46, 46);

    this->decrement100 = new QPushButton("-100", this);
    this->decrement100->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
    this->decrement100->setBaseSize(46, 46);

    connect(this->decrement10, &QPushButton::pressed, this, [=]()
    {
        if (this->value - 10 > this->borne.min)
        {
            this->value-=10;
            this->valueLabel->setText(QString::number(this->value));
        }
    });

    connect(this->increment10, &QPushButton::pressed, this, [=]()
    {
        if (this->value + 10 < this->borne.max)
        {
            this->value+=10;
            this->valueLabel->setText(QString::number(this->value));
        }
    });

    connect(this->increment100, &QPushButton::pressed, this, [=]()
    {
        if (this->value + 100 <= this->borne.max)
        {
            this->value += 100;
            this->valueLabel->setText(QString::number(this->value));
        }
        else
        {
            this->value = this->borne.max;
            this->valueLabel->setText(QString::number(this->value));
        }
    });

    connect(this->decrement100, &QPushButton::pressed, this, [=]()
    {
        if (this->value - 100 >= this->borne.min)
        {
            this->value -= 100;
            this->valueLabel->setText(QString::number(this->value));
        }
        else
        {
            this->value = this->borne.min;
            this->valueLabel->setText(QString::number(this->value));
        }
    });

    layout->addWidget(textLabel);
    layout->addWidget(decrement100);
    layout->addWidget(decrement10);
    layout->addWidget(valueLabel);
    layout->addWidget(increment10);
    layout->addWidget(increment100);
}

void TestModeBtn::setBorne(const int min, const int max)
{
    this->borne = {min, max};
}

int TestModeBtn::getValue() const
{
    return this->value;
}
