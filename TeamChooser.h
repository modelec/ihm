#pragma once
#include <qboxlayout.h>
#include <QPushButton>
#include <QWidget>

class TeamChooser : public QWidget {
    Q_OBJECT
public:
    explicit TeamChooser(QWidget* parent = nullptr);

private slots:
    void spawnPointClicked(int nb);

signals:
    void spawnPointChoose(int nb);


private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* middleLayout;
    QHBoxLayout* bottomLayout;

    QPushButton* spawnPoint1;
    QPushButton* spawnPoint2;
    QPushButton* spawnPoint3;
    QPushButton* spawnPoint4;
    QPushButton* spawnPoint5;
    QPushButton* spawnPoint6;

};
