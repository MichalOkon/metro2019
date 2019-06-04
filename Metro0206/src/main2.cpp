#include <iostream>
#include "../include/Menu.h"
#include "../include/Parser.h"
#include "../include/Graph.h"

using namespace std;

int main() {

    Graph city(10);
    Graphics drawer(&city);
    Display shower(&city);
    SL saver(&city);

    Menu * menu = new Menu(&city);
    menu->greetUsers();
    menu->showOptions();

    Parser * parser = new Parser(&city);
    int n = 0;
    std::string sInt;

    parser->safeInsertInt(&n);

    if (n == 1) {
        menu->safeLoad(saver, "saved.txt");
    } else if (n == 2) {
        menu->fillGraph(&city, parser);
    }

    
    shower.stationsInfo();
    system("pause");

    menu->makeFun(&shower, &drawer, &saver, parser);

    // OTHER STUFF LIKE PLAYING SIMULATION
    

    // string str = n == 2 ? "Two" : "One";
    
    cout << "Current stations amount: " << city.getStretchesAmount() << endl;
    // cout << "Size of stations vect: " << city.getStations().size() << endl;

    // cout << str << endl;


}