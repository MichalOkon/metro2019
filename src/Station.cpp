#include "Station.h"
#include "Point.h"



Station::Station(int name, int people, Point point)
{
    this->name = name;
    this->people = people;
    this->point.setX( point.getX() );
    this->point.setY( point.getY() );
}

Station::Station(int name, int people, int x, int y)
{
    this->name = name;
    this->people = people;
    this->point.setX( x );
    this->point.setY( y );
}

void Station::setName(int newName)
{
    name = newName;
}

int Station::getName()
{
    return name;
}

void Station::setPeople(int newPeople)
{
    people = newPeople;
}

int Station::getPeople()
{
    return people;
}

void Station::setPoint(Point newPoint)
{
    this->point.setX( newPoint.getX() );
    this->point.setY( newPoint.getY() );
}

void Station::setPoint(int newX, int newY)
{
    this->point.setX( newX );
    this->point.setY( newY );
}

Point Station::getPoint()
{
    return point;
}
