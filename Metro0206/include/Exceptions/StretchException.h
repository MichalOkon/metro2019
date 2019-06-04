#include <exception>
#ifndef STRETCH_EXCEPTION_H
#define STRETCH_EXCEPTION_H

class StretchException : public std::exception {
    public:
    virtual const char * what() const throw() {
        return "Stretch exception";
    }
};

#endif