#ifndef CABSTRUCTFSM_H
#define CABSTRUCTFSM_H

#include <QObject>
#include <qDebug>
#include "cabstructcontrolleritem.h"

class CAbstructFSM : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructFSM(QObject *parent = 0);

signals:
    void sendDataToIONetworkManager(const QString &data);
    void sendDataToDBManager(const QString &data);

public slots:
    void fsm(const QString &data);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTFSM_H
