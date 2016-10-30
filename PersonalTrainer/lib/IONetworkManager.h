#ifndef IONETWORKMANAGER_H
#define IONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "Data.h"

class IONetworkManager : public QObject
{
Q_OBJECT

public:
    explicit IONetworkManager(QTcpSocket *socket, QObject *parent = 0);

    void initConnections();
    QTcpSocket *getSocket() const;

private:
    QTcpSocket *socket;

signals:

public slots:
    void connectToHost(const Data& data);
    void recieveData();
    void errorPrint();

};

#endif // IONETWORKMANAGER_H
