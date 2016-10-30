#include "Model.h"

Model::Model(QTcpSocket *socket, QObject *parent) :
    QObject(parent), socket(socket), net(0), db(0), fsm(0)
{

}

IONetworkManager *Model::getNet() const
{
    return net;
}

DBManager *Model::getDB() const
{
    return db;
}

FSM *Model::getFSM() const
{
    return fsm;
}

void Model::recieveDataFromAbstructController(const Data &data)
{

}

void Model::createModel()
{
    net = new IONetworkManager(socket, this);
    db = new DBManager(this);
    fsm = new FSM(this);
}
