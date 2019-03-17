#ifndef POINT_H
#define POINT_H
//#include "Point.cpp"

class Point
{
    public:
        Point(int x, int y);

        void setX(int newX);
        int getX();

        void setY(int newY);
        int getY();

    protected:

    private:
    int x;
    int y;
};

#endif // POINT_H
