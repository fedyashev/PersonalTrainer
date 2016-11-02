#ifndef CABSTRUCTCONTROLLERITEM_H
#define CABSTRUCTCONTROLLERITEM_H

#include <QObject>
#include <cstring>

class CAbstructControllerItem : public QObject
{
    Q_OBJECT
public:
    explicit CAbstructControllerItem(QObject *parent = 0);

protected:
    virtual void initConnections() = 0;

signals:
    void sendData(const QString &data);
    void recvData(const QString &data);
};

#endif // CABSTRUCTCONTROLLERITEM_H
