#ifndef REPO_METRO_DISPLAY_H
#define REPO_METRO_DISPLAY_H

#include <vector>
#include <iostream>
#include "Station.h"
#include "Area.h"
#include "Stretch.h"
#include "Present.h"

using namespace std;


class Display : public Present{

public:

    //using Present::Present;
    Display(Graph* graph) : Present(graph){}
    //displaying population map
    void drawPop();
    //displaying stations and their connections
    void drawMetro();
    //saving population to file
    void savePop();
    ~Display(){}
};

#endif //REPO_METRO_DISPLAY_H

