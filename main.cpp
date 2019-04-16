#include <iostream>

#include "graph.cpp"

using namespace std;
int main()
{
    Graph miasto;
    cout << "podaj ilosc stacji" << endl;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        miasto.add_station();
    cout << "podaj ilosc polaczen" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
        miasto.add_stretch();
    cout << "Podaj ilosc dni" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Day " << i+1 << endl;
        miasto.to_one_point(2);
        miasto.show();
        cout << endl;
    }
    return 0;
}