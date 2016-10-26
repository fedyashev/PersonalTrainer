#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "IONetworkManager.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket *socket, QObject *parent = 0);

    void initConnection();

    QTcpSocket *getSocket() const;

private:
    QTcpSocket *socket;
    QThread *thread;
    IONetworkManager *net_manager;

signals:

public slots:
};

#endif // CLIENT_H
