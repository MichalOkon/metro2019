#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

#include "Point.h"

using namespace std;

class Station
{
    private:
        int mID;
        int mPeople;
        Point mPoint;
        char mName;
        vector <int> peopleToStation;

    public:
        Station();
        Station(int ID, char name, int people, Point point);
        Station(int ID, char name, int people, int newX, int newY);
        ~Station();

        int getID();

        void setName(char newName);
        char getName();

        void setPeople(int newPeople);
        int getPeople();

        void setPoint(Point newPoint);
        void setPoint(int newX, int newY);
        Point getPoint();

        void setPeopleToStation( vector<float>* );
        int getPeopleToStation(int);
        void modifyPeopleToStation(int, int);
        void updatePeople();

        void operator+=(int);
        void operator-=(int);
        int &operator[](int);

    protected:
};

//#include "Station.cpp"

#endif // STATION_H
