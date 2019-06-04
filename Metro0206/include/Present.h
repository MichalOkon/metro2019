#ifndef REPO_METRO_PRESENT_H
#define REPO_METRO_PRESENT_H

#include "Graph.h"


class Present {
public:
    Graph* mGraph;


    explicit Present(Graph* graph): mGraph(graph){}
    virtual void drawMetro() = 0;
    virtual void drawPop() = 0;

    virtual ~Present() {}
};

#endif