#include <iostream>
#include <vector>
#include <fstream>
#ifndef AREA_H
#define AREA_H
#include "Point.cpp"
class Area {
    private:

        Point * mCity;
        int mTemple;

        std::vector<int> mPopulation;

    public:

        // Getters and Setters
        Point* GetCity();
        void SetCity(Point * city);
        int GetTemple();
        void SetTemple(int temple);

        // Finally useful methods
        //void Day();
        //void display();

        // Constructors and Destructors
        Area(Point*, int);
        Area();
        ~Area();

        void printPopulation();

        std::vector<int> GeneratePopulation(int lenOfDistricts);
        std::vector<int> GetPopulation();
        void SetPopulation(std::vector<int> population);
        void SavePopulation(std::ofstream* toFile); // write to file
        void RestorePopulation(std::ifstream* fromFile, int elToRead); // extract from file

};

#endif // AREA_H

