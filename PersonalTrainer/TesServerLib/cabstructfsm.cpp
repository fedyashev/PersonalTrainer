#include "cabstructfsm.h"

CAbstructFSM::CAbstructFSM(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
}

void CAbstructFSM::fsm(const QString &data)
{
    qDebug() << data.toUtf8().data();
    emit sendDataToIONetworkManager(QString(data.toUtf8()));
}

void CAbstructFSM::initConnections()
{
    connect(this, SIGNAL(recvData(QString)), SLOT(fsm(QString)));
}

