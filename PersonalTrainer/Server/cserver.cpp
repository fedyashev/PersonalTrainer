#include "cserver.h"

/*!
 * \brief Конструктор
 * \param[in] parent Указатель на объект верхнего уровня иерархии объектов.
 *
 * В конструкторе вызывается метод initConnection() который инициализирует соединения
 * сигналов и слотов.
 */
CServer::CServer(QObject *parent) :
    QObject(parent), m_server(new QTcpServer())
{
    initConnections();
    startServer();
}

/*!
 * \brief Деструктор.
 */
CServer::~CServer()
{
    qDebug() << "CServer: destructor " << this;
}

/*!
 * \brief Метод инициализации соединения сигналов и слотов.
 */
void CServer::initConnections()
{
    /*!
     * \brief Соединяем сигнал QTcpServer::newConnection() и слот CServer::newConnection().
     * Когда к серверу подключается новый клиент объет класса QTcpServer генерирует сигнал
     * newConnection(). Этот сигнал подключаем к слоту CServer::newConnection(), таким образом,
     * при подключении нового клиента вызывается слот CServer::newConnection().
     */
    connect(m_server, SIGNAL(newConnection()), SLOT(newConnection()));
}

/*!
 * \brief Метод-getter указателя на объект сервера.
 * \return Возвращыет указатель на объект сервера.
 */
QTcpServer *CServer::getServer() const
{
    return m_server;
}

/*!
 * \brief Слот обработки для сигнала QTcpServer::newConnection().
 *
 * При подключении клиента к серверу создается объект класса QTcpSocket.
 * Далее создается контроллер работы с клиентом - объект класса CServerController,
 * в который передается указетль на созданный сокет для данного подключения и указатель
 * на объект верхнего уровня иерархии объектов. Также, инициализируется соединение сигнала
 * CServerController::finishWork() и слота CServerController::deleteLater().
 * Когда контроллер завершил работу всех в включенных в него объектов, завершил работу отдельного
 * потока и включил объекты в расписание на удаление, то сервер включает контроллер в расписание
 * на удаление.
 */
void CServer::newConnection()
{
    QTcpSocket *socket = m_server->nextPendingConnection();
    CServerController *controller = new CServerController(socket, this);
    connect(controller, SIGNAL(finishWork()), controller, SLOT(deleteLater()));
    qDebug() << "Client connected. SC: " << socket->socketDescriptor();
}

/*!
 * \brief Слот запуска сервера.
 *
 * Сервер запускает прослушивание порта 52816 на всех сетевых интерфейсах подключенных
 * к хосту. Если успешно установлено прослушивание порта 52816 по всем сетевым интерфейсам,
 * то в консоль выводиться сообщение о успешном запуске сервера, иначе выводиться сообщение
 * о невозможности запуска сервера.
 */
void CServer::startServer()
{
    if (m_server->listen(QHostAddress::Any,52816))
    {
        qDebug() << "Server started: success.";
    } else
    {
        qDebug() << "Server started: faild.";
    }
}

