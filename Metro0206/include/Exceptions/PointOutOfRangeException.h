#include "StationException.h"
#ifndef POINT_OUT_OF_RANGE_EXCEPTION_H
#define POINT_OUT_OF_RANGE_EXCEPTION_H


class PointOutOfRangeException: public StationException
{
    public:
    const char* what() const throw()
    {
        return "The point is out of range";
    }
};


#endif