#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
#include <ostream>
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
        //Graph( Graph g );
        Graph(int);
        Graph(int,int);
        ~Graph();
        //void set_stations_amount(int);
        int getStationsAmount();
        //void set_stretches_amount(int);
        int getStretchesAmount();

        int GraphLen1();
        int GraphLen2(int j);
        int StationsLen();
        int ConnectionsLen();

        void printGraphElem(int j, int k);
        void printStationsElem(int j);
        void printConnectionsElem(int j);

        Area* getArea();
        void addStation();
        void addStation(string, int, int, int);
        void addStretch();
        void addStretch(int, int, int);
        void toOnePoint(int);
        void DFS(int, int);
        void DFS2(bool*, int*, int, int, int);
        vector < Station* > getStations();
        vector < Stretch* > getStretches();
        void show();
        void action();
        void populationToStation();
        int* Dijkstra(int);


    //float ???????
};
#endif
