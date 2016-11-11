#ifndef CABSTRUCTIONETWORKMANAGER_H
#define CABSTRUCTIONETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "cabstructcontrolleritem.h"

/*!
 * \brief Базовый класс передачи и приема данных по сети.
 */
class CAbstructIONetworkManager : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructIONetworkManager(QTcpSocket *socket, QObject *parent = 0);
    virtual ~CAbstructIONetworkManager();

    QTcpSocket *getSocket() const;

private:
    QTcpSocket *m_socket; ///< Сокет

signals:
    /// Сигнал генерируется когда сокет генерирует сигнал disconected()
    void disconnected();

public slots:
    void recvDataFromSocket();
    void sendDataToSocket(QString* data);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTIONETWORKMANAGER_H
