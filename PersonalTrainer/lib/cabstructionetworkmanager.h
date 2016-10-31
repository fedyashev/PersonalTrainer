#ifndef CABSTRUCTIONETWORKMANAGER_H
#define CABSTRUCTIONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>

class CAbstructIONetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit CAbstructIONetworkManager(QTcpSocket* socket, QObject *parent = 0);

private:
    QTcpSocket *m_socket;

signals:


public slots:
};

#endif // CABSTRUCTIONETWORKMANAGER_H
