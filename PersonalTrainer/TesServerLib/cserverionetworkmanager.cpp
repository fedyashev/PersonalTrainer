#include "cserverionetworkmanager.h"

CServerIONetworkManager::CServerIONetworkManager(QTcpSocket *socket, QObject *parent) :
    CAbstructIONetworkManager(socket, parent)
{
    initConnections();
}

CServerIONetworkManager::~CServerIONetworkManager()
{
    qDebug() << "CServerIONetworkManager: destructor " << this;
}

void CServerIONetworkManager::initConnections()
{
    connect(getSocket(), SIGNAL(error(QAbstractSocket::SocketError)), SLOT(errorPrint(QAbstractSocket::SocketError)));
}

void CServerIONetworkManager::errorPrint(QAbstractSocket::SocketError)
{
    qDebug() << getSocket()->errorString();
}

