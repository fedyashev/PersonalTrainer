#include "cclientdbmanager.h"

CClientDBManager::CClientDBManager(QObject *parent)
    : CAbstructDBManager(parent)
{
    initConnections();
}

CClientDBManager::~CClientDBManager()
{

}

void CClientDBManager::initConnections()
{

}
