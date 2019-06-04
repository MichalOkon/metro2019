#include "StationException.h"
#ifndef EXISTING_NAME_EXCEPTION_H
#define EXISTING_NAME_EXCEPTION_H

class ExistingNameException: public StationException {
    public:
    const char* what() const throw()
    {
        return "The name you want to choose has been already taken";
    }
};


#endif