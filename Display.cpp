#include "Display.h"
#define WIDTH 4
#define WIDTHS 5


using namespace std;

void Display::displayMetro(vector <Station*> stations, vector <Stretch*> const stretches) {

    cout.setf(ios::left, ios::adjustfield);
    cout.width(WIDTHS);

    cout.setf(ios::left, ios::adjustfield);
    cout.width(WIDTHS);
    cout << " ";

    for(int i = 0; i < stations.size(); ++i){
        cout.setf(ios::left, ios::adjustfield);
        cout.width(WIDTHS);
        cout << stations[i]->getName();
    }
    cout<< endl;

    for(int i = 0; i < stations.size(); ++i){
        cout.setf(ios::left, ios::adjustfield);
        cout.width(WIDTHS);
        cout << stations[i]->getName();

        for(int j = 0; j < stations.size(); ++j){

            for(int k = 0; k < stretches.size(); ++k){
                if((stretches[k]->getFrom().getID() == (stations[j])->getID() &&
                        stretches[k]->getTo().getID() == (stations[i])->getID())
                   || (stretches[k]->getTo().getID() == (stations[j])->getID() &&
                       stretches[k]->getFrom().getID() == (stations[i])->getID())){


                    cout.setf(ios::left, ios::adjustfield);
                    cout.width(WIDTHS);
                    cout << "X";
                    break;
                }


                cout.setf(ios::left, ios::adjustfield);
                cout.width(WIDTHS);
                cout << " ";
            }
        }
        cout<<endl;
    }
}


void Display::displayPop(int** population) {

    for(int a = 0; a < (WIDTH+1)*SIZE + 1; a++){
        cout << "-";
    }

    cout << endl;

    for(int i = 0; i < SIZE; i++){

        cout << "|";

        for (int j = 0; j < SIZE; j++){
            cout.width(WIDTH);
            cout << population[i][j] ;
            cout << "|";

        }

        cout << endl;

        for(int a = 0; a < (WIDTH+1)*SIZE + 1; a++){
            cout << "-";
        }

        cout << endl;
    }
}

void Display::savePop(int** population){

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
            file << population[i][j] ;
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
