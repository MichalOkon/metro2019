#include <iostream>
#include <cstdlib>
#include "Area.h"
#include "Graph.h"
#include "Test.h"
#include "Display.h"
#include "Graphics.h"
#include "Statistics.h"

//using namespace std;
//
//int main()
//{
//    srand(time(0));
//
//    int n;
//    Graph city(10);
//
//    Display show;
//    Graphics draw;
//
//    cout << "Hello, world" << endl;
//
//    cout << "Gimme stations amount: " << endl;
//    cin >> n;
//
//    for(int i=0; i < n; i++)
//        city.addStation();
//
//    city.populationToStation();
//
//    cout << "Gimme stretches amount: " << endl;
//    cin >> n;
//
//    for (int i = 0; i < n; i++)
//        city.addStretch();
//
//    char c;
//    bool breakFlag = 0;
//
//    while (!breakFlag) {
//
//        system("clear");
//
//        cout << "Co chcesz zrobic:\n";
//        cout << "1. Wypisz nazwy\n";
//        cout << "2. Wypisz informacje o stacjach\n";
//        cout << "3. Wypisz informacje o polaczeniach\n";
//        cout << "4. Symuluj ilosc dni\n";
//        cout << "5. Pokaz rozmieszczenie ludzi\n";
//        cout << "6. Zapisz ludnosc do pliku\n";
//        cout << "7. Odczytaj ludnosc z pliku\n";
//        cout << "8. Narusuj mape ludnosci do pliku\n";
//        cout << "9. Rysuj mape metra do pliku" << endl;
//
//        cout << "Podaj odpowiednia liczbe: ";
//        int request;
//        cin >> request;
//
//        switch(request)
//        {
//        case 1:
//            stationNamesTest(&city);
//            break;
//        case 2:
//            stationsInfoTest(&city);
//            break;
//        case 3:
//            stretchesInfoTest(&city);
//            show.displayMetro(city.getStations(), city.getStretches());
//            break;
//        case 4: {
//            cout << "Podaj liczbe dni do symulacji: ";
//            int days;
//            cin >> days;
//            Statistics *stat = simulateNDays(&city, days);
//            cout << stat << endl;
//            break;
//        }
//        case 5:
//            show.displayPop(city.getArea()->getPopulation());
//            break;
//        case 6:
//            peopleSaveTest(&city);
//            break;
//        case 7:
//            peopleRestoreTest(&city);
//            break;
//        case 8:
//            draw.drawPop(city.getArea()->getPopulation());
//            break;
//        case 9:
//            draw.drawMetro(city.getStations(), city.getStretches(), "City");
//            break;
//        default:
//            cout << "Nie wiem co zrobic z twoim zapytaniem..." << endl;
//            break;
//        }
//
//        cout << "Czy chcesz cos jeszcze zrobic? (Y/N)" << endl;
//
//        cin >> c;
//        if (c == 'N' || c == 'n') {
//            breakFlag = 1;
//        }
//
//    }
//    return 0;
//}