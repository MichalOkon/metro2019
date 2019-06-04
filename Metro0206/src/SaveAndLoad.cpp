//
// Created by micha on 22.05.2019.
//

#include "../include/SaveAndLoad.h"


void SL::saveMetro(const string& name){
    ofstream file;
    file.open(name, ofstream::out);

    file << mGraph->getArea()->getSize() << endl;
    file << mGraph->getStations().size() << endl;

    for(auto i: mGraph->getStations()){
        file << i->getName() << endl;
        file << i->getPeople() << endl;
        file << i->getPoint()->getX() << endl;
        file << i->getPoint()->getY() << endl;
    }

    file << mGraph->getStretches().size() << endl;

    for(auto i: mGraph->getStretches()){
        file << i->getTo()->getID() << endl;
        file << i->getFrom()->getID() << endl;
        file << i->getPass() << endl;
    }

}


void SL::loadMetro(string name, Graph* graph){
    ifstream file;
    file.open(name, ifstream::in);

    if(!file.good()){
        abort();
    }

    int asize;
    int stanumb;
    file >> asize;
    file >>stanumb;

    graph->graphStart(asize);

    for (int i = 0; i < stanumb; i++){
        string sname;
        file >> sname;

        int people;
        file >> people;

        int x, y;
        file >> x >> y;

        graph->addStation(sname, people, x, y);
    }

    int strnumb;
    file >> strnumb;
    for (int i = 0; i < strnumb; i++){
        int toID;
        file >> toID;
        int fromID;
        file >> fromID;
        int pass;
        file >> pass;

        graph->addStretch(fromID, toID, pass);

    }

    file.close();

}

void SL::savePop(const string& name){

    ofstream file;
    file.open(name, ofstream::out);

    for(int i = 0; i<mGraph->getArea()->getSize(); i++){
        for (int j = 0; j < mGraph->getArea()->getSize(); j++)
            file << mGraph->getArea()->getPopulation()[i][j] << endl;
    }

    file.close();
}

void SL::loadPop(const string &name) {

    ifstream file;
    file.open(name, ifstream::in);

    for(int i = 0; i<mGraph->getArea()->getSize(); i++) {
        for (int j = 0; j < mGraph->getArea()->getSize(); j++) {
            int value;
            file >> value;
            mGraph->getArea()->setPop(i, j, value);
        }
    }
    file.close();

    mGraph->populationToStation();
}