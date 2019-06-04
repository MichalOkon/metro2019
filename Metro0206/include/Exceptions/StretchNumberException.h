#include "StretchException.h"
#ifndef STRETCH_NUMBER_EXCEPTION_H
#define STRETCH_NUMBER_EXCEPTION_H

class StretchNumberException: public StretchException
{
    public:
    const char* what() const throw()
    {
        return "Nie mozna dodac tylu polaczen pomiedzy stacjami. Sprobuj ponownie...";
    }
};


#endif