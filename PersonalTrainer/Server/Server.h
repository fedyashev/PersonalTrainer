#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "ServerController.h"

class Server : public QObject
{
Q_OBJECT

public:
    explicit Server(QObject *parent = 0);
    ~Server();

    void startServer();

private:
    QTcpServer server;

signals:

public slots:
    void newConnection();
};

#endif // SERVER_H
