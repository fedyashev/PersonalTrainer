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
    QTcpSocket *socket = server.nextPendingConnection();
    ServerController *client = new ServerController(socket, this);
    qDebug() << "Client connected: socket " << socket->socketDescriptor() << ", current thread " << thread();
}
