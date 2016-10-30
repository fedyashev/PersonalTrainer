#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include "../lib/AbstractController.h"

class Controller : public AbstractController
{

public:
    Controller(QObject *parent = 0);

    // AbstractController interface
protected:
    void initConnections();
};

#endif // CONTROLLER_H
