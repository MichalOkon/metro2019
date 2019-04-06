#ifndef STATION_H
#define STATION_H

#include "Point.cpp"

class Station
{
    private:

    public:
        int mName;
        int mPeople;
        Point mPoint;


        Station();
        Station(int name, int people, Point point);//());
        Station(int name, int people, int newX, int newY);

        void setName(int newName);
        int getName();

        void setPeople(int newPeople);
        int getPeople();

        void setPoint(Point newPoint);
        void setPoint(int newX, int newY);
        Point getPoint();

        Station operator<<(Station &obj);

    protected:
};

//#include "Station.cpp"

#endif // STATION_H
