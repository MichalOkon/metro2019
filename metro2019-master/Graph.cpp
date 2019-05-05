#include <iostream>
#include <vector>
#include "Graph.h"
#include "Station.h"
#include "Stretch.h"

using namespace std;

/*void Graph::set_stations_amount(int statio)
{
    if(this->stations.size() > statio) //gdyby ktos chcial ustalic mniej stacji niz juz jest
    {
        cout << "ERROR" << endl;
        return;
    }
    else
        this->mStationsAmount = statio;
    return;
}*/

int Graph::getStationsAmount()
{
    return this->stations.size();
}

/*void Graph::set_stretches_amount(int stre)
{
    if(this->connections.size() > stre) //jesli ktos by chcial ustawic mniej polaczen niz juz jest
    {
        cout << "ERROR" << endl;
        return;
    }
    else
        this->mStretchesAmount = stre;
    return;
}*/

int Graph::getStretchesAmount()
{
    return this->connections.size();
}

void Graph::addStation() //wczytanie wartosci wewnatrz funkcji
{
    int name, people, x, y;
    cout << "Podaj nazwa, ilosc ludzi i wspolrzedne stacji" << endl;
    cin >> name >> people >> x >> y;
    Station * newStation = new Station(name,people,x,y);
    vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tablicy stacji
}

void Graph::addStation(int name, int people, int x, int y)
{
    Station* newStation = new Station(name,people,x,y);
    vector < Stretch* > v; //tu bede polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tabliy stacji
}

void Graph::addStretch() //wczytuje parametry wewnatrz
{
    int from, to, howMany;
    cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
    cin >> from >> to >> howMany;
	Stretch * str = new Stretch(this->connections.size(), howMany, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::addStretch(int from, int to, int how_many) //przyjmuje parametry z zewnatrz
{
    Stretch * str = new Stretch(this->connections.size(), how_many, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::DFS(int parent, int u)
{
	for(unsigned int i=0; i<this->graph[u].size(); i++)
	{
		if(this->graph[u][i]->getTo(u).mName == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->getTo(u).mName]->mPeople - this->graph[u][i]->getPass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			stations[u]->mPeople += graph[u][i]->getPass();
			stations[this->graph[u][i]->getTo(u).mName]->mPeople -= this->graph[u][i]->getPass();
		}
		else
		{//jesli jest mniej niz przepustowosc
			stations[u]->mPeople += stations[graph[u][i]->getTo(u).mName]->mPeople;
			stations[this->graph[u][i]->getTo(u).mName]->mPeople = 0;
		}
		DFS(u, this->graph[u][i]->getTo(u).mName);//schodzimy nizej
	}
}

void Graph::toOnePoint(int dest) //dest -> swiatynia
{
	this->DFS(dest, dest);
}

vector < Station* >  Graph::getStations()
{
    return this->stations;
}

vector < Stretch* >  Graph::getStretches()
{
    return this->connections;
}

void Graph::show()
{    
    for(int i=1; i < this->stations.size(); ++i)
        cout << this->stations[i]->mName << " " << this->stations[i]->mPeople << endl;
    return;
}