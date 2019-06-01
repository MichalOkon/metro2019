#include "../include/Stretch.h"
#include <cmath>

Stretch::Stretch()
{
}

Stretch::Stretch(int id, int pass, Station* from, Station* to)
{
    mId = id;
    mPass = pass;
    mFrom = from;
    mTo = to;
    mTime = sqrt( (mFrom->getPoint()->getX() - mTo->getPoint()->getX())*(mFrom->getPoint()->getX() - mTo->getPoint()->getX())
        + (mFrom->getPoint()->getY() - mTo->getPoint()->getY())*(mFrom->getPoint()->getY() - mTo->getPoint()->getY()) );
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

Station* Stretch::getFrom()
{
    return mFrom;
}

void Stretch::setFrom(Station* val)
{
    mFrom = val;
}

Station* Stretch::getToorFrom(int fromm)
{
    if(mFrom->getID() == fromm)
        return mTo;
    else if(mTo->getID() == fromm)
        return mFrom;
    else
        return mTo;
}

Station* Stretch::getTo()
{
    return mTo;
}

void Stretch::setTo(Station* val)
{
    mTo = val;
}


bool Stretch::sameDir(Stretch * str) {
    bool answer = false;
    if (this->mFrom == str->getFrom() && this->mTo == str->getTo()) {
        answer = true;
    } else if (this->mFrom == str->getTo() && this->mTo == str->getFrom()) {
        answer = true;
    }

    return answer;
}
int Stretch::getTime()
{
    return mTime;
}

