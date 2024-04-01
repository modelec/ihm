#pragma once
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class TiretteState : public QWidget {
    Q_OBJECT

public:
    TiretteState(QWidget* parent = nullptr);

    void setState(const std::string& state);

signals:
    void askTCPServer(const std::string& message);

public slots:
    void onStateButtonClicked();

private:
    QVBoxLayout* mainLayout;
    QLabel* title;
    QHBoxLayout* tiretteStateLayout;
    QLabel* stateLabel;
    QPushButton* stateButton;
};
