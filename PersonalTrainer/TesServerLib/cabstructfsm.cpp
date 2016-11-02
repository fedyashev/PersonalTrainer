#include "cabstructfsm.h"

CAbstructFSM::CAbstructFSM(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
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

