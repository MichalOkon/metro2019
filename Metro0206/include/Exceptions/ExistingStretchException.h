#include "StretchException.h"
#ifndef EXISTING_STRETCH_EXCEPTION_H
#define EXISTING_STRETCH_EXCEPTION_H


class ExistingStretchException: public StretchException
{
    public:
    
    const char* what() const throw()
    {
        return "A similar stretch already exist";
    }
};


#endif