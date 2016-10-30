#include "ServerController.h"

ServerController::ServerController(QTcpSocket *socket, QObject *parent) : AbstractController(socket, new QThread(parent), parent)
{

}

void ServerController::initConnections()
{

}
