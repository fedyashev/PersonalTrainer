#include "Controller.h"

Controller::Controller(QObject *parent):
    AbstractController(new QTcpSocket(parent), NULL, parent)
{

}

void Controller::initConnections()
{

}
