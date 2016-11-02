#ifndef CSERVERFSM_H
#define CSERVERFSM_H

#include "cabstructfsm.h"

class CServerFSM : public CAbstructFSM
{
    Q_OBJECT
public:
    CServerFSM(QObject *parent = 0);

signals:

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CSERVERFSM_H
