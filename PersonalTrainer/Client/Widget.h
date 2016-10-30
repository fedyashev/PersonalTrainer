#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include "Controller.h"
#include "../lib/Data.h"

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

    Controller *m_client;

public slots:
    void button1OnClick();
    void showMessageDialog(const QString& msg);

signals:
    void authorization(const Data& data);
};

#endif // WIDGET_H
