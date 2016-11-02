#include "cabstructionetworkmanager.h"

CAbstructIONetworkManager::CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent) :
    CAbstructControllerItem(parent), m_socket(socket)
{
    initConnections();
}

QTcpSocket *CAbstructIONetworkManager::getSocket() const
{
    return m_socket;
}

void CAbstructIONetworkManager::recvDataFromSocket()
{
    QByteArray raw_data = m_socket->readAll();
    emit sendData(QString(raw_data.data()));
}

void CAbstructIONetworkManager::sendDataToSocket(const QString &data)
{
    char* msg = data.toUtf8().data();
    m_socket->write(msg, strlen(msg));
    m_socket->waitForBytesWritten(500);
    m_socket->flush();
}

void CAbstructIONetworkManager::initConnections()
{
    connect(m_socket, SIGNAL(readyRead()), SLOT(recvDataFromSocket()));
    connect(this, SIGNAL(recvData(QString)), this, SLOT(sendDataToSocket(QString)));
}
