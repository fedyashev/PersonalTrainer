#ifndef CABSTRUCTIONETWORKMANAGER_H
#define CABSTRUCTIONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <Data.h>

class CAbstructIONetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit CAbstructIONetworkManager(QTcpSocket* socket, QObject *parent = 0);

    virtual void initConnection() = 0;

    QTcpSocket *getSocket() const;

private:
    QTcpSocket *m_socket;

signals:
    void sendDataToFSM(const Data&);

public slots:
    void recieveDataFromNetwork();
};

#endif // CABSTRUCTIONETWORKMANAGER_H
