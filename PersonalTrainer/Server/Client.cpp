#include "Client.h"

Client::Client(QTcpSocket *socket, QObject *parent) : QObject(parent), socket(socket)
{
    socket->setParent(NULL);
    thread = new QThread();
    net_manager = new IONetworkManager(socket);

    initConnection();

    socket->moveToThread(thread);
    net_manager->moveToThread(thread);

    thread->start();
}

void Client::initConnection()
{
    connect(socket, SIGNAL(readyRead()), net_manager, SLOT(recieveData()));
    connect(socket, SIGNAL(disconnected()), net_manager, SLOT(disconnected()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    connect(net_manager, SIGNAL(finish()), thread, SLOT(quit()));
    connect(net_manager, SIGNAL(finish()), net_manager, SLOT(deleteLater()));

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
}

QTcpSocket *Client::getSocket() const
{
    return socket;
}
