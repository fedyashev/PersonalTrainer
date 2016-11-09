#ifndef CABSTRUCTCONTROLLERITEM_H
#define CABSTRUCTCONTROLLERITEM_H

#include <QObject>
#include <QDebug>
#include <cstring>

class CAbstructControllerItem : public QObject
{
    Q_OBJECT
public:
    explicit CAbstructControllerItem(QObject *parent = 0);
    virtual ~CAbstructControllerItem();

protected:
    virtual void initConnections() = 0;

signals:
    void sendData(QString*);
    void recvData(QString*);
};

#endif // CABSTRUCTCONTROLLERITEM_H
