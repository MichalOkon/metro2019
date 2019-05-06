#include <iostream>
#include <vector>
#include <fstream>
#ifndef AREA_H
#define AREA_H
#include "Station.h"
using namespace std;

class Area {
    private:
        int** mPopulation;
        int mSumOfPeople = 0;
        int mSize = 10;

//        Point * mCity;
        int mTemple = 0;

//        std::vector<int> mPopulation;

    public:

        // Getters and Setters
//        Point* getCity();
//        void setCity(Point * city);
        int getTemple();
        void setTemple(int temple);
        int getSumOfPeople();

        // Finally useful methods
        //void Day();
        //void display();

        // Constructors and Destructors
//        Area(Point*, int);
        Area(int); //int size
        Area();
        ~Area();

        void generatePopulation();
        void populationToStation( vector <Station*> );
        int &operator[](Point); //zwraca mPopulation[point.X][point.Y]

//        void printPopulation();

//        std::vector<int> generatePopulation(int lenOfDistricts);
//        std::vector<int> getPopulation();
//        void setPopulation(std::vector<int> population);
//        void savePopulation(std::ofstream* toFile); // write to file
//        void restorePopulation(std::ifstream* fromFile, int elToRead); // extract from file

};

#endif // AREA_H

