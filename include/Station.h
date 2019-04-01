#ifndef STATION_H
#define STATION_H

#include <ostream>
#include "Point.h"


class Station
{
    public:
        Station(int name, int people, Point *point);
        Station(int name, int people, int newX, int newY);

        void setName(int newName);
        int getName();

        void setPeople(int newPeople);
        int getPeople();

        void setPoint(Point newPoint);
        void setPoint(int newX, int newY);
        Point getPoint();

    friend std::ostream &operator<<(std::ostream &os, const Station &station);
//     std::ostream &operator<<(std::ostream &os, const Station &station);

protected:

    private:
    int name;
    int people;
    Point point;
};

#endif // STATION_H
