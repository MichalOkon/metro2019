//
// Created by zsantorowska on 19.05.19.
//

#include "Statistics.h"

Statistics::Statistics()
{

}


void Statistics::addDay(Graph* g)
{
    //Graph* newG = new Graph(g);
    days.push_back( g);
}

void Statistics::PrintMe()
{
    for(int i = 0; i < days.size(); i++)
    {
        for(int j = 0; j < days[i]->GraphLen1(); j++)
        {
            for(int k = 0; k < days[i]->GraphLen2(j); k++)
            {
                days[i]->printGraphElem( j , k );
                //cout<<" a ";
            }
        }
        cout<<endl;

        for(int j = 0; j < days[i]->StationsLen(); j++)
        {
            days[i]->printStationsElem(j);
            //cout<<" b ";
        }
        cout<<endl;

        for(int j = 0; j < days[i]->ConnectionsLen(); j++)
        {
            days[i]->printConnectionsElem(j);
            //cout<<" c ";
        }
        cout<<endl;
        cout<<endl;
    }
}

void Statistics::showGraph()
{
    cout<<endl;
    cout<<endl;
    for(int i = 0; i < days.size(); i++)
    {
        days[i]->show();
        cout<<endl;
    }

}