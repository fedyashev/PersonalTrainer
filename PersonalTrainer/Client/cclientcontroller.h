#ifndef CCLIENTCONTROLLER_H
#define CCLIENTCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "../lib/cabstructcontrolleritem.h"
#include "cclientionetworkmanager.h"
#include "cclientfsm.h"
#include "cclientdbmanager.h"

class CClientController : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CClientController(QTcpSocket *socket, QObject *parent = 0);
    virtual ~CClientController();

    CClientIONetworkManager *getIONetworkManager() const;
    CClientFSM *getFSM() const;
    CClientDBManager *getDBManager() const;

private:
    CClientIONetworkManager *m_net;
    CClientFSM *m_fsm;
    CClientDBManager *m_dbm;
    QThread *m_thread;

signals:
    void disconnected();
    void finished();
    void connectToHost();

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CCLIENTCONTROLLER_H
