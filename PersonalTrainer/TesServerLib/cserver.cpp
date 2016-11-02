#include "cserver.h"

CServer::CServer(QObject *parent) :
    QObject(parent), m_server(new QTcpServer())
{
    initConnections();
}

void CServer::initConnections()
{
    startServer();
    connect(m_server, SIGNAL(newConnection()), SLOT(newConnection()));
}

QTcpServer *CServer::getServer() const
{
    return m_server;
}

void CServer::newConnection()
{
    QTcpSocket *socket = m_server->nextPendingConnection();
    CServerController *controller = new CServerController(socket, this);
    qDebug() << "Client connected. SC: " << socket->socketDescriptor();
}

void CServer::startServer()
{
    if (m_server->listen(QHostAddress::Any,52816))
    {
        qDebug() << "Server started: success.";
    } else
    {
        qDebug() << "Server started: faild.";
    }
}

