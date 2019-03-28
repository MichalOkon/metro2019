#include <iostream>
#include <vector>

#include "stretch.cpp"
#include "Area.cpp"

using namespace std;

vector <vector< stretch* > > graph;
vector <Station> stations; //przechowuje kazda stacje (ilosc ludzi, wspolrzedne itp.)

void DFS(int parent, int u)
{
    for(unsigned int i=0; i<graph[u].size(); i++)
    {
        if(graph[u][i]->Getto(u).mName == parent)
            continue;

        if(stations[graph[u][i]->Getto(u).mName].mPeople - graph[u][i]->Getpass() >= 0)
        {
            stations[u].mPeople += graph[u][i]->Getpass();
            stations[graph[u][i]->Getto(u).mName].mPeople -= graph[u][i]->Getpass();
        }
        else
        {
            stations[u].mPeople += stations[graph[u][i]->Getto(u).mName].mPeople;
            stations[graph[u][i]->Getto(u).mName].mPeople = 0;
        }
        DFS(u, graph[u][i]->Getto(u).mName);
    }
}

void to_one_point(int dest) //dest -> swiatynia
{
    DFS(dest, dest);
}

inline int get_max_id() //ile jest wszystkich stacji
{
    cout << "ILE STACJI" << endl;
    int a;
    cin >> a;
    return a;
}

inline void init()
{
    int station_amount = 5;//get_max_id();
    for(int i=0; i<station_amount; i++)
    {
        int a,b,c,d;
        Point newPoint(c,d,i);
        Station newStation(a,b,newPoint);
        vector < stretch* > v;
        graph.push_back(v);
        stations.push_back(newStation);
    }
}

int main()
{
    init();
    int stretch_amount = 5;
    for(int i=0; i<stretch_amount; i++)
    {
        int a,b,c; cin >> a >> b >> c;
	stretch * str = new stretch(i,c,stations[a],stations[b]); //(id_polaczenia, przepustowosc, stacja_a, stacja_b)
        graph[a].push_back(str);
        graph[b].push_back(str);
    }
    return 0;
}
