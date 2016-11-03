#include "cabstructcontrolleritem.h"

CAbstructControllerItem::CAbstructControllerItem(QObject *parent) : QObject(parent)
{

}

CAbstructControllerItem::~CAbstructControllerItem()
{
    qDebug() << "CAbstructControllerItem: destructor " << this;
}

