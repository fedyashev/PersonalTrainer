#include "cabstructdbmanager.h"

CAbstructDBManager::CAbstructDBManager(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
}

CAbstructDBManager::~CAbstructDBManager()
{
    qDebug() << "CAbstructDBManager: destructor " << this;
}

void CAbstructDBManager::initConnections()
{

}

