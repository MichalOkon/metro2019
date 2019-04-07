#ifndef STRETCH_H
#define STRETCH_H

#include "Station.cpp"

class stretch
{
    private:
        int m_id;
        //maximum number of passengers transported at the same time
        int m_pass;
        Station m_from;
        Station m_to;

    public:
        stretch();
        stretch(int id, int pass, Station from, Station to)
        {
            m_id = id;
            m_pass = pass;
            m_from = from;
            m_to = to;
        };
        virtual ~stretch();

        int Getid() { return m_id; }
        void Setid(int val) { m_id = val; }
        int Getpass() { return m_pass; }
        void Setpass(int val) { m_pass = val; }
        Station Getfrom() { return m_from; }
        void Setfrom(Station val) { m_from = val; }
        Station Getto( int fromm )
        {
            if(m_from.mName == fromm)
                return m_to;
            else if(m_to.mName == fromm)
                return m_from;
        }
        void Setto(Station val) { m_to = val; }

    protected:
};

#endif // STRETCH_H
