#include <iostream>
#include <vector>
#include <fstream>
#include <array>

#ifndef AREA_H
#define AREA_H
#include "Station.h"
#define INF 1000000000 //10^9
#define SIZE 10 //domyslny rozmiar boku mapy

using namespace std;

class Area {
    private:
        array < array <int, 100>, 100> pop;
        int** mPopulation;
        int mSumOfPeople = 0;
        int mSize = SIZE;
        int mTemple = 0;

    public:

        // Getters and Setters
        int getTemple();
        void setTemple(int temple);
        int getSumOfPeople();
        int** getPopulation();

        // Finally useful methods
        // Constructors and Destructors
        Area(int); //int size
        Area();
        ~Area();

        void generatePopulation();
        void populationToStation( vector <Station*> );
        int &operator[](Point); //zwraca mPopulation[point.X][point.Y]
};

#endif // AREA_H

