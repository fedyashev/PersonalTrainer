#include "cabstructcontrolleritem.h"

/*!
 * \brief Коструктор
 * \param parent
 * Указатель на корневой (родительский) объект в структуре иерархии объектов
 */
CAbstructControllerItem::CAbstructControllerItem(QObject *parent) : QObject(parent)
{

}

/*!
 * \brief Виртуальный деструктор
 */
CAbstructControllerItem::~CAbstructControllerItem()
{
    qDebug() << "CAbstructControllerItem: destructor " << this;
}
