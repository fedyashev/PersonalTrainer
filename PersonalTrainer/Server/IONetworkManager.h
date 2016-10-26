#ifndef IONETWORKMANAGER_H
#define IONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>

class IONetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit IONetworkManager(QTcpSocket *socket, QObject *parent = 0);

private:
    QTcpSocket *socket;

signals:
    void recievedData(const QString& data);
    void finish();

public slots:
    void sendData(const QString &data);
    void recieveData();
    void disconnected();
};

#endif // IONETWORKMANAGER_H
