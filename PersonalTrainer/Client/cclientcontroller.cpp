#include "cclientcontroller.h"

CClientController::CClientController(QTcpSocket *socket, QObject *parent):
    CAbstructControllerItem(parent), m_net(0), m_fsm(0), m_dbm(0), m_thread(0)
{
    socket->setParent(NULL);

    m_net = new CClientIONetworkManager(socket);
    m_fsm = new CClientFSM();
    m_dbm = new CClientDBManager();
    m_thread = new QThread(this);

    initConnections();

    socket->moveToThread(m_thread);
    m_net->moveToThread(m_thread);
    m_fsm->moveToThread(m_thread);
    m_dbm->moveToThread(m_thread);
    m_thread->start();
}

CClientController::~CClientController()
{

}

CClientIONetworkManager *CClientController::getIONetworkManager() const
{
    return m_net;
}

CClientFSM *CClientController::getFSM() const
{
    return m_fsm;
}

CClientDBManager *CClientController::getDBManager() const
{
    return m_dbm;
}

void CClientController::initConnections()
{
    connect(m_net, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));
    connect(m_dbm, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));
    connect(m_fsm, SIGNAL(sendDataToIONetworkManager(QString*)), m_net, SIGNAL(recvData(QString*)));
    connect(m_fsm, SIGNAL(sendDataToDBManager(QString*)), m_dbm, SIGNAL(recvData(QString*)));
    connect(m_net, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(this, SIGNAL(disconnected()), m_net, SLOT(deleteLater()));
    connect(this, SIGNAL(disconnected()), m_fsm, SLOT(deleteLater()));
    connect(this, SIGNAL(disconnected()), m_dbm, SLOT(deleteLater()));
    connect(this, SIGNAL(disconnected()), m_thread, SLOT(quit()));
    connect(m_thread, SIGNAL(finished()), this, SIGNAL(finished()));
    connect(this, SIGNAL(connectToHost()), m_net, SLOT(connectToHost()));
}
