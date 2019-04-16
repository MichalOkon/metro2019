#include <vector>
#include "stretch.cpp"

using namespace std;

class Graph
{
    vector < vector < stretch* > > graph;
    vector < Station* > stations;
    vector < stretch* > connections;
	int mStationsAmount;
    int mStretchesAmount;

    public:
        Graph()
        {
            Station * s0 = new Station();
            stations.push_back(s0);
            vector < stretch* > v0;
            graph.push_back(v0);
        }
        Graph(int statio, int stret)
        {
            mStationsAmount = statio;
            mStretchesAmount = stret;
            Station * s0 = new Station();
            stations.push_back(s0);
            vector < stretch* > v0;
            graph.push_back(v0);
        }
        ~Graph()
        {
            for(int i=0; i<connections.size(); ++i)
                delete connections[i];
            for(int i=0; i<graph[i].size(); ++i)
                graph[i].clear();
            graph.clear();
            stations.clear();
        }
        //void set_stations_amount(int);
        int get_stations_amount();
        //void set_stretches_amount(int);
        int get_stretches_amount();
        void add_station();
        void add_station(int, int, int, int);
        void add_stretch();
        void add_stretch(int, int, int);
        void to_one_point(int);
        void DFS(int, int);
        vector < Station* > * get_stations();
        vector < stretch* > * get_stretches();
        void show();
};
