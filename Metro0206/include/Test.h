#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "Graph.h"
#include "Graphics.h"
using namespace std;



void simulateNDays(Graph* city, int days, Graphics& g) {

    cout << "SYMULACJA " << days << " DNI:" << endl;
        for (int i = 0; i < days; i++) {
            cout << "DZIEN: " << i + 1 << endl;
            city->action();
            cout << "After the something" << endl;
            city->show();
            cout << endl;
            g.drawMetro();
        }
    // return;
}