#ifndef CABSTRUCTCONTROLLERTEMPLATE_H
#define CABSTRUCTCONTROLLERTEMPLATE_H

#include "CAbstructModelTemplate.h"

template <class T_M>
class CAbstructControllerTemplate
{

public:
    CAbstructControllerTemplate():
        m_model(new CAbstructModelTemplate())
    {

    }

    virtual ~CAbstructControllerTemplate()
    {
        delete m_model;
    }

    virtual void initConnections() = 0;

    T_M *getModel() const
    {
        return m_model;
    }

private:
    T_M *m_model;
};

#endif // CABSTRUCTCONTROLLERTEMPLATE_H

