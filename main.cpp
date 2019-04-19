#include <iostream>

#include "Area.h"
#include "graph.h"

using namespace std;

using namespace std;

int tests(Graph city){

    auto stations = city.get_stations();

    //Pokaz stacje

    cout<< "STACJE: "<< endl;

    for(int i = 1; i < stations.size(); i++ ){
        cout<< stations[i]->getName() << endl;
    }


    //Pokaz informacje o stacjach

    cout<< "INFORMACJE O STACJACH: " << endl;


    for(int i = 1; i < stations.size(); i++ ){
        cout<< "Nazwa: " << stations[i]->getName()<< ": ";
        cout<< "Liczba ludzi: " << stations[i]->getPeople() << endl;
        cout<< "X: " << stations[i]->getPoint().getX() << endl;
        cout<< "Y: " << stations[i]->getPoint().getY() << endl;
    }



    //Jaki jest cel?



    //Wyswietl polaczenia

    cout << "POLACZENIA: " << endl;

    auto stretch = city.get_stretches();

    for(int i = 0; i < stretch.size(); i++){
        cout<< "ID: " << stretch[i]->Getid() << endl;
        cout<< " Z: "  << stretch[i]->Getfrom().mName;
        cout<< " Do: " << stretch[i]->Getto().mName;
        cout<< " Przepustowosc: " << stretch[i]->Getpass() << endl;

    }


    //Symuluj 5 dni

    cout << "SYMULACJA PIECIU DNI: " << endl;


    for(int i=0; i<5; i++) {
        cout << "Day " << i + 1 << endl;
        city.to_one_point(2);
        city.show();
        cout << endl;
    }

    //Pokaz rozmieszczenie ludzi w terenie

    cout<< "ROZMIESZCZENIE LUDZI: "<<endl;

    Area map;
    map.GeneratePopulation(5);
    map.printPopulation();

    //Zapisywanie ludnosci DO pliku

    ofstream ofile;
    ofile.open("test.txt");
    map.SavePopulation(&ofile);


    //Odczyt ludnosci z pliku

    Area map2;
    ifstream ifile;
    ifile.open("test2.txt");
    map2.RestorePopulation(&ifile, 100);

    cout << "ODCZYT LUDNOSCI Z PLIKU"<<endl;
    map2.printPopulation();


    return 1;

}

int main()
{
    Graph city;
    cout << "podaj ilosc stacji" << endl;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        city.add_station();


    cout << "podaj ilosc polaczen" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
        city.add_stretch();


    //cout << "Podaj ilosc dni" << endl;
    //cin >> n;

    //testy
    tests(city);

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