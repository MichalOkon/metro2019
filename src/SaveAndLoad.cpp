//
// Created by micha on 22.05.2019.
//

#include "../include/SaveAndLoad.h"

void SL::saveMetro(string name){
    ofstream file;
    file.open(name, ofstream::out);

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


bool SL::loadMetro(string name){
    ifstream file;
    file.open(name, ifstream::in);

    if(!file.good()){
        return false;
    }

    int stanumb;
    file >> stanumb;

    for (int i = 0; i < stanumb; i++){
        string sname;
        file >> sname;

        int people;
        file >> people;

        int x, y;
        file >> x >> y;

        mGraph->addStation(sname, people, x, y);
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

        mGraph->addStretch(fromID, toID, pass);

    }
    return true;

}