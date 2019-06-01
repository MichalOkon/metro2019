#ifndef POINT_H
#define POINT_H


#include <ostream>

class Point

{
	private:
		int mX;
		int mY;

	public:
		Point(int x, int y);
		Point();

		void setX(int newX);
		int getX();

		void setY(int newY);
		int getY();

	friend std::ostream &operator<<(std::ostream &os, const Point &point);

	// void setStationIndex(int stationIndex);
		//int getStationIndex();

	protected:
};

#endif // POINT_H

