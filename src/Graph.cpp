#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include "../include/Graph.h"
#include "../include/Station.h"
#include "../include/Stretch.h"
#include "../include/Area.h"
#define INF 1000000000 //10^9
#define SIZE 10

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
// little bug - if user adds a wrong station, he can't retry in this iteration
// stations to add : n -> n - 1
void Graph::addStation() //wczytanie wartosci wewnatrz funkcji
{
    int id, x, y;
    string name, sX, sY;
    

    bool breakFlag = false;

    id = mStationsAmount++;
    Station * newStation;

    // pyta do skutku o prawidłowe dane (name, X, Y)
    while(true) {

        // waliduje, czy nie wystąpiło przypadkiem wykroczenie poza planszę
        try {

            cout << "Podaj nazwe i wspolrzedne stacji" << endl;

            cin >> name >> sX >> sY;
            cout << endl;
            x = stoi(sX);
            y = stoi(sY);

            if ((x < 0 || x >= SIZE) || (y < 0 || y >= SIZE)) {
                throw "Index out of range.";
            }

            newStation = new Station(id,name,0,x,y);

        } catch (const char* msg) {
            cout << msg << endl;
            cout << "Try again. Use correct data this time" << endl;
            continue;
        } catch (std::exception &ex) {
            cout << "I wasn't expected a string (strings) as a station's coordinates. Try again...\n" << endl;
            continue;
        }
        break;
    }
    
    // jeśli stacje mają to samo imię czy są położone w tym samym punkcie - to wywala
    // bug - nie prosi o ponowne wprowadzenie -> można nie wprowadzić żadnej stacji
    
    for (int i = 0; i < stations.size(); i++) {
        if (stations[i]->isSimilar(newStation)) {
            delete newStation;
            mStationsAmount--;
            cout << "Sorry, there is a station of an exact name or in the point you want to create a new one.\n" << endl;
            breakFlag = true;
            break;
        }
    }

    if (!breakFlag) {
        vector < Stretch* > v; //tu beda polaczenia tej stacji z innymi
        graph.push_back(v);
        stations.push_back(newStation); //do tablicy stacji
        stringToID.insert( make_pair(name,id) );
    }
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
    string sFrom, sTo, sHowMany;
    int from, to;

    int id = mStretchesAmount++;
    // cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
    Stretch * str; //= new Stretch(1000, 0, nullptr, nullptr);

    // do skutku prosi wprowadzić prawidłowe dane
    while(true) {
        
        // łapie wyjątki - polaczenie stacji samą z sobą;
        //               - połączenie z nieistniejącą stacją lub między nieistniejącymi stacjami
        // 
        try {

            cout << "Podaj skad, dokad i jaka przepustowosc" << endl;
            cin >> sFrom >> sTo >> sHowMany;

            if (!stExists(sFrom) || !stExists(sTo)) {
                throw "At least one of the stations do not exist. Try again...";
                // add here a flag stop adding next stations and repeat until valid
                break;
            } else if (sFrom.compare(sTo) == 0) {
                throw "You can't connect a station with itself. Try again...";
            }

            from = stringToID[sFrom];
            to = stringToID[sTo];
            str = new Stretch(id, howMany, stations[from], stations[to]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)

            howMany = stoi(sHowMany);

        } catch (const char* msg) {
            cout << msg << endl;
            continue;
        }
        catch (std::exception &ex) {
            cout << "Enter integer capacity! Try again..." << endl;
            continue;
        }
        break;
    }
    ///////////////na razie from i to sa wartosciami mID; TODO: przejscie mName -> mID
	
    // Ta część do wyłapania, jeśli podobne połączenie już istnieje
    bool breakFlag = false;

    for (int i = 0; i < connections.size(); i++) {
        if (connections[i]->sameDir(str)) {
            delete str;
            mStretchesAmount--;
            cout << "Nie moge dodac polaczenia, gdyz podobne juz istnieje" << endl;
            breakFlag = true;
            break;
        }
    }


    if (!breakFlag) {
        graph[from].push_back(str);
	    graph[to].push_back(str);
	    connections.push_back(str); //tablica polaczen
    }
	
}

// TODO: adapt station checker for this function

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
		if(graph[u][i]->getToorFrom(u)->getID() == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->getToorFrom(u)->getID()]->getPeople() - graph[u][i]->getPass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			int help = stations[u]->getPeople() + graph[u][i]->getPass();
            stations[u]->setPeople(help);
            help = stations[graph[u][i]->getToorFrom(u)->getID()]->getPeople() - graph[u][i]->getPass();
			stations[graph[u][i]->getToorFrom(u)->getID()]->setPeople(help);
		}
		else
		{//jesli jest mniej niz przepustowosc
            int help = stations[u]->getPeople() + stations[graph[u][i]->getToorFrom(u)->getID()]->getPeople();
            stations[u]->setPeople(help);
			stations[graph[u][i]->getToorFrom(u)->getID()]->setPeople(0);
		}
		DFS(u, graph[u][i]->getToorFrom(u)->getID());//schodzimy nizej
	}
}

void Graph::DFS2(bool* was, int* dist, int parent, int u, int dest)
{
    if( was[u] )
        return;
    was[u] = true;
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->getToorFrom(u)->getID() == parent || was[graph[u][i]->getToorFrom(u)->getID() ] ) //zeby sie nie cofac
			continue;

        if(dist[u] + graph[u][i]->getTime() == dist[graph[u][i]->getToorFrom(u)->getID() ]) //jesli odleglosc bylaby wieksza niz ta wyliczona z Dijkstry to nie ma co sprawdzac
        {
    		if(stations[graph[u][i]->getToorFrom(u)->getID()]->getPeopleToStation(dest) - graph[u][i]->getPass() >= 0)
	    	{//jest na stacji jest wiecej ludzi niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, graph[u][i]->getPass() );
                stations[graph[u][i]->getToorFrom(u)->getID()]->modifyPeopleToStation( dest, (-1)*graph[u][i]->getPass() );
		    }
    		else
	    	{//jesli jest mniej niz przepustowosc
                stations[u]->modifyPeopleToStation( dest, stations[graph[u][i]->getToorFrom(u)->getID()]->getPeopleToStation(dest) );
    			stations[graph[u][i]->getToorFrom(u)->getID()]->modifyPeopleToStation(dest, (-1)*stations[graph[u][i]->getToorFrom(
                        u)->getID()]->getPeopleToStation(dest));
	    	}
            DFS2(was, dist, u, graph[u][i]->getToorFrom(u)->getID(), dest);//schodzimy nizej
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
            if( dist[graph[s][i]->getToorFrom(s)->getID() ] == INF )
                Q.push(make_pair( (-1)*(currentDistance + graph[s][i]->getTime()), graph[s][i]->getToorFrom(s)->getID() ));
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

//checks if a stations exists in graph
bool Graph::stExists(std::string sName) {
    bool answer = false;
    for (int i = 0; i < mStationsAmount; i++) {
        if (sName == stations[i]->getName()) {
            answer = true;
            break;
        }
    }
    return answer;
}

void Graph::show()
{
    for(unsigned int i=0; i < stations.size(); ++i)
        cout << stations[i]->getName() << " " << stations[i]->getPeople() << endl; //valgrind mowi, ze jest blad w getPeople(), a raczej w populationToStation()
    return;
}

