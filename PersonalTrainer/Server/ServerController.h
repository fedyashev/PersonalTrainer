#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <QTcpSocket>
#include "../lib/AbstractController.h"

class ServerController : public AbstractController
{
Q_OBJECT

public:
    ServerController(QTcpSocket *socket, QObject *parent = 0);

    // AbstractController interface
protected:
    void initConnections();
};

#endif // SERVERCONTROLLER_H
