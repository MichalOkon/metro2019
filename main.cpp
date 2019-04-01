#include <iostream>
#include <vector>
#include "include/Station.h"
//#include "stretch.cpp"

using namespace std;

//vector <vector<pair<int,int> > > graph;
//vector <Station> stations; //przechowuje kazda stacje (ilosc ludzi, wspolrzedne itp.)
//
//void DFS(int parent, int u)
//{
//    for(unsigned int i=0; i<graph[u].size(); i++)
//    {
//        if(graph[u][i].first == parent)
//            continue;
//
//        if(stations[graph[u][i].first].people - graph[u][i].second >= 0)
//        {
//            stations[u].people += graph[u][i].second;
//            stations[graph[u][i].first].people -= graph[u][i].second;
//        }
//        else
//        {
//            stations[u].people += stations[graph[u][i].first].people;
//            stations[graph[u][i].first].people = 0;
//        }
//        DFS(u, graph[u][i].first);
//    }
//}
//
//void to_one_point(int dest) //dest -> swiatynia
//{
//    DFS(dest, dest);
//}
//
//inline int get_max_id() //ile jest wszystkich stacji
//{
//    cout << "ILE STACJI" << endl;
//    int a;
//    cin >> a;
//    return a;
//}
//
//inline void init()
//{
//    int station_amount = get_max_id();
//    for(int i=0; i<station_amount; i++)
//    {
//        int a,b,c,d;
//        Point newPoint(c,d);
//        Station newStation(a,b,newPoint);
//        vector <pair<int,int> > v;
//        graph.push_back(v);
//        stations.push_back(newStation);
//    }
//}



int main()
{
//    Point *p = new Point(1, 1);
//    Station *s = new Station(30, 10, p);
//    cout << *s <<endl;
//    s->setPeople(100);
//    cout << *s <<endl;

//    vector <Station> stations;
//    vector <vector<pair<int,int> > > graph;

    //////////////////////////////  int stretch_amount = get_stretch_amount();
//    int stretch_amount = 5;
//    for(int i=0; i<stretch_amount; i++)
//    {
//        //      int a = get_from();
//        //      int b = get_to();
//        //      int c = get_pass();
//        int a,b,c; cin >> a >> b >> c;
//        graph[a].push_back(make_pair(b,c));
//        graph[b].push_back(make_pair(a,c));
//    }

///stations[];

    return 0;
}
