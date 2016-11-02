#ifndef CABSTRUCTDBMANAGER_H
#define CABSTRUCTDBMANAGER_H

#include <QObject>
#include "cabstructcontrolleritem.h"

class CAbstructDBManager : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructDBManager(QObject *parent = 0);

signals:

public slots:

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTDBMANAGER_H
