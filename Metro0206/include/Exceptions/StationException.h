#include <exception>
#ifndef STATION_EXCEPTION_H
#define STATION_EXCEPTION_H

class StationException : public std::exception {
    public:
    virtual const char * what() const throw() {
        return "Station exception";
    }
};

#endif