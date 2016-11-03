#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "cclientcontroller.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initConnections();

private:
    QLabel *label1;
    QLabel *label2;
    QLineEdit *line1;
    QLineEdit *line2;
    QPushButton *button1;
    QPushButton *button2;
    QGridLayout *grid;

    CClientController *controller;
};

#endif // MAINWINDOW_H
