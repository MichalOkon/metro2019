#include <iostream>
#include "Point.h"

// Constructors
Point::Point(int x, int y) {
	mX = x;
	mY = y;
}

Point::Point() {
	mX = -1;
	mY = -1;
}


// Setters and Getters
void Point::setX(int newX) {
	mX = newX;
}

void Point::setY(int newY) {
	mY = newY;
}

int Point::getX() {
	return mX;
}

int Point::getY() {

	return mY;
}

// void Point::setStationIndex(int newStationIndex) {
//     mStationIndex = newStationIndex;
// }

// int getStationIndex() {
//     return mStationIndex;
// }

