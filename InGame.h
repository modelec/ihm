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

    void updatePos(std::string x, std::string y) const;

    void updateTime();

    void showEvent(QShowEvent* event) override;

signals:
    askTCPServer(const std::string& message);

private:
    QLabel* pts;
    QLabel* x;
    QLabel* y;
    QLabel* time;
    QVBoxLayout* mainLayout;
    QHBoxLayout* posAndTimeLayout;
    QVBoxLayout* posLayout;
    QTimer* timer;
    int timeCounter = 0;
};
