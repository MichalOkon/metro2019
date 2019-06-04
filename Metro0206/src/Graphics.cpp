#include "../include/Graphics.h"

#include "../include/Area.h"
#include "../include/Simple_svg.hpp"
#include <string>
#include <math.h>

#define WIDTH 100

using namespace svg;



void Graphics::drawPop() {

    int size = mGraph->getArea()->getSize();

    Dimensions dimensions(size * 100, size * 100);
    Document doc("population.svg", Layout(dimensions, Layout::TopLeft));

    Polygon border(Stroke(1, Color::Black));
    border << Spoint(0, 0) << Spoint(dimensions.width, 0)
          << Spoint(dimensions.width, dimensions.height) << Spoint(0, dimensions.height);
    doc << border;

    Polyline lineY(Stroke(0.5, Color::Black));
    Polyline lineX(Stroke(0.5, Color::Black));

    for(int i=0; i<size; ++i){
        for(int j = 0; j< size; ++j){
            doc << Text(Spoint(((WIDTH * (j + 0.35) ) ), (WIDTH * (i + 0.65))),
                    to_string(mGraph->getArea()->getPopulation()[i][j]), Color::Green, Font(40, "Verdana"));
            lineY << Spoint((WIDTH * i) , (WIDTH * j ));
            lineX << Spoint(((WIDTH * j) ), (WIDTH * i ));

            if(j + 1 == size){
                lineY << Spoint((WIDTH * i), WIDTH * (j + 1));
                lineY << Spoint((WIDTH * i), 0);
                lineY << Spoint((WIDTH * (i + 1)), 0);
                lineX << Spoint((WIDTH*(j+1)), (WIDTH * i));
                lineX << Spoint(0,(WIDTH * i ));
            }
        }
    }

    doc << lineX;
    doc << lineY;

    doc.save();

}
//korzystalem z name
void Graphics::drawMetro(){

    mNumber++;
    int size = mGraph->getArea()->getSize();

    Dimensions dimensions(size * 100 + 100, size * 100 + 100);
    Document doc("metro" + to_string(mNumber) + ".svg", Layout(dimensions, Layout::BottomLeft));

    Polygon border(Stroke(1, Color::Black));
    border << Spoint(0, 0) << Spoint(dimensions.width, 0)
           << Spoint(dimensions.width, dimensions.height) << Spoint(0, dimensions.height);
    doc << border;

    for(auto i: mGraph->getStretches()) {

        //a line representing connections between stations
        doc << (Polyline(Stroke(max(2, min(10, i->getPass()/5)), Color::Blue))
        << Spoint(i->getFrom()->getPoint()->getX() * 100 + 50,
                i->getFrom()->getPoint()->getY() * 100 + 50)
                << Spoint(i->getTo()->getPoint()->getX() * 100 + 50,
                        i->getTo()->getPoint()->getY() * 100 + 50));

        //station's throughput
        doc << Text(Spoint(((i->getFrom()->getPoint()->getX() * 100 + 50) +
        i->getTo()->getPoint()->getX() * 100 + 50)/2.0,
                (((i->getFrom()->getPoint()->getY() * 100 + 50)
                + i->getTo()->getPoint()->getY() * 100 + 50)/2.0 + 20)), to_string(i->getPass()),
                    Color::Brown, Font(20, "Verdana"));

    }

    for(auto i: mGraph->getStations()){
        //stations show as circles
        doc << Circle(Spoint(i->getPoint()->getX() * 100 + 50,i->getPoint()->getY() * 100 + 50),
                max(8, min(i->getPeople()/10, 50)), Fill(Color(255,0,0)), Stroke(1, Color(0, 0, 0)));

        //string sname(1, stations[i]->getName());

        //TODO: text in a cricle showing station's number
        //doc << Text(Spoint(stations[i]->getPoint().getX() * 100 + 35, stations[i]->getPoint().getY() * 100 + 35),
        //            sname, Color::Black, Font(max(8, min(stations[i]->getPeople()/10, 50)), "Verdana"));

        //number of people at the station
        doc << Text(Spoint(i->getPoint()->getX() * 100 + 65, i->getPoint()->getY() * 100 + 65),
                to_string(i->getPeople()), Color::Black, Font(20, "Verdana"));
        //station's coordinates
        doc << Text(Spoint(i->getPoint()->getX() * 100 + 65, i->getPoint()->getY() * 100 + 35),
                "(" + to_string(i->getPoint()->getX())
                + ", " + to_string (i->getPoint()->getY()) + ")",
                Color::Black, Font(20, "Verdana"));
    }

    doc.save();
}
