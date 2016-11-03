#include "cservercontroller.h"

CServerController::CServerController(QTcpSocket *socket, QObject *parent) :
    QObject(parent),
    m_net(0),
    m_fsm(0),
    m_dbm(0),
    m_thread(0)
{
    m_net = new CServerIONetworkManager(socket);
    m_fsm = new CServerFSM();
    m_dbm = new CServerDBManager();
    m_thread = new QThread();

    initConnections();

    socket->setParent(NULL);
    socket->moveToThread(m_thread);
    m_net->moveToThread(m_thread);
    m_fsm->moveToThread(m_thread);
    m_dbm->moveToThread(m_thread);
    m_thread->start();
}

CServerController::~CServerController()
{
    qDebug() << "CServerController: destructor " << this;
}


CServerIONetworkManager *CServerController::getIONetworkManager() const
{
    return m_net;
}

CServerFSM *CServerController::getFSM() const
{
    return m_fsm;
}

CServerDBManager *CServerController::getDBManager() const
{
    return m_dbm;
}

void CServerController::initConnections() const
{
    connect(m_net, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));
    connect(m_dbm, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));
    connect(m_fsm, SIGNAL(sendDataToIONetworkManager(QString*)), m_net, SIGNAL(recvData(QString*)));
    connect(m_fsm, SIGNAL(sendDataToDBManager(QString*)), m_dbm, SIGNAL(recvData(QString*)));
    connect(m_net, SIGNAL(disconnected()), m_net, SLOT(deleteLater()));
    connect(m_net, SIGNAL(disconnected()), m_fsm, SLOT(deleteLater()));
    connect(m_net, SIGNAL(disconnected()), m_dbm, SLOT(deleteLater()));
    connect(m_net, SIGNAL(disconnected()), m_thread, SLOT(quit()));
    connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));
    connect(m_thread, SIGNAL(finished()), SIGNAL(finishWork()));
}
