#include "stretch.h"

stretch::stretch()
{
}

strech::stretch(int id, int pass; station from; station to)
{
    m_id = id;
    m_pass = pass;
    m_from = from;
    m_to = to;
};

stretch::~stretch()
{
}

int Getid()
{
    return m_id;
}
void Setid(int val)
{
    m_id = val;
}
int Getpass()
{
    return m_pass;
}
void Setpass(int val)
{
    m_pass = val;
}
station Getfrom()
{
    return m_from;
}
void Setfrom(station val)
{
    m_from = val;
}
station Getto()
{
    return m_to;
}
void Setto(station val)
{
    m_to = val;
}
