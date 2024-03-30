#pragma once

#include <QLabel>
#include <QWidget>
#include "TestModeBtn.h"

class TestMode : public QWidget {
    Q_OBJECT
public:
    explicit TestMode(QWidget* parent = nullptr);

private slots:
    void onGoPressed();

signals:
    void goPressed(int x, int y, int theta);

private:
    QVBoxLayout* mainLayout;
    QLabel* text;
    TestModeBtn* X;
    TestModeBtn* Y;
    TestModeBtn* Theta;
    QPushButton* go;
    QLabel* textcm;
    QLabel* textrad;
};