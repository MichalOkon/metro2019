#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Area.h"
#include "Station.h"
#define INF 1000000000 //10^9

using namespace std;

int &Area::operator[](Point p)
{
    return this->mPopulation[p.getX()][p.getY()];
}

int Area::getSumOfPeople()
{
    return mSumOfPeople;
}

int Area::getTemple() {
    return mTemple;
}

void Area::setTemple(int temple) {
    mTemple = temple;
}

int Area::getSize()
{
    return mSize;
}

Area::Area() {
    mSize = 100;
    mPopulation = new int*[100]; //domyslny rozmiar
    for(int i=0; i<100; i++)
    {
        mPopulation[i] = new int[100];
        for(int j=0; j<100; ++j)
            mPopulation[i][j]=0;
    }
    this->generatePopulation();
    mTemple = 0;
}

Area::Area(int size)
{
    mSize = size;
    mPopulation = new int*[size];
    for(int i=0; i<size; ++i)
    {
        mPopulation[i] = new int[size];
        for(int j=0; j<size; ++j)
            mPopulation[i][j]=0;
    }
    this->generatePopulation();
}

Area::~Area() {
    for(int i=0; i<mSize; ++i)
            delete[] mPopulation[i];
    delete[] mPopulation;
    cout << "Area has been destroyed..." << "\n";
}

void Area::generatePopulation() // O(mSize^3)
{
    srand(time(0));
    for(int k=0; k<mSize/2; ++k) //zeby w centrum miasta bylo wiecej ludzi
        for(int i = k; i < mSize-k; ++i)
            for(int j = k; j < mSize-k; ++j)
            {
                int r = rand()%5 + 1;
                mSumOfPeople += r;
                mPopulation[i][j] += r;
            }
}

