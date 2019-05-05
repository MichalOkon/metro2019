#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Area.h"
#include "Graph.h"

using namespace std;


int stationNamesTest(Graph city) {

    vector<Station*> stations = city.getStations();
    
    cout << "STACJE: " << endl;

    for (int i = 1; i < stations.size(); i++) {
        cout << stations[i]->getName() << endl;
    }

    return 0;
}

int stationsInfoTest(Graph city) {

    vector<Station*> stations = city.getStations();

    cout << "INFORMACJE O STACJACH: " << endl;
    for (int i = 0; i < stations.size(); i++) {
        cout << "Nazwa: " << stations[i]->getName() << endl;
        cout << "Liczba ludzi: " << stations[i]->getPeople() << endl;
        cout << "X: " << stations[i]->getPoint().getX() << endl;
        cout << "Y: " << stations[i]->getPoint().getY() << endl;
    }

    return 0;
}

// TODO: What's the aim?
int commonAimTest(Graph city);

int stretchesInfoTest(Graph city) {
    
    vector<Stretch*> connections = city.getStretches();

    for (int i = 0; i < connections.size(); i++) {

        cout << "ID: " << connections[i]->getId() << endl;
        cout << "Z: " << connections[i]->getFrom().getName() << endl;
        cout << "Do: " << connections[i]->getTo().getName() << endl;
        cout << "Przepustowość: " << connections[i]->getPass() << endl;

    }

    return 0;
}

void simulateNDays(Graph city, int days) {

    cout << "SYMULACJA " << days << " DNI:" << endl;

    for (int i = 0; i < days; i++) {
        cout << "DAY " << i + 1 << endl;
        city.toOnePoint(2);
        city.show();
        cout << endl;
    }
}

int peoplePlacementTest() {
    
    cout << "ROZMIESZCZENIE LUDZI: " << endl;
    Area map;
//    map.generatePopulation(5);
//    map.printPopulation();

}

int peopleSaveTest() {
    
    Area map;

    cout << "ZAPIS LUDNOŚCI DO PLIKU: " << endl;

    ofstream toFile;
    toFile.open("testSave.txt");
//    map.savePopulation(&toFile);
    toFile.close();
    return 0;
}

int peopleRestoreTest() {

    Area map;

    cout << "ODCZYT LUDNOŚCI Z PLIKU: " << endl;

    ifstream fromFile;
    fromFile.open("test2.txt");
//    map.restorePopulation(&fromFile, 100);

//    map.printPopulation();
    fromFile.close();
}

// int tests(Graph city){

//     auto stations = city.getStations();
//     return 0;

    // //Pokaz stacje

    // cout<< "STACJE: "<< endl;

    // for(int i = 1; i < stations.size(); i++ ){
    //     cout<< stations[i]->getName() << endl;
    // }


    //Pokaz informacje o stacjach

    // cout<< "INFORMACJE O STACJACH: " << endl;


    // for(int i = 1; i < stations.size(); i++ ){
    //     cout<< "Nazwa: " << stations[i]->getName()<< ": ";
    //     cout<< "Liczba ludzi: " << stations[i]->getPeople() << endl;
    //     cout<< "X: " << stations[i]->getPoint().getX() << endl;
    //     cout<< "Y: " << stations[i]->getPoint().getY() << endl;
    // }



    //Jaki jest cel?


    //Wyswietl polaczenia

    // cout << "POLACZENIA: " << endl;

    // auto stretch = city.get_stretches();

    // for(int i = 0; i < stretch.size(); i++){
    //     cout<< "ID: " << stretch[i]->getId() << endl;
    //     cout<< " Z: "  << stretch[i]->getFrom().mName;
    //     cout<< " Do: " << stretch[i]->getTo().mName;
    //     cout<< " Przepustowosc: " << stretch[i]->getPass() << endl;

    // }


    // //Symuluj 5 dni

    // cout << "SYMULACJA PIECIU DNI: " << endl;


    // for(int i=0; i<5; i++) {
    //     cout << "Day " << i + 1 << endl;
    //     city.to_one_point(2);
    //     city.show();
    //     cout << endl;
    // }

    //Pokaz rozmieszczenie ludzi w terenie

    // cout<< "ROZMIESZCZENIE LUDZI: "<<endl;

    // Area map;
    // map.GeneratePopulation(5);
    // map.printPopulation();

    // //Zapisywanie ludnosci DO pliku

    // ofstream ofile;
    // ofile.open("test.txt");
    // map.SavePopulation(&ofile);


    // //Odczyt ludnosci z pliku

    // Area map2;
    // ifstream ifile;
    // ifile.open("test2.txt");
    // map2.RestorePopulation(&ifile, 100);

    // cout << "ODCZYT LUDNOSCI Z PLIKU"<<endl;
    // map2.printPopulation();


    // return 1;

// }

int main()
{
   // return 0;
    Graph city(10);

/*    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
            cout << setw(3) << (*city.getArea()) [Point(j,i)]; // Point (j,i) -> celowo
        cout << endl;
    }
*/

    cout << "Hello, world" << endl;
   // Graph city;

    cout << "Gimme stations amount: " << endl;
    int n;
    cin >> n;

//return 0;
    for(int i=0; i < n; i++)
        city.addStation();

    city.populationToStation();

//return 0;
    city.show();
//return 0;
    cout << "Gimme stretches amount: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
        city.addStretch();

//return 0;
    for(int i=0; i<20; ++i)
    {
        city.action();
        cout << endl;
    }
    
//    stretchesInfoTest(city);

    // NIEAKTUALNA WERSJA MAIN // 


    // Graph city;
    // cout << "podaj ilosc stacji" << endl;
    // int n;
    // cin >> n;
    // for(int i=0; i<n; i++)
    //     city.addStation();


    // cout << "podaj ilosc polaczen" << endl;
    // cin >> n;
    // for(int i=0; i<n; i++)
    //     city.addStretch();


    //cout << "Podaj ilosc dni" << endl;
    //cin >> n;

    //testy
    // tests(city);

    /*
    for(int i=0; i<n; i++)
    {
        cout << "Day " << i+1 << endl;
        city.to_one_point(2);
        city.show();
        cout << endl;
    }*/
    return 0;
}
