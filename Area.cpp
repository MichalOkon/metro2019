#include <iostream>
#include "Area.h"
#include "Point.h"

using namespace std;

// Point[] wszedzie gdzie masz

Point* Area::GetCity() {
    return mCity;
}

void Area::SetCity(Point * city) {
    mCity = city;
}

int Area::GetTemple() {
    return mTemple;
}

void Area::SetTemple(int temple) {
    mTemple = temple;
}

// int[] Area::GetSubwayLine() {
//     return subwayLine;
// }

// void Area::SetSubwayLine(int subwayLine[]) {
//     this->subwayLine = subwayLine;
// }

Area::Area(Point * city, int temple) {
    mCity = city;
    mTemple = temple;
    // this->subwayLine = subwayLine;
}


Area::Area() {
    mCity = new Point[100];
    mTemple = 0;
    // this->subwayLine = [];
}

Area::~Area() {
    cout << "Area has been destroyed..." << endl;
}

void Area::Day() {
    cout << "And that's how I simulate the day in the subway" << endl;
}


// Area::display(Point city[][]) {

//     int length1 = sizeof(city) / sizeof(city[0]);
//     int length2 = sizeof(city[0]) / sizeof(city[0][0]);

//     for (int i = 0; i < length1; i++) {
//         for (int j = 0; j < length2; j++) {
//             if (city[i][j].stationIndex() != -1) {
//                 // cout
//             }
//         }
//     }

// }

