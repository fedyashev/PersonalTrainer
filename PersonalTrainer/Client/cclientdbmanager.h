#ifndef CCLIENTDBMANAGER_H
#define CCLIENTDBMANAGER_H

#include <Qobject>
#include "../lib/cabstructdbmanager.h"

class CClientDBManager : public CAbstructDBManager
{
    Q_OBJECT
public:
    explicit CClientDBManager(QObject *parent = 0);
    virtual ~CClientDBManager();

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CCLIENTDBMANAGER_H
