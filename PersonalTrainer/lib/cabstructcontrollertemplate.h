#ifndef CABSTRUCTCONTROLLERTEMPLATE_H
#define CABSTRUCTCONTROLLERTEMPLATE_H

#include "CAbstructModelTemplate.h"

template <class T_M>
class CAbstructControllerTemplate
{

public:
    CAbstructControllerTemplate():
        m_model(new T_M())
    {

    }

    virtual ~CAbstructControllerTemplate()
    {
        delete m_model;
    }

    T_M *getModel() const
    {
        return m_model;
    }

private:
    T_M *m_model;
};

#endif // CABSTRUCTCONTROLLERTEMPLATE_H

