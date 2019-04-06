#ifndef STRETCH_H
#define STRETCH_H

#include "Station.h"

class stretch
{
    public:
        stretch();
        stretch(int id, int pass, Station from, Station to); //nazwa, przepustowosc i skad dokad
        virtual ~stretch();

        int Getid();
        void Setid(int val);
        int Getpass();
        void Setpass(int val);
        Station Getfrom();
        void Setfrom(Station val);
        Station Getto(int fromm);
        void Setto(Station val);

    protected:

    private:
        int m_id;
        //maximum number of passengers transported at the same time
        int m_pass; //przepustowosc
        Station m_from;
        Station m_to;
};

#endif // STRETCH_H
