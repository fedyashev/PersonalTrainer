#include "cabstructfsm.h"

/*!
 * \brief CAbstructFSM::CAbstructFSM
 * \param parent
 *
 * В конструкторе вызывается метод initConnections();
 */
CAbstructFSM::CAbstructFSM(QObject *parent) :
    CAbstructControllerItem(parent)
{
    initConnections();
}

/*!
 * \brief CAbstructFSM::~CAbstructFSM
 */
CAbstructFSM::~CAbstructFSM()
{
    qDebug() << "CAbsrtuctFSM: destructor " << this;
}

/*!
 * \brief Базовый функционал конечного автомата.
 * \param data
 * Принимаемые данные
 */
void CAbstructFSM::fsm(QString* data)
{
    qDebug() << *data;
    emit sendDataToIONetworkManager(new QString(*data));
    delete data;
}

/*!
 * \brief Реализация виртуального метода базового класса.
 * Устанавливает связь между принимаемыми данными от сигнала recvData()
 * и слотом fsm()
 */
void CAbstructFSM::initConnections()
{
    connect(this, SIGNAL(recvData(QString*)), SLOT(fsm(QString*)));
}

