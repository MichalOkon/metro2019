#ifndef REPO_METRO_DISPLAY_H
#define REPO_METRO_DISPLAY_H

#include <vector>
#include <iostream>
#include "Station.h"
#include "Area.h"
#include "Stretch.h"

using namespace std;


class Display{

public:
    //displaying population map
    void displayPop(int** population);
    //displaying stations and their connections
    void displayMetro(vector <Station*> stations, vector <Stretch*> stretches);
    //saving population to file
    void savePop(int** population);
};

#endif //REPO_METRO_DISPLAY_H

