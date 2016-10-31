#include "CAbstructIONetworkManager.h"

CAbstructIONetworkManager::CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent) :
    QObject(parent), m_socket(socket)
{
    initConnection();
}

QTcpSocket *CAbstructIONetworkManager::getSocket() const
{
    return m_socket;
}

void CAbstructIONetworkManager::recieveDataFromNetwork()
{
    QByteArray data = m_socket->readAll();
    qDebug() << m_socket->socketDescriptor() << " " << data.data();
}

void CAbstructIONetworkManager::initConnection()
{
    connect(m_socket, SIGNAL(readyRead()), SLOT(recieveDataFromNetwork()));
}
