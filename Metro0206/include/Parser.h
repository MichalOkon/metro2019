#ifndef PARSER_H
#define PARSER_H

#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include "Graph.h"
#include "Station.h"
#include "Stretch.h"

using namespace std;

class Parser {

    public:

        Graph * mGraph;
        Parser(Graph * g);
        Parser();
        ~Parser();

        void insertStation();
        void insertStretch();
        bool parseStation(string sName, string sX, string sY, int * x, int * y); // parses Station
        bool parseStretch(string from, string to, string sHowMany, int * howMany); // parses Stretch
        bool stCheckName(string name); // checks if station candidate has the exact name like a one on the list
        bool checkPoint(int x, int y); // checks if the point is empty
        bool stCheckCoords(int x, int y); // checks if coords of the station are correct
        bool checkSelfConn(string from, string to); // checks if station is connected with itself
        bool checkConnNumber(int n); // checks if the number of connections is <= than (n - 1) * n / 2
        bool checkConnEmpty(std::string s1, std::string s2); // checks if all the stations exist: can't add (empty->st), (st->empty), (empty->empty)
        bool isConnExist(string s1, string s2); // checks is connection between two stations exists
        bool stExists(std::string sName);
        int parseInt(std::string sInt);
        bool safeInsertInt(int* i); // wczytuje inta bezpiecznie
        void safeNumStretches(int * i);
        bool hasAnyDigits(std::string s);
};

#endif