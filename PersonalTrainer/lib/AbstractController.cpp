#include "AbstractController.h"

AbstractController::AbstractController(QTcpSocket *socket, QThread *thread, QObject *parent) :
    QObject(parent), thread(thread), model(0)
{
    model = new Model(socket);

    initConnections();

    if (thread) {
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(thread, SIGNAL(started()), model, SLOT(createModel()));

        socket->setParent(NULL);
        socket->moveToThread(thread);
        model->moveToThread(thread);

        thread->start();
    } else {
        model->createModel();
    }
}

void AbstractController::initConnections()
{

}

void AbstractController::recieveDataFromModel(const Data &data)
{

}
