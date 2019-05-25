#ifndef REPO_METRO_SAVEANDLOAD_H
#define REPO_METRO_SAVEANDLOAD_H

#include "Graph.h"

class SL {
    Graph* mGraph;

public:

    explicit SL(Graph* graph) : mGraph(graph){}

    void saveMetro(string name); //saves metro
    bool loadMetro(string name); //loads saved metro





};


#endif //REPO_METRO_SAVEANDLOAD_H
