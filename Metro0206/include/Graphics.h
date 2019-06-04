#ifndef REPO_METRO_GRAPHICS_H
#define REPO_METRO_GRAPHICS_H
#include "Station.h"
#include "Stretch.h"
#include "Present.h"

#define SIZE 10



class Graphics : public Present{
private:
    int mNumber = 0;//number of drawn graphs

public:

    //using Present::Present;
    explicit Graphics(Graph* graph): Present(graph){}


    void drawPop();
    void drawMetro();

    ~Graphics(){}

};


#endif //REPO_METRO_GRAPHICS_H
