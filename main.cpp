#include <iostream>
#include <vector>

#include "stretch.cpp"
//#include "Area.cpp"

using namespace std;

Station Station::operator<<(Station &obj)
{
	
}

vector <vector< stretch* > > graph;
vector <Station> stations; //przechowuje kazda stacje (ilosc ludzi, wspolrzedne itp.)

void DFS(int parent, int u)
{
	for(unsigned int i=0; i<graph[u].size(); i++)
	{
		if(graph[u][i]->Getto(u).mName == parent) //zeby sie nie cofac
			continue;

		if(stations[graph[u][i]->Getto(u).mName].mPeople - graph[u][i]->Getpass() >= 0)
		{//jest na stacji jest wiecej ludzi niz przepustowosc
			stations[u].mPeople += graph[u][i]->Getpass();
			stations[graph[u][i]->Getto(u).mName].mPeople -= graph[u][i]->Getpass();
		}
		else
		{//jesli jest mniej niz przepustowosc
			stations[u].mPeople += stations[graph[u][i]->Getto(u).mName].mPeople;
			stations[graph[u][i]->Getto(u).mName].mPeople = 0;
		}
		DFS(u, graph[u][i]->Getto(u).mName);//schodzimy nizej
	}
}

void to_one_point(int dest) //dest -> swiatynia
{
	DFS(dest, dest);
}

int get_max_id() //ile jest wszystkich stacji
{
	int a;
	cin >> a;
	return a;
}

inline void init()
{
	stations.push_back( Station(0,0,Point(0,0,0) ) ); //stacje numerujemy od 1, wiec wrucamy cokolwiek do komorki 0
	vector <stretch* > v0; //stacje numerujemy od 1, wiec wrucamy cokolwiek do komorki 0
	graph.push_back(v0); //stacje numerujemy od 1, wiec wrucamy cokolwiek do komorki 0

	int station_amount = get_max_id();
	for(int i=0; i<station_amount; i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		Point newPoint(c,d,i+1); //nowy punkt dla stacji
		Station newStation(a,b,newPoint); //nowa stacja
		vector < stretch* > v; //vector na wskazniki polaczen z dana stacja
		graph.push_back(v); //wrzucamy ten vector do grafu, ktory przechowuje wszystkie vectory
		stations.push_back(newStation);
	}
}

inline void clear_all()
{
	for(int i=0; i<graph[i].size(); ++i)
		graph[i].clear();
	graph.clear();
	stations.clear();
}

int main()
{
	init();
	vector <stretch*> connections;
	int stretch_amount;
	cin >> stretch_amount;
	for(int i=0; i<stretch_amount; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		stretch * str = new stretch(i,c,stations[a],stations[b]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
		graph[a].push_back(str);
		graph[b].push_back(str);
		connections.push_back(str);
	}
	int days;
	cin >> days;

	cout << "day 0" << endl;
	for(int i=0; i<stations.size(); i++)
		cout << stations[i].mName << " " << stations[i].mPeople << endl;

	for(int j=0; j<days; j++)
	{
		to_one_point(2); //2 jest swiatynia
		cout << "day " << j+1 << endl;
		for(int i=0; i<stations.size(); i++)
		{
			cout << stations[i].mName << " " << stations[i].mPeople << endl;
		}
		cout << endl;
	}

	for(int i=0; i<connections.size(); ++i)
		delete connections[i];
	clear_all();
	return 0;
}
