#include <vector>
#include <iostream>
#include <ctime>
#include <string> 
#include <queue>
#include "Area.h"
#include "Station.h"


using namespace std;

void add(int x, int y, int ac, int odl, int size, vector <int> ** tab, queue < pair<Point, int> >* Q)
{
    if( x < 0)
        return;
    if( x >= size )
        return;
    if( y < 0)
        return;
    if( y >=size )
        return;
    if( tab[x][y][0] == odl+1 )
    {
        for(int j=1; j < tab[x][y].size(); ++j)
            if(tab[x][y][j] == ac) 
                return;
     
            tab[x][y].push_back(ac);
            (*Q).push( make_pair( Point( x,y ), ac) );
    }
    else if(tab[x][y][0] == INF)
    {
        tab[x][y][0] = odl+1;
        tab[x][y].push_back(ac);
        (*Q).push( make_pair( Point( x,y ), ac) );
    }
}

int &Area::operator[](Point p)
{
    return this->mPopulation[p.getX()][p.getY()];
}

int Area::getSumOfPeople()
{
    return mSumOfPeople;
}

int** Area::getPopulation() {
    return mPopulation;
}

int Area::getTemple() {
    return mTemple;
}

void Area::setTemple(int temple) {
    mTemple = temple;
}

Area::Area() {
    mSize = SIZE;
    mPopulation = new int*[SIZE]; //domyslny rozmiar
    for(int i=0; i<SIZE; i++)
        mPopulation[i] = new int[SIZE];
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
}

void Area::generatePopulation() // O(mSize^3)
{
    int a = 0;
    for (int k = 0; k < mSize / 2; ++k) { //zeby w centrum miasta bylo wiecej ludzi
        for (int i = k; i < mSize - k; ++i) {
            for (int j = k; j < mSize - k; ++j) {
                int r = rand() % 5 + 1;
                mSumOfPeople += r;
                mPopulation[i][j] += r;

            }
        }
    }
}

void Area::populationToStation( vector <Station*> stations ) //Zrobic przejscie area w area
{
    for(int i=0; i<stations.size(); ++i)
        stations[i]->setPeople(0);

    vector <int> ** tab = new vector<int>* [mSize];
    for(int i=0; i<mSize; ++i)
        tab[i] = new vector<int> [mSize];

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

            add(p.getX()-1, p.getY(), ac, tab[p.getX()][p.getY()][0], mSize, tab, &Q);
            add(p.getX()+1, p.getY(), ac, tab[p.getX()][p.getY()][0], mSize, tab, &Q);
            add(p.getX(), p.getY()-1, ac, tab[p.getX()][p.getY()][0], mSize, tab, &Q);
            add(p.getX(), p.getY()+1, ac, tab[p.getX()][p.getY()][0], mSize, tab, &Q);
        }
    }

/////////////////////////////////////////////// ^ przerobic mape na mape

    for(int i=0; i<mSize; ++i)
        for(int j=0; j<mSize; ++j)
            for(int k=1; k<tab[i][j].size(); ++k)
                (*stations[ tab[i][j][k] ]) += mPopulation[i][j] / (tab[i][j].size()-1);
}