#pragma once
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class Homologation : public QWidget {
    Q_OBJECT
public:
    Homologation(QWidget* parent = nullptr) : QWidget(parent)
    {
        this->layout = new QVBoxLayout(this);

        this->text = new QLabel("Mode Homologation", this);
        text->setStyleSheet("font-size: 66px; font-weight: bold; margin-top: 20px; color: black;");
        this->text->setAlignment(Qt::AlignCenter);
        layout->addWidget(text);

        this->deplier = new QPushButton("Déplier", this);
        deplier->setStyleSheet("background-color: #5FC8E6; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
        deplier->setBaseSize(378, 66);
        layout->addWidget(deplier);

        this->replier = new QPushButton("Replier", this);
        replier->setStyleSheet("background-color: #ED4747; border-radius: 20px; height: 66px; width: 378px; margin-top: 20px; color: black; font-size: 33px;");
        replier->setBaseSize(378, 66);
        layout->addWidget(replier);

        connect(this->deplier, &QPushButton::pressed, this, &Homologation::onDeplierClicked);

        connect(this->replier, &QPushButton::pressed, this, &Homologation::onReplierClicked);

    }

protected slots:
    void onDeplierClicked()
    {
        emit deplierClicked();
    }

    void onReplierClicked()
    {
        emit replierClicked();
    }

signals:
    void deplierClicked();
    void replierClicked();

private:
    QLayout* layout;
    QLabel* text;
    QPushButton* deplier;
    QPushButton* replier;

};
