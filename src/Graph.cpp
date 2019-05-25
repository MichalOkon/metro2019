#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include "../include/Graph.h"
#include "../include/Station.h"
#include "../include/Stretch.h"
#include "../include/Area.h"
#define INF 1000000000 //10^9

using namespace std;

map <string, int> stringToID;

/////////////////////////////////  constructors
Graph::Graph(int s) //generuje Area o rozmiarze s X s
{
    city = new Area(s);
    //city->generatePopulation();
}

Graph::Graph(int statio, int stret)
{
        //city->generatePopulation();
        mStationsAmount = statio;
        mStretchesAmount = stret;
        for(int i=0; i<statio; ++i)
            this->addStation();
        for(int i=0; i<stret; ++i)
            this->addStretch();
}

Graph::~Graph()
{
    for(int i=0; i<graph[i].size(); ++i)
        graph[i].clear();
    graph.clear();
    for(int i=0; i<stations.size(); ++i)
        delete stations[i];
    stations.clear();
    for(int i=0; i<connections.size(); ++i)
        delete connections[i];
    connections.clear();
    if( city != nullptr )
        delete city;
}

////////////////////////////////////////////// getters
vector < Station* >  Graph::getStations()
{
    return this->stations;
}

vector < Stretch* >  Graph::getStretches()
{
    return this->connections;
}

int Graph::getStationsAmount()
{
    return this->mStationsAmount;
}

int Graph::getStretchesAmount()
{
    return this->mStretchesAmount;
}

Area* Graph::getArea()
{
    return this->city;
}

///////////////////////////////////////////////// adders
void Graph::addStation() //wczytanie wartosci wewnatrz funkcji
{
    int id, x, y;
    string name;
    cout << "Podaj nazwe i wspolrzedne stacji" << endl;
    cin >> name >> x >> y;
    id = mStationsAmount++;
    Station * newStation = new Station(id,name,0,x,y);
    vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tablicy stacji
    stringToID.insert( make_pair(name,id) );
}

void Graph::addStation(string name, int people, int x, int y)
{
    int id = mStationsAmount++;
    Station* newStation = new Station(id,name,people,x,y);
    vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tabliy stacji
    stringToID.insert( make_pair(name,id) );
}

void Graph::addStretch() //wczytuje parametry wewnatrz
{
    int howMany;
    string sFrom, sTo;
    int from, to;
    cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
    cin >> sFrom >> sTo >> howMany; ///////////////na razie from i to sa wartosciami mID; TODO: przejscie mName -> mID
	from = stringToID[sFrom];
    to = stringToID[sTo];
    Stretch * str = new Stretch(mStretchesAmount++, howMany, stations[from], stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::addStretch(int from, int to, int how_many) //przyjmuje parametry z zewnatrz
{
    Stretch * str = new Stretch(mStretchesAmount++, how_many, stations[from], stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

/////////////////////////////////////////// helping
void Graph::DFS(int parent, int u)
{
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->getToorFrom(u).getID() == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->getToorFrom(u).getID()]->getPeople() - graph[u][i]->getPass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			int help = stations[u]->getPeople() + graph[u][i]->getPass();
            stations[u]->setPeople(help);
            help = stations[graph[u][i]->getToorFrom(u).getID()]->getPeople() - graph[u][i]->getPass();
			stations[graph[u][i]->getToorFrom(u).getID()]->setPeople(help);
		}
		else
		{//jesli jest mniej niz przepustowosc
            int help = stations[u]->getPeople() + stations[graph[u][i]->getToorFrom(u).getID()]->getPeople();
            stations[u]->setPeople(help);
			stations[graph[u][i]->getToorFrom(u).getID()]->setPeople(0);
		}
		DFS(u, graph[u][i]->getToorFrom(u).getID());//schodzimy nizej
	}
}

void Graph::DFS2(bool* was, int* dist, int parent, int u, int dest)
{
    if( was[u] )
        return;
    was[u] = true;
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->getToorFrom(u).getID() == parent || was[graph[u][i]->getToorFrom(u).getID() ] ) //zeby sie nie cofac
			continue;

        if(dist[u] + graph[u][i]->getTime() == dist[graph[u][i]->getToorFrom(u).getID() ]) //jesli odleglosc bylaby wieksza niz ta wyliczona z Dijkstry to nie ma co sprawdzac
        {
    		if(stations[graph[u][i]->getToorFrom(u).getID()]->getPeopleToStation(dest) - graph[u][i]->getPass() >= 0)
	    	{//jest na stacji jest wiecej ludzi niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, graph[u][i]->getPass() );
                stations[graph[u][i]->getToorFrom(u).getID()]->modifyPeopleToStation( dest, (-1)*graph[u][i]->getPass() );
		    }
    		else
	    	{//jesli jest mniej niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, stations[graph[u][i]->getToorFrom(u).getID()]->getPeopleToStation(dest) );
    			stations[graph[u][i]->getToorFrom(u).getID()]->modifyPeopleToStation(dest, (-1)*stations[graph[u][i]->getToorFrom(
                        u).getID()]->getPeopleToStation(dest));
	    	}
            DFS2(was, dist, u, graph[u][i]->getToorFrom(u).getID(), dest);//schodzimy nizej
        }
    }
}

