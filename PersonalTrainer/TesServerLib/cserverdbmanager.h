#ifndef CSERVERDBMANAGER_H
#define CSERVERDBMANAGER_H

#include "cabstructdbmanager.h"


class CServerDBManager : public CAbstructDBManager
{
    Q_OBJECT
public:
    CServerDBManager(QObject *parent = 0);

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CSERVERDBMANAGER_H
