#include "Server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

Server::~Server()
{

}

void Server::startServer()
{
    connect(&server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    int port = 52816;
    if (server.listen(QHostAddress::Any, port)) {
        qDebug() << "Server start: true.";
    } else {
        qDebug() << "Server start: false.";
    }
}

void Server::newConnection()
{
    Client *client = new Client(server.nextPendingConnection());
    qDebug() << "Client connected: socket " << client->getSocket()->socketDescriptor();
}
