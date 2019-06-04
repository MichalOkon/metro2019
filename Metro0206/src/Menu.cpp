#include <iostream>
#include <iomanip>
#include "../include/Menu.h"
#include "../include/Test.h"

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
    cout << "Witaj w Metro 2019" << endl;
}

void Menu::showOptions() {
    cout << "Wybierz jedna z dwoch opcji" << endl;
    cout << "1. Zaladowac z pliku\t\t2. Stworzyc nowa symulacje" << endl;
}

void Menu::safeLoad(SL saver, string filename) {
    try {
        saver.loadMetro(filename, mCity);
    } catch(std::exception &e) {
        cout << e.what() << endl;
    }
}

char Menu::singleCharInp(string input) {
    cin >> input;
    return input[0];
}



void Menu::makeFun(Display * shower, Graphics * drawer, SL * saver, Parser * parser) {
        
        char c;
        bool breakFlag = false;

        while (!breakFlag) {
            
            system("cls");

            cout << "Co chcesz zrobic:\n";
            cout << "1. Wypisz informacje o stacjach\n";
            cout << "2. Wypisz informacje o polaczeniach\n";
            cout << "3. Symuluj ilosc dni\n";
            cout << "4. Pokaz rozmieszczenie ludzi\n";
            cout << "5. Zapisz ludnosc do pliku\n";
            cout << "6. Odczytaj ludnosc z pliku\n";
            cout << "7. Narusuj mape ludnosci do pliku\n";
            cout << "8. Rysuj mape metra do pliku" << endl;
            cout << "9. Zapisz mape metra do pliku" << endl;
            cout << "Podaj odpowiednia liczbe: ";

            int request;
            parser->safeInsertInt(&request);

            switch(request) {
                case 1:
                    shower->stationsInfo();
                    break;
                case 2:
                    shower->stretchesInfo();
                    shower->drawMetro();
                    break;
                case 3:
                    cout << "Podaj liczbe dni do symulacji: ";
                    int days;
                    cin >> days;
                    simulateNDays(mCity, days, *drawer);
                    break;
                case 4:
                    shower->drawPop();
                    break;
                case 5:
                    saver->savePop("individual_save.txt");
                    break;
                case 6:
                    saver->loadPop("individual_save.txt");
                    break;
                case 7: 
                    drawer->drawPop();
                    break;
                case 8:
                    drawer->drawMetro();
                    break;
                case 9: 
                    saver->saveMetro("saved.txt");
                    saver->savePop();
                    break;
                default: 
                    cout << "Nie wiem co zrobic z twoim zapytaniem..." << endl;
                    break;
            }

            cout << "Czy cos jeszcze (Y/N): " << endl;
            cin >> c;

            if (c == 'N' || c == 'n') {
                breakFlag = true;
            }
            cout << endl;

        }

}

void Menu::fillGraph(Graph * graph, Parser * parser) {

    cout << "Podaj wielkosc miasta:" << endl;
    int w;
    parser->safeInsertInt(&w);
    mCity->graphStart(w);

    // TODO: enters the amount of stations SAFELY - DONE
    cout << "Podaj liczbe stacji: ";
    int n;

    parser->safeInsertInt(&n);
    cout << endl;


    // TODO: enters each station one by one SAFELY - DONE
    cout << "Dodajmy stacje:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Podaj imie i wspolrzedne stacje: " << endl;
        parser->insertStation();
    }

    mCity->populationToStation();


    for (int i = 0; i < mCity->getStationsAmount(); i++) {
        cout << "sName: " << mCity->getStations()[i]->getName() << " sX: " << mCity->getStations()[i]->getPoint()->getX() << " sY: " << mCity->getStations()[i]->getPoint()->getY() << endl;
    }

    cout << endl;

    // TODO: enters the amount of stretches SAFELY 
    // TODO: add checking the number of connections

    cout << "Podaj liczbe polaczen: ";
    parser->safeNumStretches(&n);

    cout << n << endl;
    // TODO: enters each stretch SAFELY

    for(int i = 0; i < n; i++) {
        cout << "Podaj skad, dokad i przepustowosc" << endl;
        // cout << "i = " << i << endl;
        parser->insertStretch();
    }


    
    cout << "Hi" << endl;

}


