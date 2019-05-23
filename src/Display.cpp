#include "Display.h"
#define WIDTH 4
#define WIDTHS 5


using namespace std;


void Display::drawMetro() {

    cout.setf(ios::left, ios::adjustfield);
    cout.width(WIDTHS);
    cout << " ";

    for(auto i: mGraph->getStations()){
        cout.width(WIDTHS);
        cout << i->getName();
    }
    cout<< endl;

    for(auto i: mGraph->getStations()){
        cout.width(WIDTHS);
        cout << i->getName();

        for(auto j: mGraph->getStations()){

            bool pom = false;
            for(auto k: mGraph->getStretches()){
                if((k->getFrom().getID() == (j)->getID() &&
                        k->getTo().getID() == i->getID())
                   || (k->getTo().getID() == j->getID() &&
                       k->getFrom().getID() == i->getID())){


                    cout.width(WIDTHS);
                    cout << "X";
                    pom = true;
                    break;
                }

            }
                if(!pom){
                    cout.width(WIDTHS);
                    cout << " ";
                }
        }
        cout<<endl;
    }
}


void Display::drawPop() {

    cout << endl;

    for(int i = 0; i < SIZE; i++){

        cout << "|";

        for (int j = 0; j < SIZE; j++){
            cout.width(WIDTH);
            cout << mGraph->getArea()->getPopulation()[i][j] ;
            cout << "|";

        }

        cout << endl;

        for(int a = 0; a < (WIDTH+1)*SIZE + 1; a++){
            cout << "-";
        }

        cout << endl;
    }
}

/////////////////////wzorzec obserwator
////////////dodatkowe klasy design

void Display::savePop(){

    ofstream file;

    file.open("population.txt", ofstream::out);

    for(int a = 0; a < (WIDTH+1)*SIZE + 1; a++){
        file << "-";
    }

    file << endl;

    for(int i = 0; i < SIZE; i++){

        file << "|";

        for (int j = 0; j < SIZE; j++){
            file.width(WIDTH);
            file << mGraph->getArea()->getPopulation()[i][j] ;
            file << "|";

        }

        file << endl;

        for(int a = 0; a < (WIDTH+1)*SIZE + 1; a++){
            file << "-";
        }

        file << endl;
    }

    file.close();
}