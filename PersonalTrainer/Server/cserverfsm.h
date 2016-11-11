#ifndef CSERVERFSM_H
#define CSERVERFSM_H

#include <QDebug>
#include "../lib/cabstructfsm.h"

/*!
 * \brief Класс работы с конечным автоматом сервера.
 */
class CServerFSM : public CAbstructFSM
{
    Q_OBJECT
public:
    CServerFSM(QObject *parent = 0);
    ~CServerFSM();

signals:

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CSERVERFSM_H
