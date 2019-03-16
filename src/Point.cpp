#include "Point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getX()
{
    return x;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getY()
{
    return y;
}
