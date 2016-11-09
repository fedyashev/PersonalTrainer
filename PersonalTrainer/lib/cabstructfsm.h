#ifndef CABSTRUCTFSM_H
#define CABSTRUCTFSM_H

#include <QObject>
#include <QDebug>
#include "cabstructcontrolleritem.h"

class CAbstructFSM : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructFSM(QObject *parent = 0);
    virtual ~CAbstructFSM();

signals:
    void sendDataToIONetworkManager(QString*);
    void sendDataToDBManager(QString*);

public slots:
    void fsm(QString* data);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTFSM_H
