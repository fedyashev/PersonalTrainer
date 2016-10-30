#ifndef DATA_H
#define DATA_H

#include <QObject>

class Data : public QObject
{
Q_OBJECT

public:
    explicit Data(QString content, QObject *parent = 0);

    QString content;

signals:

public slots:

};

#endif // DATA_H
