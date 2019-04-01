#include "Station.h"
#include "Point.h"

Station::Station()
{

}

Station::Station(int name, int people, Point point)//())
{
    mName = name;
    mPeople = people;
    mPoint.setX( point.getX() );
    mPoint.setY( point.getY() );
}

Station::Station(int name, int people, int x, int y)
{
    mName = name;
    mPeople = people;
    mPoint.setX( x );
    mPoint.setY( y );
}

void Station::setName(int newName)
{
    mName = newName;
}

int Station::getName()
{
    return mName;
}

void Station::setPeople(int newPeople)
{
    mPeople = newPeople;
}

int Station::getPeople()
{
    return mPeople;
}

void Station::setPoint(Point newPoint)
{
    mPoint.setX( newPoint.getX() );
    mPoint.setY( newPoint.getY() );
}

void Station::setPoint(int newX, int newY)
{
    mPoint.setX( newX );
    mPoint.setY( newY );
}

Point Station::getPoint()
{
    return mPoint;
}
