#include <iostream>
#include <vector>

#include "graph.h"

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

int Graph::get_stations_amount()
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

int Graph::get_stretches_amount()
{
    return this->connections.size();
}

void Graph::add_station() //wczytanie wartosci wewnatrz funkcji
{
    int name,people,x,y;
    cout << "Podaj nazwa, ilosc ludzi i wspolrzedne stacji" << endl;
    cin >> name >> people >> x >> y;
    Station * newStation = new Station(name,people,x,y);
    vector < stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tablicy stacji
}

void Graph::add_station(int name, int people, int x, int y)
{
    Station* newStation = new Station(name,people,x,y);
    vector < stretch* > v; //tu bede polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tabliy stacji
}

void Graph::add_stretch() //wczytuje parametry wewnatrz
{
    int from, to, how_many;
    cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
    cin >> from >> to >> how_many;
	stretch * str = new stretch(this->connections.size(), how_many, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::add_stretch(int from, int to, int how_many) //przyjmuje parametry z zewnatrz
{
    stretch * str = new stretch(this->connections.size(), how_many, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::DFS(int parent, int u)
{
	for(unsigned int i=0; i<this->graph[u].size(); i++)
	{
		if(this->graph[u][i]->Getto(u).mName == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->Getto(u).mName]->mPeople - this->graph[u][i]->Getpass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			stations[u]->mPeople += graph[u][i]->Getpass();
			stations[this->graph[u][i]->Getto(u).mName]->mPeople -= this->graph[u][i]->Getpass();
		}
		else
		{//jesli jest mniej niz przepustowosc
			stations[u]->mPeople += stations[graph[u][i]->Getto(u).mName]->mPeople;
			stations[this->graph[u][i]->Getto(u).mName]->mPeople = 0;
		}
		DFS(u, this->graph[u][i]->Getto(u).mName);//schodzimy nizej
	}
}

void Graph::to_one_point(int dest) //dest -> swiatynia
{
	this->DFS(dest, dest);
}

vector < Station* > * Graph::get_stations()
{
    return &(this->stations);
}

vector < stretch* > * Graph::get_stretches()
{
    return &(this->connections);
}

void Graph::show()
{    
    for(int i=1; i < this->stations.size(); ++i)
        cout << this->stations[i]->mName << " " << this->stations[i]->mPeople << endl;
    return;
}