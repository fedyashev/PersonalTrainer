#include "cserverdbmanager.h"

/*!
 * \brief Конструктор.
 * \param[in] parent Указатель на объект верхнего уровня иерархии объектов.
 *
 * В конструкторе вызывается метод initConnections() для соединения сигналов и слотов.
 */
CServerDBManager::CServerDBManager(QObject *parent) :
    CAbstructDBManager(parent)
{
    initConnections();
}

/*!
 * \brief Деструктор.
 */
CServerDBManager::~CServerDBManager()
{
    qDebug() << "CServerDBManager: destructor " << this;
}

/*!
 * \brief Метод соединения сигналов и слотов.
 */
void CServerDBManager::initConnections()
{

}