int* Graph::Dijkstra(int statio) //na wikipedii jest dobre wytlumaczenie
{
    int* dist = new int[mStationsAmount];
    for(int i=0; i < mStationsAmount; ++i)
        dist[i] = INF;
    
    priority_queue < pair<int,int> > Q;
    Q.push(make_pair(0,statio));
    while(!Q.empty())
    {
        int currentDistance = Q.top().first * (-1); //wszystko razy -1, zeby kolejnosc w priority queue byla dobra
        int s = Q.top().second; //biezemy stacje, ktora jest najblizej poczatku i z niej wychodzimy we wszystkie kierunki
        Q.pop();
        if(dist[s] == INF)
            dist[s] = currentDistance;
        else
            continue;

        for(int i=0; i < graph[s].size(); ++i)
            if( dist[graph[s][i]->getToorFrom(s).getID() ] == INF )
                Q.push(make_pair( (-1)*(currentDistance + graph[s][i]->getTime()), graph[s][i]->getToorFrom(s).getID() ));
    }
    return dist;
}

/////////////////////////////////// skuteczne
void Graph::action() //jedno przejscie w grafie, ktory moze byc cyklicznys
{
    for(int i=0; i<mStationsAmount; ++i)
    {
        //return;
        int* dist = this->Dijkstra(i); //dlugosc najkrotszej drogi na grafie wazonym
        bool* was = new bool[mStationsAmount]; //czy dana stacja juz byla
        for(int i=0; i<mStationsAmount; ++i)
            was[i] = false;
        //return;
        DFS2(was, dist, i, i, i); //specjalny DFS
        
        //return;
        delete[] dist;
        delete[] was;
    }
    for(int i=0; i<mStationsAmount; ++i) //aktualizuje mPeople dla kazdej stacji na podstawie mPeopleToStation
        stations[i]->updatePeople();
}

void Graph::populationToStation()
{
    city->populationToStation( this->stations ); //dla kazdej stacji mowi ile ludzi na niej jest (na podst mapy z Area)
    int sum = city->getSumOfPeople();

    vector <float> ratio; //przechowuje ulamki ile % ludzi chce dotrzec do stacji 'i' -> ratio[i]
    for(int i=0; i<stations.size(); ++i)
    {
        ratio.push_back( ((float)stations[i]->getPeople() / sum) ); ////// TODO: opracowac lepszy podzial ludzi
    }
    for(int i=0; i<stations.size(); ++i)
        stations[i]->setPeopleToStation( &ratio ); //daje tablice ulamkow do metody, ona tam mnozy razy ilosc ludzi i zapisuje w station
}

void Graph::toOnePoint(int dest) //dest -> swiatynia
{
	this->DFS(dest, dest);
}

void Graph::show()
{
    for(unsigned int i=0; i < stations.size(); ++i)
        cout << stations[i]->getName() << " " << stations[i]->getPeople() << endl; //valgrind mowi, ze jest blad w getPeople(), a raczej w populationToStation()
    return;
}

