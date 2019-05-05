#include <vector>
#include <iostream>
#include <ctime>
#include "Area.h"



using namespace std;

// Point[] wszedzie gdzie masz

Point* Area::getCity() {
    return mCity;
}

void Area::setCity(Point * city) {
    mCity = city;
}

int Area::getTemple() {
    return mTemple;
}

void Area::setTemple(int temple) {
    mTemple = temple;
}

Area::Area(Point * city, int temple) {
    mCity = city;
    mTemple = temple;
    mPopulation.assign(100, 0);
}


Area::Area() {
    mCity = new Point[100];
    mTemple = 0;
    mPopulation.assign(100, 0);
}

Area::~Area() {
	delete[] mCity;
    cout << "Area has been destroyed..." << "\n";
}

// generates the population
// it's just pseudo - random numbers <200, 1200)
std::vector<int> Area::generatePopulation(int lenOfDistricts)
{
    //std::vector<int> population;
    mPopulation.assign(100, 0); // sets the value of the vector to 0s
    for (int i = 0; i < lenOfDistricts; i++) {
        mPopulation[i] = rand() % 1000 + 200;
    }


    return mPopulation;
}

// simply returns the member population
std::vector<int> Area::getPopulation()
{
    return mPopulation;
}

// a setter for population
void Area::setPopulation(std::vector<int> population)
{
    mPopulation = population;
}

// writes population to the file
// saves it in the file
void Area::savePopulation(ofstream* toFile)
{
    std::vector<int> temp = this->getPopulation();
    for (int i = 0; i < temp.size(); i++) {
        *toFile << temp[i] << "\n";
    }
	temp.clear();
}

// extract from file
// and restores the population
void Area::restorePopulation(ifstream* fromFile, int elToRead)
{
    std::vector<int> temp;
    temp.assign(100, 0);  // wypełnia zerami
    for (int i = 0; i < elToRead; i++) {
        *fromFile >> temp.at(i);
    }

    this->setPopulation(temp);
}

void Area::printPopulation() {
    for (int i = 0; i < mPopulation.size(); i++) {
        cout << mPopulation[i] << "\n";
    }
}


// TODO: match points in area with population on each district





/*int main() {

    srand(time(NULL));
    Area Area;

    // generates the population
    std::vector<int> population = Area.GeneratePopulation(100);
    int genLen = population.size();

    // sets the mPopulation
    Area.SetPopulation(population);

    // that's where the writing goes
    std::ofstream toFile;
    toFile.open("data.txt", ios::out);

    Area.SavePopulation(&toFile);

    toFile.close();

    // for testing purposes associates
    // the population vector to zeros
    std::vector<int> test;
    test.assign(100, 0);
    Area.SetPopulation(test);


    // restoring the population
    std::ifstream fromFile;
    fromFile.open("data.txt", ios::in);

//    std::vector<int> newPop;
    Area.RestorePopulation(&fromFile, genLen);

    // and prints the result
    Area.printPopulation();
}*/
