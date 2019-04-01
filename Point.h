#ifndef POINT_H
#define POINT_H


class Point

{
	private:
		int mX;
		int mY;
		int mStationIndex;

	public:
		Point(int x, int y, int stationIndex);
		Point();

		void setX(int newX);
		int getX();

		void setY(int newY);
		int getY();

        // void setStationIndex(int stationIndex);
		int getStationIndex();

	protected:
};

#endif // POINT_H

