#pragma once
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>

class InGame : public QWidget {
    Q_OBJECT
public:
    explicit InGame(QWidget* parent = nullptr);

    void updateScode(int score) const;

    void updatePos(const std::string& x, const std::string &y) const;

    void updateSpeed(const std::string& speed) const;

    void updateAngle(const std::string& angle) const;

    void updateTime();

    void showEvent(QShowEvent* event) override;

    void stopTimer() const;

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
};
