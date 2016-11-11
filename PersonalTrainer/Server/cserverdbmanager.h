#ifndef CSERVERDBMANAGER_H
#define CSERVERDBMANAGER_H

#include <QDebug>
#include "../lib/cabstructdbmanager.h"

/*!
 * \brief Класс работы с базой данных на сервере
 */
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
