#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include "Client.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QGridLayout *grid;
    QLabel *label1;
    QLabel *label2;
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit *ledit1;
    QLineEdit *ledit2;

    Client client;

signals:
    void authorization(const QString& login, const QString& password);

public slots:
    void button1OnClick();
    void showMessageDialog(const QString& msg);
};

#endif // WIDGET_H
