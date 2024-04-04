#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "preparation/Lidar.h"
#include "preparation/OneItemPreparation.h"
#include "preparation/TiretteState.h"

class PreparationMatch : public QWidget {
    Q_OBJECT
public:
    explicit PreparationMatch(QWidget* parent = nullptr);

    void responseFromPing(const QString& message);

    void responseTiretteState(const QString& message);

    void responseLidar(const QString& message);

    void clearCheckboxes();

signals:
    void startGame();

    void askTCPServer(const std::string& message);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* gridLayout;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;

    Lidar* lidar;
    OneItemPreparation* ledVerte;
    OneItemPreparation* arduino;
    OneItemPreparation* aruco;
    OneItemPreparation* lidarPing;
    OneItemPreparation* tirette;
    OneItemPreparation* servo_moteur;
    TiretteState* tiretteState;

    QPushButton* startButton;
};
