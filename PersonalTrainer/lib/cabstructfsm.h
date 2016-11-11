#ifndef CABSTRUCTFSM_H
#define CABSTRUCTFSM_H

#include <QObject>
#include <QDebug>
#include "cabstructcontrolleritem.h"

/*!
 * \brief Базовый класс реализующий базовый функционал конечного автомата.
 */

class CAbstructFSM : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructFSM(QObject *parent = 0);
    virtual ~CAbstructFSM();

signals:
    //! \brief Сигнал передачи данных объекту управляющему сетевым взаимодействием.
    void sendDataToIONetworkManager(QString*);

     //! \brief Сигнал передачи данных объекту работающему с базой данных.
    void sendDataToDBManager(QString*);

public slots:
    void fsm(QString* data);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTFSM_H
