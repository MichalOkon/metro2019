#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Graph.h"
#include "Station.h"
#include "Stretch.h"
#include "Area.h"
#define INF 1000000000 //10^9

using namespace std;


/////////////////////////////////  constructors
Graph::Graph(int s)
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
    char name;
    cout << "Podaj nazwe i wspolrzedne stacji" << endl;
    cin >> name >> x >> y;
    id = mStationsAmount++;
    Station * newStation = new Station(id,name,0,x,y);
    vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tablicy stacji
}

void Graph::addStation(char name, int people, int x, int y)
{
    int id = mStationsAmount++;
    Station* newStation = new Station(id,name,people,x,y);
    vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
    graph.push_back(v);
    stations.push_back(newStation); //do tabliy stacji
}

void Graph::addStretch() //wczytuje parametry wewnatrz
{
    int from, to, howMany;
    cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
    cin >> from >> to >> howMany;
	Stretch * str = new Stretch(mStretchesAmount++, howMany, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

void Graph::addStretch(int from, int to, int how_many) //przyjmuje parametry z zewnatrz
{
    Stretch * str = new Stretch(mStretchesAmount++, how_many, *stations[from], *stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
	graph[from].push_back(str);
	graph[to].push_back(str);
	connections.push_back(str); //tablica polaczen
}

/////////////////////////////////////////// helping
void Graph::DFS(int parent, int u)
{
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->getTo(u).getID() == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->getTo(u).getID()]->getPeople() - graph[u][i]->getPass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			int help = stations[u]->getPeople() + graph[u][i]->getPass();
            stations[u]->setPeople(help);
            help = stations[graph[u][i]->getTo(u).getID()]->getPeople() - graph[u][i]->getPass();
			stations[graph[u][i]->getTo(u).getID()]->setPeople(help);
		}
		else
		{//jesli jest mniej niz przepustowosc
            int help = stations[u]->getPeople() + stations[graph[u][i]->getTo(u).getID()]->getPeople();
            stations[u]->setPeople(help);
			stations[graph[u][i]->getTo(u).getID()]->setPeople(0);
		}
		DFS(u, graph[u][i]->getTo(u).getID());//schodzimy nizej
	}
}

void Graph::DFS2(bool* was, int* dist, int parent, int u, int dest)
{
    if( was[u] )
        return;
    was[u] = true;
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->getTo(u).getID() == parent || was[ graph[u][i]->getTo(u).getID() ] ) //zeby sie nie cofac
			continue;

        if(dist[u] + graph[u][i]->getTime() == dist[ graph[u][i]->getTo(u).getID() ])
        {
    		if(stations[graph[u][i]->getTo(u).getID()]->getPeopleToStation(dest) - graph[u][i]->getPass() >= 0)
	    	{//jest na stacji jest wiecej ludzi niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, graph[u][i]->getPass() );
                stations[graph[u][i]->getTo(u).getID()]->modifyPeopleToStation( dest, (-1)*graph[u][i]->getPass() );
		    }
    		else
	    	{//jesli jest mniej niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, stations[graph[u][i]->getTo(u).getID()]->getPeopleToStation(dest) );
    			stations[graph[u][i]->getTo(u).getID()]->modifyPeopleToStation(dest, (-1)*stations[graph[u][i]->getTo(u).getID()]->getPeopleToStation(dest));
	    	}
            DFS2(was, dist, u, graph[u][i]->getTo(u).getID(), dest);//schodzimy nizej
        }
    }
}

int* Graph::Dijkstra(int statio)
{
    int* dist = new int[mStationsAmount];
    for(int i=0; i < mStationsAmount; ++i)
        dist[i] = INF;
    
    priority_queue < pair<int,int> > Q;
    Q.push(make_pair(0,statio));
    while(!Q.empty())
    {
        int currentDistance = Q.top().first * (-1);
        int s = Q.top().second;
        Q.pop();
        if(dist[s] == INF)
            dist[s] = currentDistance;
        else
            continue;

        for(int i=0; i < graph[s].size(); ++i)
            if( dist[ graph[s][i]->getTo(s).getID() ] == INF )
                Q.push(make_pair( (-1)*(currentDistance + graph[s][i]->getTime()), graph[s][i]->getTo(s).getID() ));
    }
    return dist;
}

/////////////////////////////////// skuteczne
void Graph::action()
{
    for(int i=0; i<mStationsAmount; ++i)
    {
        //return;
        int* dist = this->Dijkstra(i);
        bool* was = new bool[mStationsAmount];
        for(int i=0; i<mStationsAmount; ++i)
            was[i] = false;
        //return;
        DFS2(was, dist, i, i, i);
        
        //return;
        delete[] dist;
        delete[] was;
    }
    for(int i=0; i<mStationsAmount; ++i)
        stations[i]->updatePeople();

    this->show();
}

void Graph::populationToStation()
{
    city->populationToStation( this->stations );
    int sum = city->getSumOfPeople();
    vector <float> ratio;
    for(int i=0; i<stations.size(); ++i)
    {
        ratio.push_back( ((float)stations[i]->getPeople() / sum) ); ////// TODO: opracowac lepszy podzial ludzi
    }
    for(int i=0; i<stations.size(); ++i)
        stations[i]->setPeopleToStation( &ratio );
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