void Area::populationToStation( vector <Station*> stations )
{
    for(int i=0; i<stations.size(); ++i)
        stations[i]->setPeople(0);

    vector <int> tab[mSize][mSize];
    for(int i=0; i<mSize; ++i)
        for(int j=0; j<mSize; j++)
            tab[i][j].push_back(INF);

    queue < pair<Point, int> > Q;

    for(int i=0; i<stations.size(); ++i)
    {
        Q.push( make_pair(stations[i]->getPoint(), i) );
        tab[Q.back().first.getX()][Q.back().first.getY()][0]=1;
        tab[Q.back().first.getX()][Q.back().first.getY()].push_back(i);
    }
    while( !Q.empty() )
    {
        int s = Q.size();
        for(int i=0; i<s; ++i)
        {
            Point p = Q.front().first;
            int ac = Q.front().second;
            Q.pop();

            if( p.getX()-1 >= 0) //X-1, Y
            {
                if( tab[ p.getX()-1 ][ p.getY() ][0] == tab[ p.getX() ][ p.getY() ][0]+1 ) //X-1, Y
                {
                    bool help = true;
                    for(int j=1; j < tab[ p.getX()-1 ][ p.getY() ].size(); ++j)
                        if(tab[ p.getX()-1 ][ p.getY() ][j] == ac) 
                        {
                            help = false;
                            break;
                        }
                    if(help)
                    {
                        tab[ p.getX()-1 ][ p.getY() ].push_back(ac);
                        Q.push( make_pair( Point( p.getX()-1, p.getY() ), ac) );
                    }
                }
                else if(tab[ p.getX()-1 ][ p.getY() ][0] == INF)
                {
                    tab[ p.getX()-1 ][ p.getY() ][0] = tab[ p.getX() ][ p.getY() ][0]+1;
                    tab[ p.getX()-1 ][ p.getY() ].push_back(ac);
                    Q.push( make_pair( Point( p.getX()-1, p.getY() ), ac) );
                }
            }
            if( p.getX()+1 < mSize) //X+1, Y
            {
                if( tab[ p.getX()+1 ][ p.getY() ][0] == tab[ p.getX() ][ p.getY() ][0]+1 )
                {
                    bool help = true;
                    for(int j=1; j < tab[ p.getX()+1 ][ p.getY() ].size(); ++j)
                        if(tab[ p.getX()+1 ][ p.getY() ][j] == ac) 
                        {
                            help = false;
                            break;
                        }
                    if(help)
                    {
                        tab[ p.getX()+1 ][ p.getY() ].push_back(ac);
                        Q.push( make_pair( Point( p.getX()+1, p.getY() ), ac) );
                    }
                }
                else if(tab[ p.getX()+1 ][ p.getY() ][0] == INF)
                {
                    tab[ p.getX()+1 ][ p.getY() ][0] = tab[ p.getX() ][ p.getY() ][0]+1;
                    tab[ p.getX()+1 ][ p.getY() ].push_back(ac);
                    Q.push( make_pair( Point( p.getX()+1, p.getY() ), ac) );
                }
            }
            if( p.getY()-1 >= 0) //X, Y-1
            {
                if( tab[ p.getX() ][ p.getY()-1 ][0] == tab[ p.getX() ][ p.getY() ][0]+1 )
                {
                    bool help = true;
                    for(int j=1; j < tab[ p.getX() ][ p.getY()-1 ].size(); ++j)
                        if(tab[ p.getX() ][ p.getY()-1 ][j] == ac) 
                        {
                            help = false;
                            break;
                        }
                    if(help)
                    {
                        tab[ p.getX() ][ p.getY()-1 ].push_back(ac);
                        Q.push( make_pair( Point( p.getX(), p.getY()-1 ), ac) );
                    }
                }
                else if(tab[ p.getX() ][ p.getY()-1 ][0] == INF)
                {
                    tab[ p.getX() ][ p.getY()-1 ][0] = tab[ p.getX() ][ p.getY() ][0]+1;
                    tab[ p.getX() ][ p.getY()-1 ].push_back(ac);
                    Q.push( make_pair( Point( p.getX(), p.getY()-1 ), ac) );
                }
            }
            if( p.getY()+1 < mSize) //X, Y+1
            {
                if( tab[ p.getX() ][ p.getY()+1 ][0] == tab[ p.getX() ][ p.getY() ][0]+1 )
                {
                    bool help = true;
                    for(int j=1; j < tab[ p.getX() ][ p.getY()+1 ].size(); ++j)
                        if(tab[ p.getX() ][ p.getY()+1 ][j] == ac) 
                        {
                            help = false;
                            break;
                        }
                    if(help)
                    {
                        tab[ p.getX() ][ p.getY()+1 ].push_back(ac);
                        Q.push( make_pair( Point( p.getX(), p.getY()+1 ), ac) );
                    }
                }
                else if(tab[ p.getX() ][ p.getY()+1 ][0] == INF)
                {
                    tab[ p.getX() ][ p.getY()+1 ][0] = tab[ p.getX() ][ p.getY() ][0]+1;
                    tab[ p.getX() ][ p.getY()+1 ].push_back(ac);
                    Q.push( make_pair( Point( p.getX(), p.getY()+1 ), ac) );
                }
            }
        }
    }
    for(int i=0; i<mSize; ++i)
        for(int j=0; j<mSize; ++j)
            for(int k=1; k<tab[i][j].size(); ++k)
                (*stations[ tab[i][j][k] ]) += mPopulation[i][j] / (tab[i][j].size()-1);
}

void Area::printPopulation() {
    for(int i=0; i<mSize; ++i)
    {
        for(int j=0; j<mSize; ++j)
            cout << setw(4) << (*this)[Point(j,i)]; // Point (j,i) -> celowo
        cout << endl;
    }
}


// writes population to the file
// saves it in the file
void Area::savePopulation(fstream* toFile)
{
    for (int i = 0; i < mSize; ++i) {
        for(int j=0; j< mSize; ++j)
            *toFile << mPopulation[i][j] << " ";
        *toFile << endl;
    }
}

// extract from file
// and restores the population
void Area::restorePopulation(fstream* fromFile, int readSize)
{
    for (int i = 0; i < readSize; ++i)
        for(int j = 0; j < readSize; ++j)
            *fromFile >> mPopulation[i][j];
}



// TODO: match points in area with population on each district


/*int main() {

//    saving the population
    toFile.open("data.txt", ios::out);
    Area.SavePopulation(&toFile);
    toFile.close();

//    restoring the population
    fstream fromFile;
    fromFile.open("data.txt", ios::in);

//    std::vector<int> newPop;
    Area.RestorePopulation(&fromFile, genLen);

    // and prints the result
    Area.printPopulation();
}*/
