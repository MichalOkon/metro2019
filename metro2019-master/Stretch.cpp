#include "Stretch.h"

Stretch::Stretch()
{
}

Stretch::Stretch(int id, int pass, Station from, Station to)
{
    mId = id;
    mPass = pass;
    mFrom = from;
    mTo = to;
};

Stretch::~Stretch()
{
    
}

int Stretch::getId()
{
    return mId;
}

void Stretch::setId(int val)
{
    mId = val;
}

int Stretch::getPass()
{
    return mPass;
}

void Stretch::setPass(int val)
{
    mPass = val;
}

Station Stretch::getFrom()
{
    return mFrom;
}

void Stretch::setFrom(Station val)
{
    mFrom = val;
}

Station Stretch::getTo(int fromm)
{
    if(mFrom.mName == fromm)
        return mTo;
    else if(mTo.mName == fromm)
        return mFrom;
    else
        return mTo;
}

void Stretch::setTo(Station val)
{
    mTo = val;
}
