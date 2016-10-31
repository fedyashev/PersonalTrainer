#ifndef CABSTRUCTMODELTEMPLATE_H
#define CABSTRUCTMODELTEMPLATE_H

template <class T_NET, class T_FSM, class T_DBM>
class CAbstructModelTemplate
{

public:
    CAbstructModelTemplate():
        m_net(new T_NET()), m_fsm(new T_FSM()), m_dbm(new T_DBM())
    {

    }

    virtual ~CAbstructModelTemplate()
    {
        delete m_net;
        delete m_fsm;
        delete m_dbm;
    }

    virtual void initConnections() = 0;

    T_NET *getIONetworkManager() const
    {
        return m_net;
    }

    T_FSM *getFSM() const
    {
        return m_fsm;
    }

    T_DBM *getDBManager() const
    {
        return m_dbm;
    }

private:
    T_NET *m_net;
    T_FSM *m_fsm;
    T_DBM *m_dbm;
};

#endif // CABSTRUCTMODELTEMPLATE_H

