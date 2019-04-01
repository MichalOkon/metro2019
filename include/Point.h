#ifndef POINT_H
#define POINT_H
//#include "Point.cpp"

#include <ostream>

class Point
{
    public:
        Point();
        Point(int x, int y);

        void setX(int newX);
        int getX();

        void setY(int newY);
        int getY();

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    protected:

    private:
    int x;
    int y;
};

#endif // POINT_H
