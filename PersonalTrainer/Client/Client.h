#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = 0);

private:
    QTcpSocket socket;

signals:
    void showMessageDialog(const QString& msg);

public slots:
    void connectToServer(const QString& login, const QString& password);
    void connectionEstablished();
    void connectionError(const QAbstractSocket::SocketError err);
};

#endif // CLIENT_H
