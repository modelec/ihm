#include "OneItemPreparation.h"

OneItemPreparation::OneItemPreparation(const QString &title, const QString &buttonText, QWidget *parent) : QWidget(parent)
{
    this->mainLayout = new QHBoxLayout(this);

    this->item = new QLabel(title, this);
    this->item->setStyleSheet("font-size: 24px; color: black;");
    this->checkBox = new QCheckBox(this);
    this->button = new QPushButton(buttonText, this);
    this->button->setStyleSheet("height: 46px; color: black; font-size: 24px;");

    this->mainLayout->addWidget(item);
    this->mainLayout->addWidget(checkBox);
    this->mainLayout->addWidget(button);

    this->checkBox->setDisabled(true);

    connect(this->button, &QPushButton::pressed, this, &OneItemPreparation::onButtonClicked);
}

void OneItemPreparation::setChecked(const bool checked) const
{
    this->checkBox->setChecked(checked);
}

void OneItemPreparation::toggleChecked() const
{
    this->checkBox->toggle();
}

bool OneItemPreparation::isChecked() const
{
    return this->checkBox->isChecked();
}

void OneItemPreparation::onButtonClicked() {
    emit buttonClicked();
}
