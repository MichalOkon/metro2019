#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include <ostream>

#include "Point.h"

using namespace std;

class Station
{
    private:
        int mID;
        int mPeople;
        Point mPoint;
        string mName;
        vector <int> peopleToStation; //peopleToStation[i] zwraca ile ludzi chce z tej stacji do stacji 'i'

    public:
        Station();
        Station(int ID, string name, int people, Point point);
        Station(int ID, string name, int people, int newX, int newY);
        Station(Station *s);
        ~Station();

        int getID();

        void setName(char newName);
        string getName();

        void setPeople(int newPeople);
        int getPeople();

        void setPoint(Point newPoint);
        void setPoint(int newX, int newY);
        Point getPoint();

        void setPeopleToStation( vector<float>* );
        int getPeopleToStation(int);
        void modifyPeopleToStation(int, int);
        void updatePeople();

        void operator+=(int); //zwieksza mPeople o int
        void operator-=(int); //zmniejsza mPeople o int
        int &operator[](int);

    friend ostream &operator<<(ostream &os, const Station &station);
    //zwraca peopleToStation[ int ]

    protected:
};

//#include "Station.cpp"

#endif // STATION_H
