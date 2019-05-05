#include <vector>
// #include "Stretch.h"
#include "Stretch.h"
#include "Station.h"


using namespace std;

class Graph
{
    vector < vector < Stretch* > > graph;
    vector < Station* > stations;
    vector < Stretch* > connections;
	int mStationsAmount;
    int mStretchesAmount;

    public:
        Graph()
        {
            Station * s0 = new Station();
            stations.push_back(s0);
            vector < Stretch* > v0;
            graph.push_back(v0);
        }
        Graph(int statio, int stret)
        {
            mStationsAmount = statio;
            mStretchesAmount = stret;
            Station * s0 = new Station();
            stations.push_back(s0);
            vector < Stretch* > v0;
            graph.push_back(v0);
        }
        ~Graph()
        {
            connections.clear();
            for(int i=0; i<graph[i].size(); ++i)
                graph[i].clear();
            graph.clear();
            stations.clear();
        }
        //void set_stations_amount(int);
        int getStationsAmount();
        //void set_stretches_amount(int);
        int getStretchesAmount();
        void addStation();
        void addStation(int, int, int, int);
        void addStretch();
        void addStretch(int, int, int);
        void toOnePoint(int);
        void DFS(int, int);
        vector < Station* > getStations();
        vector < Stretch* > getStretches();
        void show();
};
