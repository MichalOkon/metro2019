#include "StationException.h"
#ifndef POINTNOTEMPTYEXCEPTION_H
#define POINTNOTEMPTYEXCEPTION_H


class PointNotEmptyException: public StationException
{
    public:
    const char* what() const throw()
    {
        return "The point is not empty. Choose another...";
    }
};


#endif