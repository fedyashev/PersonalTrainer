#ifndef CSERVERCONTROLLER_H
#define CSERVERCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "cserverionetworkmanager.h"
#include "cserverdbmanager.h"
#include "cserverfsm.h"

class CServerController : public QObject
{
    Q_OBJECT
public:
    explicit CServerController(QTcpSocket *socket, QObject *parent = 0);

    CServerIONetworkManager *getIONetworkManager() const;
    CServerFSM *getFSM() const;
    CServerDBManager *getDBManager() const;

    void initConnections() const;

private:
    CServerIONetworkManager *m_net;
    CServerFSM *m_fsm;
    CServerDBManager *m_dbm;
    QThread *m_thread;
};

#endif // CSERVERCONTROLLER_H
