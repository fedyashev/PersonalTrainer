#include "cabstructfsm.h"

CAbstructFSM::CAbstructFSM(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
}

CAbstructFSM::~CAbstructFSM()
{
    qDebug() << "CAbsrtuctFSM: destructor " << this;
}

void CAbstructFSM::fsm(QString* data)
{
    qDebug() << *data;
    emit sendDataToIONetworkManager(new QString(*data));
    delete data;
}

void CAbstructFSM::initConnections()
{
    connect(this, SIGNAL(recvData(QString*)), SLOT(fsm(QString*)));
}

