#include "cabstructionetworkmanager.h"

CAbstructIONetworkManager::CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent) :
    CAbstructControllerItem(parent), m_socket(socket)
{
    initConnections();
}

CAbstructIONetworkManager::~CAbstructIONetworkManager()
{
    qDebug() << "CAbstructIONetworkManager: destructor " << this;
}

QTcpSocket *CAbstructIONetworkManager::getSocket() const
{
    return m_socket;
}

void CAbstructIONetworkManager::recvDataFromSocket()
{
    QByteArray raw_data = m_socket->readAll();
    QString raw_string(raw_data.data());
    emit sendData(new QString(raw_string.toUtf8().data()));
}

void CAbstructIONetworkManager::sendDataToSocket(QString* data)
{
    QByteArray byte_data = data->toUtf8();
    char* msg = byte_data.data();
    m_socket->write(msg, byte_data.size());
    m_socket->waitForBytesWritten(500);
    m_socket->flush();
}

void CAbstructIONetworkManager::initConnections()
{
    connect(m_socket, SIGNAL(readyRead()), SLOT(recvDataFromSocket()));
    connect(this, SIGNAL(recvData(QString*)), this, SLOT(sendDataToSocket(QString*)));
    connect(m_socket, SIGNAL(disconnected()), SIGNAL(disconnected()));
    connect(m_socket, SIGNAL(disconnected()), m_socket, SLOT(deleteLater()));
}
