#include "StationException.h"
#ifndef NAME_EXCEPTION_H
#define NAME_EXCEPTION_H

class NameException: public StationException
{
    public:
    const char* what() const throw()
    {
        return "Nie mozna uzywac cyfr w imieniu";
    }
};


#endif