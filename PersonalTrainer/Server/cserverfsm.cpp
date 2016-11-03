#include "cserverfsm.h"

CServerFSM::CServerFSM(QObject *parent) :
    CAbstructFSM(parent)
{
    initConnections();
}

CServerFSM::~CServerFSM()
{
    qDebug() << "CServerFSM: destructor " << this;
}

void CServerFSM::initConnections()
{

}
