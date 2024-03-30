#pragma once

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <TCPSocket/TCPUtils.hpp>

#include "HomePage.h"


class WaintingForTirette : public QWidget {
    Q_OBJECT
public:

    explicit WaintingForTirette(QWidget* parent = nullptr);

    ~WaintingForTirette() override;

    void responseFromTirette(const std::string& response);

    void startWaiting() const;

signals:
    void startGame();
    void disarmePressed();


private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QLabel* wating;
    QTimer* timer;
    QPushButton* disarme;

    int i = 0;
};
