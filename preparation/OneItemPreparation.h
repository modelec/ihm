#pragma once
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QCheckBox>
#include <QPushButton>

class OneItemPreparation : public QWidget {
    Q_OBJECT

public:
    OneItemPreparation(const QString& title, const QString& buttonText, QWidget* parent = nullptr);

    void setChecked(bool checked) const;

    void toggleChecked() const;

    [[nodiscard]] bool isChecked() const;

signals:
    void buttonClicked();

public slots:
    void onButtonClicked();

private:
    QHBoxLayout* mainLayout;
    QLabel* item;
    QCheckBox* checkBox;
    QPushButton* button;
};
