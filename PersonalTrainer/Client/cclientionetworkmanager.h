#ifndef CCLIENTIONETWORKMANAGER_H
#define CCLIENTIONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include "../lib/cabstructionetworkmanager.h"

class CClientIONetworkManager : public CAbstructIONetworkManager
{
    Q_OBJECT
public:
    explicit CClientIONetworkManager(QTcpSocket *socket, QObject * parent = 0);
    virtual ~CClientIONetworkManager();

public slots:
    void error(QAbstractSocket::SocketError);
    void connectToHost();

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CCLIENTIONETWORKMANAGER_H
