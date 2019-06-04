#include "StretchException.h"
#ifndef ITSELF_CONNECTION_EXCEPTION_H
#define ITSELF_CONNECTION_EXCEPTION_H


class ItselfConnectionException: public StretchException
{
    public:
    
    const char* what() const throw()
    {
        return "You can't connect a station with itself";
    }
};


#endif