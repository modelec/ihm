#pragma once
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QCheckBox>
#include <QPushButton>

class OneItemPreparation : public QWidget {
    Q_OBJECT

public:
    OneItemPreparation(const QString& title, const QString& buttonText, QWidget* parent = nullptr) : QWidget(parent)
    {
        this->mainLayout = new QHBoxLayout(this);

        this->item = new QLabel(title, this);
        this->checkBox = new QCheckBox(this);
        this->button = new QPushButton(buttonText, this);

        this->mainLayout->addWidget(item);
        this->mainLayout->addWidget(checkBox);
        this->mainLayout->addWidget(button);

        this->checkBox->setDisabled(true);

        connect(this->button, &QPushButton::pressed, this, &OneItemPreparation::onButtonClicked);
    }

    void setChecked(const bool checked) const
    {
        this->checkBox->setChecked(checked);
    }

    void toggleChecked() const
    {
        this->checkBox->toggle();
    }

    bool isChecked() const
    {
        return this->checkBox->isChecked();
    }

signals:
    void buttonClicked();

public slots:
    void onButtonClicked()
    {
        emit buttonClicked();
    }


private:
    QHBoxLayout* mainLayout;
    QLabel* item;
    QCheckBox* checkBox;
    QPushButton* button;
};
