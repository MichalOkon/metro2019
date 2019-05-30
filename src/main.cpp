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
    Graph city;
    Display show(&city);
    Graphics draw(&city);
    SL saver(&city);

    int n;
    string sN;

    char c;

    string wrInp;
    // breakFlag = false;
    bool breakFlag = false;

    while(!breakFlag) {

        cout << "Czy chcesz zaladowac metro z pliku? Wpisz 'Y'(tak) lub 'N'(nie)" << endl;
        
        cin >> wrInp;


        // prevent data from imputs like 'yaml' or 'nor' which is YES or NO in your code LATER
        if (wrInp[0] == 'y' || wrInp[0] == 'Y') {
            SL::loadMetro("saved.txt", &city);
            saver.loadPop();
            breakFlag = true;


        } else if(wrInp[0] == 'n' || wrInp[0] == 'N') {

            cout << "Podaj wielkosc miasta:" << endl;
            int w;
            cin >> w;
            city.graphStart(w);


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
        cin >> request;

        switch(request)
        {
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
            break;
        case 5:
            saver.savePop("individual_save.txt");
            break;
        case 6:
            saver.loadPop("individual_save.txt");
            break;
        case 7:
            draw.drawPop();
            break;
        case 8:
            draw.drawMetro();
            break;
        case 9:
            saver.saveMetro("saved.txt");
            saver.savePop();
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

