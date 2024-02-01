#pragma once

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


class TestModeBtn : public QWidget{
    Q_OBJECT
public:
    TestModeBtn(const QString& name, const int min = 0, const int max = 0, QWidget *parent = nullptr) : QWidget(parent), borne({min, max}) {
        this->layout = new QHBoxLayout(this);
        this->layout->setAlignment(Qt::AlignCenter);

        this->textLabel = new QLabel(name, this);
        textLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

        this->valueLabel = new QLabel(QString::number(this->value), this);
        this->valueLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

        this->increment = new QPushButton("+", this);
        this->increment->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        this->increment->setBaseSize(46, 46);

        this->decrement = new QPushButton("-", this);
        this->decrement->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        this->decrement->setBaseSize(46, 46);

        this->increment10 = new QPushButton("+10", this);
        this->increment10->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        this->increment10->setBaseSize(46, 46);

        this->decrement10 = new QPushButton("-10", this);
        this->decrement10->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        this->decrement10->setBaseSize(46, 46);

        connect(this->decrement, &QPushButton::pressed, this, [=]()
        {
            if (this->value > this->borne.min)
            {
                this->value--;
                this->valueLabel->setText(QString::number(this->value));
            }
        });

        connect(this->increment, &QPushButton::pressed, this, [=]()
        {
            if (this->value < this->borne.max)
            {
                this->value++;
                this->valueLabel->setText(QString::number(this->value));
            }
        });

        connect(this->increment10, &QPushButton::pressed, this, [=]()
        {
            if (this->value + 10 <= this->borne.max)
            {
                this->value += 10;
                this->valueLabel->setText(QString::number(this->value));
            }
            else
            {
                this->value = this->borne.max;
                this->valueLabel->setText(QString::number(this->value));
            }
        });

        connect(this->decrement10, &QPushButton::pressed, this, [=]()
        {
            if (this->value - 10 >= this->borne.min)
            {
                this->value -= 10;
                this->valueLabel->setText(QString::number(this->value));
            }
            else
            {
                this->value = this->borne.min;
                this->valueLabel->setText(QString::number(this->value));
            }
        });

        layout->addWidget(textLabel);
        layout->addWidget(decrement10);
        layout->addWidget(decrement);
        layout->addWidget(valueLabel);
        layout->addWidget(increment);
        layout->addWidget(increment10);
    }

    void setBorne(const int min, const int max)
    {
        this->borne = {min, max};
    }

    int getValue() const
    {
        return value;
    }

private:
    QHBoxLayout *layout;
    QLabel *textLabel;
    QLabel *valueLabel;
    QPushButton *decrement10;
    QPushButton *decrement;
    QPushButton *increment;
    QPushButton *increment10;

    int value = 0;

    struct Borne
    {
        int min;
        int max;
    } borne;
};
