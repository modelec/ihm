//
// Created by breizhhardware on 1/25/24.
//

#ifndef TESTMODEBTN_H
#define TESTMODEBTN_H
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


class TestModeBtn : public QWidget{
    Q_OBJECT
public:
    TestModeBtn(QString name, QWidget *parent = nullptr) : QWidget(parent) {
        this->layout = new QVBoxLayout(this);
        this->layout->setAlignment(Qt::AlignCenter);

        QHBoxLayout *xLayout = new QHBoxLayout();

        this->Text = new QLabel(name, this);
        Text->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");
        xLayout->addWidget(Text);

        Decrement = new QPushButton("-", this);
        Decrement->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Decrement->setBaseSize(46, 46);


        Value = new QLabel(QString::number(this->valueTaMere), this);
        Value->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");

        Increment10 = new QPushButton("+10", this);
        Increment10->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Increment10->setBaseSize(46, 46);

        Decrement10 = new QPushButton("-10", this);
        Decrement10->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Decrement10->setBaseSize(46, 46);

        Increment = new QPushButton("+", this);
        Increment->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 46px; width: 46px; color: black;");
        Increment->setBaseSize(46, 46);

        connect(this->Decrement, &QPushButton::pressed, this, [=]()
        {
            this->valueTaMere--;
            this->Value->setText(QString::number(this->valueTaMere));
        });

        connect(this->Increment, &QPushButton::pressed, this, [=]()
        {
            this->valueTaMere++;
            this->Value->setText(QString::number(this->valueTaMere));
        });

        connect(this->Increment10, &QPushButton::pressed, this, [=]()
        {
            this->valueTaMere += 10;
            this->Value->setText(QString::number(this->valueTaMere));
        });

        connect(this->Decrement10, &QPushButton::pressed, this, [=]()
        {
            this->valueTaMere -= 10;
            this->Value->setText(QString::number(this->valueTaMere));
        });

        xLayout->addWidget(Decrement10);
        xLayout->addWidget(Decrement);
        xLayout->addWidget(Value);
        xLayout->addWidget(Increment);
        xLayout->addWidget(Increment10);

        this->layout->addLayout(xLayout);
    }

    int getValue() const
    {
        return valueTaMere;
    }
private:
    QVBoxLayout *layout;
    QLabel *Text;
    QPushButton *Decrement;
    QLabel *Value;
    QPushButton *Increment;
    int valueTaMere = 0;
    QPushButton *Increment10;
    QPushButton *Decrement10;
};



#endif //TESTMODEBTN_H
