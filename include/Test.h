#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "Graph.h"
using namespace std;

void stationNamesTest(Graph* city) {

    vector<Station*> stations = city->getStations();
    
    cout << "STACJE: " << endl;

    for (int i = 0; i < stations.size(); i++) {
        cout << stations[i]->getName() << endl;
    }
    return;
}

void stationsInfoTest(Graph* city) {

    vector<Station*> stations = city->getStations();

    cout << "INFORMACJE O STACJACH: " << endl;
    for (int i = 0; i < stations.size(); i++) {
        cout << "Nazwa: " << stations[i]->getName() << endl;
        cout << "Liczba ludzi: " << stations[i]->getPeople() << endl;
        cout << "X: " << stations[i]->getPoint().getX() << endl;
        cout << "Y: " << stations[i]->getPoint().getY() << endl;
    }
    return;
}

void stretchesInfoTest(Graph* city) {
    
    vector<Stretch*> connections = city->getStretches();

    for (int i = 0; i < connections.size(); i++) {

        cout << "ID: " << connections[i]->getId() << endl;
        cout << "Z: " << connections[i]->getFrom()->getName() << endl;
        cout << "Do: " << connections[i]->getTo()->getName() << endl;
        cout << "Przepustowość: " << connections[i]->getPass() << endl;

    }
    return;
}

void simulateNDays(Graph* city, int days) {

    cout << "SYMULACJA " << days << " DNI:" << endl;

    for (int i = 0; i < days; i++) {
        cout << "DAY " << i + 1 << endl;
        city->action();
        city->show();
        cout << endl;
    }
    return;
}

void peopleSaveTest(Graph* city) {
    
    Area* map = city->getArea();

    cout << "ZAPIS LUDNOŚCI DO PLIKU: " << endl;

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


void allTests(Graph* city)
{
    stationNamesTest(city);
    cout << endl;
    stationsInfoTest(city);
    cout << endl;
    stretchesInfoTest(city);
    cout << endl;
    simulateNDays(city, 1);
    city->show();
    cout << endl;
}