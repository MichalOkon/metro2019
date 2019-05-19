//
// Created by zsantorowska on 19.05.19.
//

#include "Statistics.h"

Statistics::Statistics()
{

}


void Statistics::addDay(Graph* g)
{
    days.push_back( g );
}

ostream &operator<<(ostream &os, const Statistics &statistics) {
    os << "days: " << statistics.days;
    return os;
}
