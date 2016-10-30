#include "IONetworkManager.h"

IONetworkManager::IONetworkManager(QTcpSocket *socket, QObject *parent) : QObject(parent), socket(socket)
{
    initConnections();
}

void IONetworkManager::initConnections()
{
    connect(socket, SIGNAL(readyRead()), SLOT(recieveData()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(errorPrint()));
}

void IONetworkManager::recieveData() {
    QByteArray data = socket->readAll();
    qDebug() << "Socket " << socket->socketDescriptor() << ", thread " << thread() << ": " << data.data();
    socket->write(data.data());
    socket->flush();
}

void IONetworkManager::errorPrint()
{
    qDebug() << "Error: " << socket->errorString();
}
