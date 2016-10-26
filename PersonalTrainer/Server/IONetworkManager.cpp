#include "IONetworkManager.h"

IONetworkManager::IONetworkManager(QTcpSocket *socket, QObject *parent) : QObject(parent), socket(socket)
{

}

void IONetworkManager::sendData(const QString& data)
{
    socket->write(data.toUtf8());
    socket->flush();
}

void IONetworkManager::recieveData()
{
    QByteArray data = socket->readAll();
    qDebug() << socket->socketDescriptor() << " " << data.data();
    emit recievedData(data);
}

void IONetworkManager::disconnected()
{
    qDebug() << "Disconnected";
    emit finish();
}
