#pragma once

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class TestModeBtn : public QWidget{
    Q_OBJECT
public:
    explicit TestModeBtn(const QString& name, int min = 0, int max = 0, QWidget *parent = nullptr);

    void setBorne(int min, int max);

    [[nodiscard]] int getValue() const;

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
