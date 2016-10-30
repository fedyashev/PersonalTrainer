#ifndef IONETWORKMANAGER_H
#define IONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class IONetworkManager : public QObject
{
Q_OBJECT

public:
    explicit IONetworkManager(QTcpSocket *socket, QObject *parent = 0);

    void initConnections();

private:
    QTcpSocket *socket;

signals:

public slots:
    void recieveData();
    void errorPrint();

};

#endif // IONETWORKMANAGER_H
