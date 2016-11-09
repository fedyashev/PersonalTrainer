#include "cserverdbmanager.h"

CServerDBManager::CServerDBManager(QObject *parent) :
    CAbstructDBManager(parent)
{
    initConnections();
}

CServerDBManager::~CServerDBManager()
{
    qDebug() << "CServerDBManager: destructor " << this;
}

void CServerDBManager::initConnections()
{

}

