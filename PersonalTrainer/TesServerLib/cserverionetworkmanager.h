#ifndef CSERVERIONETWORKMANAGER_H
#define CSERVERIONETWORKMANAGER_H

#include <QDebug>
#include "cabstructionetworkmanager.h"


class CServerIONetworkManager : public CAbstructIONetworkManager
{
    Q_OBJECT
public:
    CServerIONetworkManager(QTcpSocket *socket, QObject *parent = 0);

public slots:
    void errorPrint(QAbstractSocket::SocketError);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CSERVERIONETWORKMANAGER_H
