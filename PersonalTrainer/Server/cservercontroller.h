#ifndef CSERVERCONTROLLER_H
#define CSERVERCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include "cserverionetworkmanager.h"
#include "cserverdbmanager.h"
#include "cserverfsm.h"

/*!
 * \brief Контроллер управления работой подключенного к серверу клиента.
 */
class CServerController : public QObject
{
    Q_OBJECT
public:
    explicit CServerController(QTcpSocket *socket, QObject *parent = 0);
    ~CServerController();

    CServerIONetworkManager *getIONetworkManager() const;
    CServerFSM *getFSM() const;
    CServerDBManager *getDBManager() const;

    void initConnections() const;

private:
    CServerIONetworkManager *m_net; ///< Указатель на объект работы с сетью.
    CServerFSM *m_fsm; ///< Указатель на объект конечного автомата.
    CServerDBManager *m_dbm; ///< Указатель на объект работы с базой данных.
    QThread *m_thread; ///< Указетель на объект потока.

signals:
    void finishWork(); ///< Сигнал завершения работы контроллера.
};

#endif // CSERVERCONTROLLER_H
