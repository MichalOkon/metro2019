#include <iostream>
#ifndef AREA_H
#define AREA_H
#include "Point.cpp"
class Area {
    private:

        Point * mCity;
        int mTemple;
        // int subwayLine[];

    public:

        // Getters and Setters
        Point* GetCity();
        void SetCity(Point * city);
        int GetTemple();
        void SetTemple(int temple);
        // int[] GetSubwayLine();
        // void SetSubwayLine(int line[]);

        // Finally useful methods
        void Day();
        void display();

        // Constructors and Destructors
        Area(Point*, int);
        Area();
        ~Area();
};

#endif // AREA_H

