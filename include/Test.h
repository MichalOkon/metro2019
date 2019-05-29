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
        cout << "DAY " << i + 1 << endl;
        city->action();
        city->show();
        cout << endl;
        g.drawMetro();


    }
    return;
}

void peopleSaveTest(Graph* city) {
    
    Area* map = city->getArea();

    cout << "ZAPIS LUDNOSCI DO PLIKU: " << endl;

    ofstream toFile;
    toFile.open("testSave.txt");
//    map.savePopulation(&toFile);
    toFile.close();
    return;
}

void peopleRestoreTest(Graph* city) {

    Area* map = city->getArea();

    cout << "ODCZYT LUDNOŚCI Z PLIKU: " << endl;

    ifstream fromFile;
    fromFile.open("test2.txt");
//    map.restorePopulation(&fromFile, 100);
    fromFile.close();
    return;
}

// TODO: What's the aim?
void commonAimTest(Graph* city)
{

}


/*void allTests(Graph* city)
{
    stationNamesTest(city);
    cout << endl;
    stationsInfoTest(city);
    cout << endl;
    stretchesInfoTest(city);
    cout << endl;
    simulateNDays(city, 1, g);
    city->show();
    cout << endl;
}*/