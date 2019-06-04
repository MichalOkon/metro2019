#include "StretchException.h"
#ifndef STATION_DOES_NOT_EXIST_EXCEPTION_H
#define STATION_DOES_NOT_EXIST_EXCEPTION_H


class StationDoesNotExistException: public StretchException
{
    public:
    const char* what() const throw()
    {
        return "At least one of the stations you want to connect doesn't exist";
    }
};


#endif