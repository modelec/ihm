#pragma once
#include <QWidget>

class TestMode : public QWidget {
    Q_OBJECT
public:
    TestMode(QWidget* parent = nullptr) : QWidget(parent) {}
};
