#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
#include "Stretch.h"
#include "Station.h"
#include "Area.h"

using namespace std;

class Graph
{
    vector < vector < Stretch* > > graph;
    vector < Station* > stations;
    vector < Stretch* > connections;
    Area* city = nullptr;
	int mStationsAmount = 0;
    int mStretchesAmount = 0;

    public:
        Graph();
        Graph(int);
        Graph(const Graph* copied);
        Graph(int,int);
        ~Graph();
        void graphStart(int s);
        //void set_stations_amount(int);
        int getStationsAmount();
        //void set_stretches_amount(int);
        int getStretchesAmount();
        Area* getArea();
        void addStation();
        void addStation(string, int, int, int);
        void addStretch();
        void addStretch(int, int, int);
        void addStretch(std::string, std::string, int);
        void toOnePoint(int);
        void DFS(int, int);
        void DFS2(bool*, int*, int, int, int);
        vector < Station* > getStations();
        vector < Stretch* > getStretches();
        void show();
        void action();
        void populationToStation();
        int* Dijkstra(int); //float ???????
        void saveMetro(string name = "saved.txt");//saves metro map
        bool loadMetro(string name = "saved.txt");//loads metro map return false if failed
        bool stExists(std::string sName);
};
#endif
