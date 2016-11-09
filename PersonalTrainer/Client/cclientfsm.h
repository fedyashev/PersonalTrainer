#ifndef CCLIENTFSM_H
#define CCLIENTFSM_H

#include <QObject>
#include "../lib/cabstructfsm.h"

class CClientFSM : public CAbstructFSM
{
    Q_OBJECT
public:
    explicit CClientFSM(QObject *parent = 0);
    virtual ~CClientFSM();


    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CCLIENTFSM_H
