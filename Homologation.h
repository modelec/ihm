#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class Homologation : public QWidget {
    Q_OBJECT
public:
    explicit Homologation(QWidget* parent = nullptr);

protected slots:
    void onDeplierClicked();

    void onReplierClicked();

    void onPanneauGaucheClicked();

    void onPanneauDroitClicked();

signals:
    void deplierClicked();
    void replierClicked();
    void panneauGaucheClicked();
    void panneauDroitClicked();

private:
    QLayout* layout;
    QLabel* text;
    QPushButton* deplier;
    QPushButton* replier;
    QPushButton* panneauGauche;
    QPushButton* panneauDroit;

};
