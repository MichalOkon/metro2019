        case 1:
            show.stationsInfo();
            break;
        case 2:
            show.stretchesInfo();
            show.drawMetro();
            break;
        case 3:
            cout << "Podaj liczbe dni do symulacji: ";
            int days;
            cin >> days;
            simulateNDays(&city, days, draw);
            break;
        case 4:
            show.drawPop();
#include <iostream>
#include <iomanip>
#include "../include/Menu.h"

Menu::Menu() {

}

Menu::Menu(Graph * g) : mCity(g) {
    
}
Menu::~Menu() {
    
}

Graph* Menu::getCity() {
    return this->mCity;
}

void Menu::setCity(Graph * graph) {
    this->mCity = graph;
}

void Menu::greetUsers() {
    cout << "Welcome to Metro 2019" << endl;
}

void Menu::showOptions() {
    cout << "Select one of the two options" << endl;
    cout << "1. Load from file\t\t2. Create a new simulation" << endl;
}

void Menu::safeLoad(SL saver, string filename) {
    try {
        saver.loadMetro(filename);
    } catch(std::exception &e) {
        cout << e.what() << endl;
    }
}

char Menu::singleCharInp(string input) {
    cin >> input;
    return input[0];
}

// void Menu::makeFun(Display * drawer, Graphics * shower, SL * saver, Parser * parser) {
    
//     cout << "Wybierz co chcesz zrobic: \n" << endl;
//     cout << "1. Wypisz informacje o stacjach" << endl;
//     cout << "2. Wypisz informacje o polaczeniach" << endl;
//     cout << "3. Symuluj ilosc dni " << endl;
//     cout << "4. Pokaz rozmieszczenie ludzi" << endl;
//     cout << "5. Zapisz ludnosc do pliku" << endl;
//     cout << "6. Odczytaj ludnosc z pliku" << endl;
//     cout << "7. Narusuj mape ludnosci do pliku" << endl;
//     cout << "8. Rysuj mape metra do pliku" << endl;
//     cout << "9. Zapisz mape metra do pliku" << endl;

//     cout << "Podaj liczbe: ";

//     int n;
//     parser->safeInsertInt(&n);

//     while (!breakFlag()) {
        
//         switch(n) {
//             case 1:
//                 shower->stationsInfo();
//                 break;
//             case 2:
//                 shower->stretchesInfo();
//                 shower->drawMetro();
//                 break;
//             case 3:
//                 cout << "Podaj liczbe dni do symulacji: ";
//                 int days;
//                 cin >> days;
//                 simulateNDays(&city, days, draw);
//                 break;
//             case 4:
//                 shower->drawPop();
//                 break;
//             case 5:
//                 saver->savePop("individual_save.txt");
//                 break;
//             case 6:
//                 saver->loadPop("individual_save.txt");
//                 break;
//             case 7:
//                 drawer->drawPop();
//                 break;
//             case 8:
//                 drawer->drawMetro();
//                 break;
//             case 9:
//                 saver->saveMetro("saved.txt");
//                 saver->savePop();
//                 break;

//             default:
//                 cout << "Nie wiem co zrobic z twoim zapytaniem..." << endl;
//                 break;
//             }

//         cout << "Czy chcesz cos jeszcze zrobic? (Y/N)" << endl;

//         }
//     }
// }

void Menu::fillGraph(Graph * graph, Parser * parser) {

    // TODO: enters the amount of stations SAFELY - DONE
    cout << "Podaj liczbe stacji: ";
    int n;

    parser->safeInsertInt(&n);


    // TODO: enters each station one by one SAFELY - DONE
    cout << "Dodajmy stacje:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Podaj imie i wspolrzedne stacje: " << endl;
        parser->insertStation();
    }


    for (int i = 0; i < mCity->getStationsAmount(); i++) {
        cout << "sName: " << mCity->getStations()[i]->getName() << " sX: " << mCity->getStations()[i]->getPoint()->getX() << " sY: " << mCity->getStations()[i]->getPoint()->getY() << endl;
    }

    cout << endl;

    // TODO: enters the amount of stretches SAFELY 
    // TODO: add checking the number of connections

    cout << "Podaj liczbe polaczen: ";
    parser->safeInsertInt(&n);

    cout << n << endl;
    // TODO: enters each stretch SAFELY

    for(int i = 0; i < n; i++) {
        cout << "Podaj skad, dokad i przepustowosc" << endl;
        // cout << "i = " << i << endl;
        parser->insertStretch();
    }
    
    cout << "Hi" << endl;
}


