#include "Station.h"
#include <string>
#include <iostream>

using namespace std;

Station::Station()
{

}

Station::Station(int id, char name, int people, Point point)//())
{
    mID = id;
    mName = name;
    mPeople = people;
    mPoint = point;
}

Station::Station(int id, char name, int people, int x, int y)
{
    mID = id;
    mName = name;
    mPeople = people;
    mPoint = Point(x,y);
}

Station::~Station()
{
    peopleToStation.clear();
}

void Station::operator+=(int add)
{
    mPeople += add;
}

void Station::operator-=(int take)
{
    mPeople -= take;
}

int Station::getID()
{
    return mID;
}

void Station::setName(char newName)
{
    mName = newName;
}

char Station::getName()
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

void Station::setPeopleToStation( vector <float>* v )
{
    for(int i=0; i < (*v).size(); ++i)
    {
        peopleToStation.push_back( mPeople * (*v)[i] );
    }
}

int Station::getPeopleToStation(int id)
{
    return peopleToStation[id];
}

int &Station::operator[](int id)
{
    return peopleToStation[id];
}

void Station::modifyPeopleToStation(int id, int val)
{
    peopleToStation[id] += val;
}

void Station::updatePeople()
{
    mPeople = 0;
    for(int i=0; i<peopleToStation.size(); ++i)
        mPeople += peopleToStation[i];
}