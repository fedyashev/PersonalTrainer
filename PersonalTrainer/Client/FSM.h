#ifndef FSM_H
#define FSM_H

#include <QObject>
#include "Data.h"

class FSM : public QObject
{
    Q_OBJECT

public:
    explicit FSM(QObject *parent = 0);

signals:
    void sendData(const Data& data);

public slots:
    void fsm(const Data& data);

private:

};

enum FSM_State {
    authorization = 0,
    update
};

enum FSM_Signal {
    send = 0,
    recieve,
};

//typedef mptr (void (FSM::*)(void));

struct FSMData {
    FSM_State nextState;
    FSM_Signal nextSignal;
};

#endif // FSM_H
