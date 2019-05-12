#include <iostream>
#include <cstdlib>

#include "Area.h"
#include "Graph.h"
#include "Test.h"
#include "Display.h"
#include "Graphics.h"


using namespace std;

int main()
{
    int n;
    Graphics g;

    Graph city(10);
    g.drawPop(city.getArea()->getPopulation());


    Display show;
    show.displayPop(city.getArea()->getPopulation());
    show.savePop(city.getArea()->getPopulation());

    cout << "Hello, world" << endl;

    cout << "Gimme stations amount: " << endl;
    cin >> n;

    for(int i=0; i < n; i++)
        city.addStation();

    city.populationToStation();
    city.show();

    cout << "Gimme stretches amount: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
        city.addStretch();

    g.drawMetro(city.getStations(), city.getStretches(), "metro");

    simulateNDays(&city, 20);

    show.displayMetro(city.getStations(), city.getStretches());
    
    return 0;
}
