#pragma once
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class Lidar : public QWidget {
    Q_OBJECT

public:
    Lidar(QWidget* parent = nullptr);

    void TCPMessage(const QString& message);

signals:
    void askTCPServer(const std::string& message);

public slots:
    void onStartButtonClicked();

    void onHealthButtonClicked();

    void onPositionButtonClicked();

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* position;
    QHBoxLayout* health;

    QPushButton* startLidar;

    QLabel* postionTitle;
    QPushButton* positionButton;

    QLabel* healthTitle;
    QPushButton* healthButton;
};
