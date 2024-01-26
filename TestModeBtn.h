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

        this->Text = new QLabel(name, this);
        Text->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

        Value = new QLabel(QString::number(this->value), this);
        Value->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

        Increment = new QPushButton("+", this);
        Increment->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Increment->setBaseSize(46, 46);

        Decrement = new QPushButton("-", this);
        Decrement->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Decrement->setBaseSize(46, 46);

        Increment10 = new QPushButton("+10", this);
        Increment10->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Increment10->setBaseSize(46, 46);

        Decrement10 = new QPushButton("-10", this);
        Decrement10->setStyleSheet("background-color: #5FC8F6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Decrement10->setBaseSize(46, 46);

        connect(this->Decrement, &QPushButton::pressed, this, [=]()
        {
            if (this->value > this->borne.min)
            {
                this->value--;
                this->Value->setText(QString::number(this->value));
            }
        });

        connect(this->Increment, &QPushButton::pressed, this, [=]()
        {
            if (this->value < this->borne.max)
            {
                this->value++;
                this->Value->setText(QString::number(this->value));
            }
        });

        connect(this->Increment10, &QPushButton::pressed, this, [=]()
        {
            if (this->value + 10 <= this->borne.max)
            {
                this->value += 10;
                this->Value->setText(QString::number(this->value));
            }
            else
            {
                this->value = this->borne.max;
                this->Value->setText(QString::number(this->value));
            }
        });

        connect(this->Decrement10, &QPushButton::pressed, this, [=]()
        {
            if (this->value - 10 >= this->borne.min)
            {
                this->value -= 10;
                this->Value->setText(QString::number(this->value));
            }
            else
            {
                this->value = this->borne.min;
                this->Value->setText(QString::number(this->value));
            }
        });

        layout->addWidget(Text);
        layout->addWidget(Decrement10);
        layout->addWidget(Decrement);
        layout->addWidget(Value);
        layout->addWidget(Increment);
        layout->addWidget(Increment10);
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
    QLabel *Text;
    QPushButton *Decrement;
    QLabel *Value;
    QPushButton *Increment;
    int value = 0;
    QPushButton *Increment10;
    QPushButton *Decrement10;

    struct Borne
    {
        int min;
        int max;
    } borne;
};
