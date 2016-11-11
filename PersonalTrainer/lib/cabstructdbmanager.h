#ifndef CABSTRUCTDBMANAGER_H
#define CABSTRUCTDBMANAGER_H

#include <QObject>
#include <QDebug>
#include "cabstructcontrolleritem.h"

/*!
 * \brief Базовый класс задает базовый функционал работы с базой данных.
 */
class CAbstructDBManager : public CAbstructControllerItem
{
    Q_OBJECT
public:
    explicit CAbstructDBManager(QObject *parent = 0);
    virtual ~CAbstructDBManager();

signals:

public slots:

    // CAbstructControllerItem interface
protected:
    void initConnections();
};

#endif // CABSTRUCTDBMANAGER_H
