#include "cabstructionetworkmanager.h"

/*!
 * \brief Коструктор.
 * \param[in] socket Указатель на объект сокета работы с сетью.
 * \param[in] parent Указатель на объект верхнего уровня иерархии объектов.
 */
CAbstructIONetworkManager::CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent) :
    CAbstructControllerItem(parent), m_socket(socket)
{
    initConnections();
}

/*!
 * \brief Деструктор
 */
CAbstructIONetworkManager::~CAbstructIONetworkManager()
{
    qDebug() << "CAbstructIONetworkManager: destructor " << this;
}

/*!
 * \brief Функиция-getter для сокета
 * \return Возвращает указатель на сокет
 */
QTcpSocket *CAbstructIONetworkManager::getSocket() const
{
    return m_socket;
}

/*!
 * \brief Слот приема данных по сети
 *
 * Создается объект raw_data класса QByteArray в который хранит данные переданные через сеть.
 * Считывание данных происходит через вызов метода readAll() у сокета.
 * Массив байт помещается в объект класса QString. Далее происходит генерация сигнала sendData().
 * В сигнал помещается объект класса QString, который содержит массив принятых байт по сети, который
 * передается внешнему объекту.
 */
void CAbstructIONetworkManager::recvDataFromSocket()
{
    QByteArray raw_data = m_socket->readAll();
    QString raw_string(raw_data.data());
    emit sendData(new QString(raw_string.toUtf8().data()));
}

/*!
 * \brief Слот передачи данных по сети
 * \param[in] data Объект содержащий передаваемую информацию
 *
 * Формируется char* строка из переданного в слок объекта QString.
 * Для передачи данных по сети из объекта сокета вызывается
 * метод write в который передается char* строка и размер этой строки.
 * Далее для ожидания передачи данных вызывается метод waitForBytesWritten()
 * и очищается буффер сокета.
 */
void CAbstructIONetworkManager::sendDataToSocket(QString* data)
{
    QByteArray byte_data = data->toUtf8();
    char* msg = byte_data.data();
    m_socket->write(msg, byte_data.size());
    m_socket->waitForBytesWritten(500);
    m_socket->flush();
}

/*!
 * \brief Инициализация подключений сигналов и слотов
 */
void CAbstructIONetworkManager::initConnections()
{
    /*!
     * Соединяем сигнал сокета readyRead() и слот CAbstructIONetworkManager::recvDataFromSocket().
     * Когда сокет генерирует сигнал readyRead(), т.е. сокету отправили из сети данные, которые он готов принять,
     * вызывется слот приема данных из сети
     */
    connect(m_socket, SIGNAL(readyRead()), SLOT(recvDataFromSocket()));

    /*!
     * \brief Соединяем сигнал CAbstructIONetworkManager::recvData(QString*) со слотом
     * CAbstructIONetworkManager::sendDataToSocket(QString*). Когда у объекта управляющего сетевым
     * взаимодействием генерируется сигнал recvData(QString*), т.е. внешний объект передает данные
     * в объект управления сетевым взаимодействием, то вызывается слот sendDataToSocket(QString*)
     * для отправки данных по сети.
     */
    connect(this, SIGNAL(recvData(QString*)), this, SLOT(sendDataToSocket(QString*)));

    /*!
     * \brief Соединяем сигнал QTcpSocket::disconnected() и сигнал CAbstructIONetworkManager::disconnected().
     * При разрыве сетевого подключения сокет генерирует сигнал disconnected(). Этот сигнал вызывает
     * генерацию сигнала disconnected() у объекта управляющего сетевым взаимодействием.
     */
    connect(m_socket, SIGNAL(disconnected()), SIGNAL(disconnected()));

    /*!
     * \brief Соединяем сигнал QTcpSocket::disconnected() и QTcpSocket::deleteLater().
     * Когда сокет сгенерировал сигнал disconnected(), то работа с сокетом считается завершенной
     * и объект сокета, соответствующего текущему подключению, считается больше не нужным, поэтому
     * объект сокета нужно включить в расписание на удаление объектов при помощи слота deleteLater().
     */
    connect(m_socket, SIGNAL(disconnected()), m_socket, SLOT(deleteLater()));
}
