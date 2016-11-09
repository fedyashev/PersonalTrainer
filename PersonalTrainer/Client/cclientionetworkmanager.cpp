#include "cclientionetworkmanager.h"

CClientIONetworkManager::CClientIONetworkManager(QTcpSocket *socket, QObject *parent):
    CAbstructIONetworkManager(socket, parent)
{
    initConnections();
}

CClientIONetworkManager::~CClientIONetworkManager()
{

}

void CClientIONetworkManager::error(QAbstractSocket::SocketError)
{
    emit sendData(new QString(getSocket()->errorString()));
}

void CClientIONetworkManager::connectToHost()
{
    getSocket()->connectToHost("192.168.100.2", 52816);
}

void CClientIONetworkManager::initConnections()
{
    connect(this->getSocket(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
}
