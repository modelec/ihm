#pragma once

#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QVBoxLayout>

class GCMode : public QWidget {
    Q_OBJECT
public:
    explicit GCMode(QWidget* parent = nullptr) : QWidget(parent) {
        layout = new QVBoxLayout(this);

        gifLabel = new QLabel(this);
        gifMovie = new QMovie(":/img/tenor.gif");

        gifLabel->setMovie(gifMovie);
        gifMovie->start();
        layout->addWidget(gifLabel);
        layout->setAlignment(Qt::AlignCenter);
    };

private:
    QVBoxLayout* layout;
    QLabel *gifLabel;
    QMovie *gifMovie;
};
