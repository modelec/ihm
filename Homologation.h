#pragma once
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class Homologation : public QWidget {
    Q_OBJECT
public:
    Homologation(QWidget* parent = nullptr);

protected slots:
    void onDeplierClicked();

    void onReplierClicked();

signals:
    void deplierClicked();
    void replierClicked();

private:
    QLayout* layout;
    QLabel* text;
    QPushButton* deplier;
    QPushButton* replier;

};
