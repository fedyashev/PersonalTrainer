#include "cservercontroller.h"

/*!
 * \brief Конструктор
 * \param[in] socket Указатель на сокет подключенного к серверу клиента.
 * \param[in] parent Указатель на объект верхнего уровня иерархии объектов.
 *
 * В конструкторе динамически создаются объектся классов CServerIONetworkManager,
 * CServerFSM, CServerDBManager, QThread. Далее вызывается метод initConnection()
 * инициализирующий соединения сигналов и сокетов для созданных объектов.
 * Затем созданные объекты перемещаются в отдельный поток (кроме объекта класса QThread,
 * т.к. этот объект является обверткой для системного потока). Так как, перемещать
 * в отдельный поток можно только объекты верхнего уровня иерархии,
 * то перед перемещением в отдельный поток для объекта socket необходимо вызвать
 * метод setParent(NULL). Затем вызывается слот start() у объект потока, который
 * запускает отдельный поток, в котором находятся перемещенные в поток объекты,
 * и запускается механизм обработки событий.
 */
CServerController::CServerController(QTcpSocket *socket, QObject *parent) :
    QObject(parent),
    m_net(0),
    m_fsm(0),
    m_dbm(0),
    m_thread(0)
{
    m_net = new CServerIONetworkManager(socket);
    m_fsm = new CServerFSM();
    m_dbm = new CServerDBManager();
    m_thread = new QThread();

    initConnections();

    socket->setParent(NULL);
    socket->moveToThread(m_thread);
    m_net->moveToThread(m_thread);
    m_fsm->moveToThread(m_thread);
    m_dbm->moveToThread(m_thread);
    m_thread->start();
}

/*!
 * \brief Деструктор
 */
CServerController::~CServerController()
{
    qDebug() << "CServerController: destructor " << this;
}

/*!
 * \brief Метод-getter для объекта работы с сетью.
 * \return Возвращает указатель на объект работы с сетью.
 */
CServerIONetworkManager *CServerController::getIONetworkManager() const
{
    return m_net;
}

/*!
 * \brief Метод-getter для объекта конечного автомата.
 * \return Возвращает указатель на объект конечного автомата.
 */
CServerFSM *CServerController::getFSM() const
{
    return m_fsm;
}

/*!
 * \brief Метод-getter для объекта работы с базой данных
 * \return Возвращает указатель на объек работы с базой данных.
 */
CServerDBManager *CServerController::getDBManager() const
{
    return m_dbm;
}

/*!
 * \brief Метод инициализации соединнений сигналов и слотов.
 */
void CServerController::initConnections() const
{
    /*!
     * \brief Сигнал CServerIONetworkManager::sendData() соединяется с сигналом CServerFSM::recvData().
     * Данные отправленные от объекта m_net работы с сетью по сигналу sendData()
     * передаются в сигнал recvData() объекта m_fsm конечного автомата. Т.е. данные которые принял
     * socket из сети помещаются в сигнал sendData() объекта работы с сетью, а объект m_fsm
     * конечного автомата принимает их через сигнал recvData().
     */
    connect(m_net, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));

    /*!
     * \brief Сигналы CServerDBManager::sendData() соединяется с сигналом CServerFSM::recvData().
     * Данные отправленные объектом m_dbm работы с базой данных помещаются в сигнал recvData()
     * объекта m_fsm конечного автомата.
     */
    connect(m_dbm, SIGNAL(sendData(QString*)), m_fsm, SIGNAL(recvData(QString*)));

    /*!
     * \brief Сигнал CServerFSM::sendDataToIONetworkManager() соединяется c сигналом
     * CServerIONetworkManager::recvData(). Объект m_fsm помещает данные в сигнал
     * sendDataToIONetworkManager(QString*) и передает их в сигнал recvData(QString*)
     * объекта m_net, такием образом происходит передача данных в объект работы с сетью
     * для оправки данных по сети.
     */
    connect(m_fsm, SIGNAL(sendDataToIONetworkManager(QString*)), m_net, SIGNAL(recvData(QString*)));

    /*!
     * \brief Сигнал CServerFSM::sendDataToDBManager() соединяется с сигналом CServerDBManager::recvData().
     * Конечный автомат передает запрос в объект работы с базой данных.
     */
    connect(m_fsm, SIGNAL(sendDataToDBManager(QString*)), m_dbm, SIGNAL(recvData(QString*)));

    /*!
     * \brief Сигнал CServerIONetworkManager::disconnected() соединяется cо слотом
     * CServerIONetworkManager::deleteLater(). При отключении от сети объект m_net
     * включается в расписание на удаление объектов.
     */
    connect(m_net, SIGNAL(disconnected()), m_net, SLOT(deleteLater()));

    /*!
     * \brief Сигнал CServerIONetworkManager::disconnected() соединяется cо слотом
     * CServerFSM::deleteLater(). При отключении от сети объект m_fsm
     * включается в расписание на удаление объектов.
     */
    connect(m_net, SIGNAL(disconnected()), m_fsm, SLOT(deleteLater()));

    /*!
     * \brief Сигнал CServerIONetworkManager::disconnected() соединяется cо слотом
     * CServerDBManager::deleteLater(). При отключении от сети объект m_dbm
     * включается в расписание на удаление объектов.
     */
    connect(m_net, SIGNAL(disconnected()), m_dbm, SLOT(deleteLater()));

    /*!
     * \brief Сигнал CServerIONetworkManager::disconnected() соединяется cо слотом
     * QThread::quit(). При отключении от сети объект m_thread завершает работу
     * отдельного потока.
     */
    connect(m_net, SIGNAL(disconnected()), m_thread, SLOT(quit()));

    /*!
     * \brief Сигнал QThread::finished() соединяется со слотом QThread::deleteLater().
     * Когда поток завершил свою работу он генерирует сигнал finished()
     * и соответственно объект потока может быть включен в расписание на удаление.
     */
    connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));

    /*!
     * \brief Сигнал QThread::finished() соединяется с сигналом CServerController::finishWork().
     * Когда объект потока генерирует сигнал finished(), т.е. поток завершил свою работу,
     * контроллер генерирует сигнал finishWork(), что в свою очередь говорит о том что контроллер
     * завершил свою работу. Сигнал finishWork() перехватывает сервер и включет объект контроллера
     * в расписание на удаление.
     */
    connect(m_thread, SIGNAL(finished()), SIGNAL(finishWork()));
}
