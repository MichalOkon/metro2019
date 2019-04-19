#include "stretch.h"

stretch::stretch()
{
}

stretch::stretch(int id, int pass, Station from, Station to)
{
    m_id = id;
    m_pass = pass;
    m_from = from;
    m_to = to;
};

stretch::~stretch()
{
}

int stretch::Getid()
{
    return m_id;
}

void stretch::Setid(int val)
{
    m_id = val;
}

int stretch::Getpass()
{
    return m_pass;
}

void stretch::Setpass(int val)
{
    m_pass = val;
}

Station stretch::Getfrom()
{
    return m_from;
}

void stretch::Setfrom(Station val)
{
    m_from = val;
}

Station stretch::Getto(int fromm)
{
    if(m_from.mName == fromm)
        return m_to;
    else if(m_to.mName == fromm)
        return m_from;
    else
        return m_to;
}

void stretch::Setto(Station val)
{
    m_to = val;
}
