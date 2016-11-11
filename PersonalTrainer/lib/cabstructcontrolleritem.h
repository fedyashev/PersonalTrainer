#ifndef CABSTRUCTCONTROLLERITEM_H
#define CABSTRUCTCONTROLLERITEM_H

#include <QObject>
#include <QDebug>
#include <cstring>

/*!
 * \brief Абстрактный класс задает интерфейс для взаимодействия объектов контроллера.
 *
 * Класс задает интерфейс взаимодействия объектов контроллера
 * при помощи сигналов sendData() и recvData(). Класс содержит
 * чисто виртуальный метод initConnect() для инициализации
 * сигналов и слотов в классах наследниках.
 * В классах наследниках для передачи данных внешним объектам
 * необходимо использовать сигнал sendData(), а для приема данных
 * от внешних объектов необходимо использовать сигнал recvData().
 */
class CAbstructControllerItem : public QObject
{
    Q_OBJECT
public:
    explicit CAbstructControllerItem(QObject *parent = 0);
    virtual ~CAbstructControllerItem();

protected:
    /// Чисто виртуальный метод необходим для инициализации сигналов и слотов d классах наследниках.
    virtual void initConnections() = 0;

signals:
    /// Сигнал передачи данных внешним объектам.
    void sendData(QString*);

    /// Сигнал приема данных от внешнего объекта.
    void recvData(QString*);
};

#endif // CABSTRUCTCONTROLLERITEM_H
