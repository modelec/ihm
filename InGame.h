#pragma once
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class InGame : public QWidget {
    Q_OBJECT
public:
    explicit InGame(QWidget* parent = nullptr);

    void updateScode(int score) const;

    void updatePos(int x, int y) const;

    void updateTime(int min, int sec) const;

private:
    QLabel* pts;
    QLabel* x;
    QLabel* y;
    QLabel* time;
    QVBoxLayout* mainLayout;
    QHBoxLayout* posAndTimeLayout;
    QVBoxLayout* posLayout;
};
