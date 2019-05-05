#include <iostream>
#include <vector>
#include <fstream>
#ifndef AREA_H
#define AREA_H
#include "Point.h"
class Area {
    private:

        Point * mCity;
        int mTemple;

        std::vector<int> mPopulation;

    public:

        // Getters and Setters
        Point* getCity();
        void setCity(Point * city);
        int getTemple();
        void setTemple(int temple);

        // Finally useful methods
        //void Day();
        //void display();

        // Constructors and Destructors
        Area(Point*, int);
        Area();
        ~Area();

        void printPopulation();

        std::vector<int> generatePopulation(int lenOfDistricts);
        std::vector<int> getPopulation();
        void setPopulation(std::vector<int> population);
        void savePopulation(std::ofstream* toFile); // write to file
        void restorePopulation(std::ifstream* fromFile, int elToRead); // extract from file

};

#endif // AREA_H

