#pragma once
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QBrush>

class InGame : public QWidget {
    Q_OBJECT
public:
    explicit InGame(QWidget* parent = nullptr);

    void updateScode() const;

    void updatePos(const std::string& x, const std::string &y) const;

    void updateSpeed(const std::string& speed) const;

    void updateAngle(const std::string& angle) const;

    void updateTime();

    void showEvent(QShowEvent* event) override;

    void stopTimer() const;

    void setScore(int score);

    void addScore(int score);

signals:
    void askTCPServer(const std::string& message);

private:
    QLabel* pts;
    QLabel* x;
    QLabel* y;
    QLabel* time;
    QLabel* speed;
    QLabel* angle;
    QVBoxLayout* mainLayout;
    QHBoxLayout* posAndTimeLayout;
    QVBoxLayout* posLayout;
    QTimer* timer;
    int timeCounter = 0;

    int score = 0;
};
