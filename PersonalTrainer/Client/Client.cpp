#include "Client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    socket.close();
    connect(&socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectionError(QAbstractSocket::SocketError)));
}

void Client::connectToServer(const QString &login, const QString &password)
{
    socket.connectToHost("192.168.1.100", 52816);
}

void Client::connectionEstablished()
{
    emit showMessageDialog("Connection established.");
    socket.disconnectFromHost();
}

void Client::connectionError(const QAbstractSocket::SocketError err)
{
    emit showMessageDialog(socket.errorString());
    socket.disconnectFromHost();
}

