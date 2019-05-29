#include <iostream>
#include <cstdlib>
#include "../include/Area.h"
#include "../include/Graph.h"
#include "../include/Test.h"
#include "../include/Display.h"
#include "../include/Graphics.h"
#include "../include/SaveAndLoad.h"
using namespace std;

int main()
{
    srand(time(0));

    int n;
    string sN;
    Graph city(20);

    Display show(&city);
    Graphics draw(&city);
    SL saver(&city);
    char c;

    string wrInp;
    // breakFlag = false;
    bool breakFlag = false;

    while(!breakFlag) {

        cout << "Czy chcesz zaladowac metro z pliku? Wpisz 'Y'(tak) lub 'N'(nie)" << endl;
        
        cin >> wrInp;


        // prevent data from imputs like 'yaml' or 'nor' which is YES or NO in your code LATER
        if (wrInp[0] == 'y' || wrInp[0] == 'Y') {
            if(saver.loadMetro("saved.txt"))
                breakFlag = true;
            else
                cout << "Nie odnaleziono pliku do wczytania" << endl;
        } else if(wrInp[0] == 'n' || wrInp[0] == 'N') {
            cout << "Podaj ilosc stacji: " << endl;

            // try {
            //     cin >> n;
            //     for (int i = 0; i < n; i++)
            //     city.addStation();
            // // } catch (std::exception & ex) {
            //     //cout << "Other exception" << endl;
            // } catch (std::invalid_argument const &e) {
            //     cout << "invalid argument" << endl;
            // }

            
            bool statErrFlag = false;
            while (true) {
                try {
                    cin >> sN;
                    n = std::stoi(sN);
                } catch (std::exception &ex) {
                    statErrFlag = true;
                    cout << "Invalid type of argument (must be integer). Try again..." << endl;
                    continue;
                }
                statErrFlag = false;
                break;
            }
            
            
            if (!statErrFlag) {
                for (int i = 0; i < n; i++)
                    city.addStation();
                city.populationToStation();
            }
            // city.populationToStation();

            bool strErrFlag = false;
            cout << "Podaj ilosc odcinkow: " << endl;
            while (true) {
                try {
                    cin >> sN;
                    n = std::stoi(sN);
                } catch (std::exception &ex) {
                    strErrFlag = true;
                    cout << "Invalid type of argument (must be integer). Try again..." << endl;
                    continue;
                }
                strErrFlag = false;
                break;
            }

            if (!strErrFlag) {

                for (int i = 0; i < n; i++)
                    city.addStretch();
            }

            breakFlag = true;
        } else {
            cout << "Podaj prawidlowy znak!" << endl;
        }

    }

    bool breakActFlag = false;

    while (!breakActFlag) {

        system("cls");

        cout << "Co chcesz zrobic:\n";
        cout << "1. Wypisz nazwy\n";
        cout << "2. Wypisz informacje o stacjach\n";
        cout << "3. Wypisz informacje o polaczeniach\n";
        cout << "4. Symuluj ilosc dni\n";
        cout << "5. Pokaz rozmieszczenie ludzi\n";
        cout << "6. Zapisz ludnosc do pliku\n";
        cout << "7. Odczytaj ludnosc z pliku\n";
        cout << "8. Narusuj mape ludnosci do pliku\n";
        cout << "9. Rysuj mape metra do pliku" << endl;
        cout << "10. Zapisz mape metra do pliku" << endl;

        cout << "Podaj odpowiednia liczbe: ";
        int request;
        cin >> request;

        switch(request)
        {
        case 1:
            stationNamesTest(&city);
            break;
        case 2:
            stationsInfoTest(&city);
            break;
        case 3:
            stretchesInfoTest(&city);
            show.drawMetro();
            break;
        case 4:
            cout << "Podaj liczbe dni do symulacji: ";
            int days;
            cin >> days;
            simulateNDays(&city, days, draw);
            break;
        case 5:
            show.drawPop();
            break;
        case 6:
            peopleSaveTest(&city);
            break;
        case 7:
            peopleRestoreTest(&city);
            break;
        case 8:
            draw.drawPop();
            break;
        case 9:
            draw.drawMetro();
            break;
        case 10:
            saver.saveMetro("saved.txt");
            break;

        default:
            cout << "Nie wiem co zrobic z twoim zapytaniem..." << endl;
            break;
        }

        cout << "Czy chcesz cos jeszcze zrobic? (Y/N)" << endl;

        cin >> c;
        if (c == 'N' || c == 'n') {
            breakActFlag = true;
        }

    }
    return 0;
}

