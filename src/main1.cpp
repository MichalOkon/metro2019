#include <iostream>
#include "../include/Graph.h"
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    Graph city(10);

    city.addStation("A", 100, 1, 9);
    city.addStation("B", 100, 8, 1);

    city.addStretch("A", "B", 19);
}