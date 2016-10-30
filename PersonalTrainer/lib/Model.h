#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTcpSocket>
#include "Data.h"
#include "IONetworkManager.h"
#include "DBManager.h"
#include "FSM.h"

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QTcpSocket *socket, QObject *parent = 0);

    IONetworkManager *getNet() const;
    DBManager *getDB() const;
    FSM *getFSM() const;

private:
    IONetworkManager *net;
    DBManager *db;
    FSM *fsm;
    QTcpSocket *socket;

signals:
    void sendDataToAbstructController(const Data& data);

public slots:
    void recieveDataFromAbstructController(const Data& data);
    void createModel();
};

#endif // MODEL_H
