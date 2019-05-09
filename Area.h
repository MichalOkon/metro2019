#ifndef AREA_H
#define AREA_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Station.h"
using namespace std;

class Area {
    private:
        int** mPopulation;
        int mSumOfPeople = 0;
        int mSize = 10;
        int mTemple = 0;

    public:
        // Constructors and Destructors
        Area(int); //int size
        Area();
        ~Area();

        // Getters and Setters
        int getTemple();
        void setTemple(int temple);
        int getSumOfPeople();
        int getSize();

        void printPopulation();
        void generatePopulation();
        void populationToStation( vector <Station*> );
        int &operator[](Point); //zwraca mPopulation[point.X][point.Y]

        void savePopulation(fstream* toFile); // write to file
        void restorePopulation(fstream* fromFile, int readSize); // extract from file

};

#endif // AREA_H

