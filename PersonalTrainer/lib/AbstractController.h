#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include "Data.h"
#include "Model.h"

class AbstractController : public QObject
{
Q_OBJECT

public:
    explicit AbstractController(QTcpSocket *socket, QThread *thread = 0, QObject *parent = 0);

protected:
    virtual void initConnections() = 0;

private:
    QThread *thread;
    Model *model;

signals:
    void sendDataToModel(const Data& data);

public slots:
    void recieveDataFromModel(const Data& data);

};

#endif // ABSTRACTCONTROLLER_H
