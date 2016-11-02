#ifndef CABSTRUCTIONETWORKMANAGER_H
#define CABSTRUCTIONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include "cabstructcontrolleritem.h"

class CAbstructIONetworkManager : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent = 0);

    QTcpSocket *getSocket() const;

private:
    QTcpSocket *m_socket;

signals:


public slots:
    void recvDataFromSocket();
    void sendDataToSocket(const QString &data);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTIONETWORKMANAGER_H
