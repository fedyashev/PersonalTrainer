#include "cabstructdbmanager.h"

/*!
 * \brief CAbstructDBManager
 * \param parent
 */
CAbstructDBManager::CAbstructDBManager(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
}

/*!
 * \brief ~CAbstructDBManager
 */
CAbstructDBManager::~CAbstructDBManager()
{
    qDebug() << "CAbstructDBManager: destructor " << this;
}

/*!
 * \brief Реализация виртуального метода базового класса.
 */
void CAbstructDBManager::initConnections()
{

}

