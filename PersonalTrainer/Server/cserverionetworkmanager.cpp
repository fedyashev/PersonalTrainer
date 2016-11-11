#include "cserverionetworkmanager.h"

/*!
 * \brief Конструктор.
 * \param[in] socket Указатель на сокет подключенного к серверу клиента.
 * \param[in] parent Указатель на объект верхнего уровня в иерархии объектов.
 *
 * В конструкторе вызывается метод initConnections() инициализации соединений
 * сигналов и слотов.
 */
CServerIONetworkManager::CServerIONetworkManager(QTcpSocket *socket, QObject *parent) :
    CAbstructIONetworkManager(socket, parent)
{
    initConnections();
}

/*!
 * \brief Деструктор.
 */
CServerIONetworkManager::~CServerIONetworkManager()
{
    qDebug() << "CServerIONetworkManager: destructor " << this;
}

/*!
 * \brief Метод инициализации сигналов и слотов.
 */
void CServerIONetworkManager::initConnections()
{
    /*!
     * \brief Сигнал socket'a errorPrint() соединяется со слотом CServerIONetworManager::errorPrint().
     * Если сокет генерирует сигнал об ошибке, то слот объекта работы с сетью выводит ошибку с консоль.
     */
    connect(getSocket(), SIGNAL(error(QAbstractSocket::SocketError)), SLOT(errorPrint(QAbstractSocket::SocketError)));
}

/*!
 * \brief Слот вывода в консоль ошибок работы сокета.
 */
void CServerIONetworkManager::errorPrint(QAbstractSocket::SocketError)
{
    qDebug() << getSocket()->errorString();
}

