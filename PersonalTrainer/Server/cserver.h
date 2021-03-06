#ifndef CSERVER_H
#define CSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "cservercontroller.h"

/*!
 * \brief Сервер
 */
class CServer : public QObject
{
    Q_OBJECT
public:
    explicit CServer(QObject *parent = 0);
    ~CServer();

    void initConnections();

    QTcpServer *getServer() const;

private:
    QTcpServer *m_server; ///< Указатель на объект сервера.

signals:

public slots:
    void newConnection();
    void startServer();
};

#endif // CSERVER_H
