#ifndef STRETCH_H
#define STRETCH_H

#include <ostream>
#include "Station.h"

class Stretch
{
public:
    Stretch();
    Stretch(int id, int pass, Station from, Station to); //nazwa, przepustowosc i skad dokad
    ~Stretch();

    int getId();
    void setId(int val);
    int getPass();
    void setPass(int val);
    Station getFrom();
    Station getTo();
    void setFrom(Station val);
    Station getToorFrom(int fromm = 0);
    void setTo(Station val);
    int getTime();

    friend ostream &operator<<(ostream &os, const Stretch &stretch);
    // float ???????

protected:

private:
    int mId;
    //maximum number of passengers transported at the same time
    int mPass; //przepustowosc
    int mTime; //czas podrozy -> odleglosc miedzy stacja mFrom i mTo; int czy float??????
    Station mFrom;
    Station mTo;
};

#endif // STRETCH_H
