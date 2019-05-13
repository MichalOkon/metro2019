#include "Graphics.h"

#include "Area.h"
#include "Simple_svg.hpp"
#include <string>
#include <math.h>

using namespace svg;

void Graphics::drawPop(int **population) {

    Dimensions dimensions(SIZE * 100, SIZE * 100);
    Document doc("population.svg", Layout(dimensions, Layout::TopLeft));

    Polygon border(Stroke(1, Color::Black));
    border << Spoint(0, 0) << Spoint(dimensions.width, 0)
          << Spoint(dimensions.width, dimensions.height) << Spoint(0, dimensions.height);
    doc << border;

    Polyline lineY(Stroke(0.5, Color::Black));
    Polyline lineX(Stroke(0.5, Color::Black));

    for(int i=0; i<SIZE; ++i){
        for(int j = 0; j< SIZE; ++j){
            doc << Text(Spoint(((dimensions.width * (j + 0.35) / 10) ), (dimensions.height * (i + 0.65) / 10)),
                    to_string(population[i][j]), Color::Green, Font(40, "Verdana"));
            lineY << Spoint((dimensions.width * i / 10) , (dimensions.height * j  / 10));
            lineX << Spoint(((dimensions.width * j  / 10) ), (dimensions.height * i  / 10));

            if(j + 1 == SIZE){
                lineY << Spoint((dimensions.width * i  / 10), dimensions.height);
                lineY << Spoint((dimensions.width * i  / 10), 0);
                lineY << Spoint((dimensions.width * (i + 1) / 10), 0);
                lineX << Spoint(dimensions.width, (dimensions.height * i / 10));
                lineX << Spoint(0,(dimensions.height * i  / 10));
            }
        }
    }

    doc << lineX;
    doc << lineY;

    doc.save();

}

void Graphics::drawMetro(vector <Station*> stations, vector <Stretch*> const stretches, string name ){

    Dimensions dimensions(SIZE * 100 + 100, SIZE * 100 + 100);
    Document doc(name + ".svg", Layout(dimensions, Layout::BottomLeft));

    Polygon border(Stroke(1, Color::Black));
    border << Spoint(0, 0) << Spoint(dimensions.width, 0)
           << Spoint(dimensions.width, dimensions.height) << Spoint(0, dimensions.height);
    doc << border;

    for(int i = 0; i < stretches.size(); i++) {

        //a line representing connections between stations
        doc << (Polyline(Stroke(max(2, min(10, stretches[i]->getPass()/5)), Color::Blue))
        << Spoint(stretches[i]->getFrom().getPoint().getX() * 100 + 50,
                stretches[i]->getFrom().getPoint().getY() * 100 + 50)
                << Spoint(stretches[i]->getTo().getPoint().getX() * 100 + 50,
                        stretches[i]->getTo().getPoint().getY() * 100 + 50));

        //station's throughput
        doc << Text(Spoint(((stretches[i]->getFrom().getPoint().getX() * 100 + 50) +
        stretches[i]->getTo().getPoint().getX() * 100 + 50)/2.0,
                (((stretches[i]->getFrom().getPoint().getY() * 100 + 50)
                + stretches[i]->getTo().getPoint().getY() * 100 + 50)/2.0 + 20)), to_string(stretches[i]->getPass()),
                    Color::Brown, Font(20, "Verdana"));

    }

    for(int i = 0; i < stations.size(); i++){
        //stations show as circles
        doc << Circle(Spoint(stations[i]->getPoint().getX() * 100 + 50, stations[i]->getPoint().getY() * 100 + 50),
                max(8, min(stations[i]->getPeople()/10, 50)), Fill(Color(255,0,0)), Stroke(1, Color(0, 0, 0)));

        string sname(1, stations[i]->getName());

        //TODO: text in a cricle showing station's number
        //doc << Text(Spoint(stations[i]->getPoint().getX() * 100 + 35, stations[i]->getPoint().getY() * 100 + 35),
        //            sname, Color::Black, Font(max(8, min(stations[i]->getPeople()/10, 50)), "Verdana"));

        //number of people at the station
        doc << Text(Spoint(stations[i]->getPoint().getX() * 100 + 65, stations[i]->getPoint().getY() * 100 + 65),
                to_string(stations[i]->getPeople()), Color::Black, Font(20, "Verdana"));
        //station's coordinates
        doc << Text(Spoint(stations[i]->getPoint().getX() * 100 + 65, stations[i]->getPoint().getY() * 100 + 35),
                "(" + to_string(stations[i]->getPoint().getX())
                + ", " + to_string (stations[i]->getPoint().getY()) + ")",
                Color::Black, Font(20, "Verdana"));
    }

    doc.save();
}