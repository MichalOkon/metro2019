#ifndef REPO_METRO_SAVEANDLOAD_H
#define REPO_METRO_SAVEANDLOAD_H

#include "Graph.h"
#include "Display.h"
#include "Graphics.h"

class SL {
    Graph* mGraph;

public:

    explicit SL(Graph* graph) : mGraph(graph){}

    void saveMetro(string name); //saves metro
    static void loadMetro(string name, Graph* graph); //loads saved metro





};


#endif //REPO_METRO_SAVEANDLOAD_H
