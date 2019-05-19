//
// Created by zsantorowska on 19.05.19.
//

#ifndef METRO2019_STATISTICS_H
#define METRO2019_STATISTICS_H


#include <include/Graph.h>
#include <ostream>
#include "Graph.h"

class Statistics {

private:

    vector < Graph* > days;

public:

    Statistics();

    void addDay(Graph* g);

    friend ostream &operator<<(ostream &os, const Statistics &statistics);

};


#endif //METRO2019_STATISTICS_H
