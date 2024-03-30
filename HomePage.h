#pragma once

#include <qguiapplication.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class HomePage : public QWidget {
    Q_OBJECT
public:
    explicit HomePage(QWidget* parent = nullptr);

signals:
    void homologationClicked();
    void jeuClicked();
    void testClicked();


private:
    QVBoxLayout* mainLayout;
    QPushButton* homologation;
    QPushButton* jeu;
    QPushButton* test;
};
