#ifndef CSERVERDBMANAGER_H
#define CSERVERDBMANAGER_H

#include "cabstructdbmanager.h"
#include <QDebug>

class CServerDBManager : public CAbstructDBManager
{
    Q_OBJECT
public:
    CServerDBManager(QObject *parent = 0);
    ~CServerDBManager();

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CSERVERDBMANAGER_H
