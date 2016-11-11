#include "cserverfsm.h"

/*!
 * \brief Конструктор.
 * \param[in] parent Указатель на объект верхнего уровня иерархии объектов.
 *
 * В конструкторе вызывается метод initConnections() инициализации соединений сигналов и слотов.
 */
CServerFSM::CServerFSM(QObject *parent) :
    CAbstructFSM(parent)
{
    initConnections();
}

/*!
 * \brief Деструктор.
 */
CServerFSM::~CServerFSM()
{
    qDebug() << "CServerFSM: destructor " << this;
}

/*!
 * \brief Метод инициализации соединений сигналов и слотов.
 */
void CServerFSM::initConnections()
{

}
