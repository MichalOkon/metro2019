#ifndef REPO_METRO_GRAPHICS_H
#define REPO_METRO_GRAPHICS_H

#include "Station.h"
#include "Stretch.h"

#define SIZE 10



class Graphics{

public:

    void drawPop(int** population);
    void drawMetro(vector <Station*> stations, vector <Stretch*> stretches, string name);

};


#endif //REPO_METRO_GRAPHICS_H
