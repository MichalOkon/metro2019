#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Graph.h"
#include "SaveAndLoad.h"
#include "Graphics.h"
#include "Display.h"
#include "Parser.h"
using namespace std;

class Menu {

    Graph* mCity;
    public:
        Menu();
        ~Menu();
        Menu(Graph * g);
        Graph* getCity();
        void setCity(Graph* g);
        void greetUsers();
        void showOptions();
        void safeLoad(SL saver, string filename);
        void fillGraph(Graph * g, Parser * parser);
        char singleCharInp(string input);
        void makeFun(Display * drawer, Graphics * shower, SL * saver, Parser* parser);
};

#endif