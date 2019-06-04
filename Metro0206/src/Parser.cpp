#include "../include/Parser.h"
#include "../include/Exceptions/ExistingNameException.h"
#include "../include/Exceptions/PointOutOfRangeException.h"
#include "../include/Exceptions/PointNotEmptyException.h"
#include "../include/Exceptions/StationDoesNotExistException.h"
#include "../include/Exceptions/ItselfConnectionException.h"
#include "../include/Exceptions/ExistingStretchException.h"
#include "../include/Exceptions/StretchNumberException.h"
#include "../include/Exceptions/NameException.h"
// #include "../include/Exceptions/StationException.h"
// #include "../include/Exceptions/StretchException.h"
#define SIZE 10

using namespace std;

Parser::Parser(Graph* g) : mGraph(g)
{

}

Parser::Parser() : mGraph(new Graph(10)){

}

Parser::~Parser() {

}

void Parser::insertStation() {
    std::string sName, sX, sY;
    int x, y;

    bool isParsed = false;
    while (!isParsed) {

        std::cin >> sName >> sX >> sY;
        isParsed = this->parseStation(sName, sX, sY, &x, &y);
    }

    mGraph->addStation(sName, 0, x, y);
}

bool Parser::parseStation(string sName, string sX, string sY, int * x, int * y) {

    bool answerXY = true, answerName = false, answerPoint = false, answerRange = false, alphaNumerical = false;

    try {

        *x = stoi(sX);
        *y = stoi(sY);
        // not sure
        answerPoint = checkPoint(*x, *y);
        answerRange = stCheckCoords(*x, *y);
        answerName = stCheckName(sName);
        alphaNumerical = !(hasAnyDigits(sName));

        if (!answerPoint) {
            throw PointNotEmptyException();
        } else if (!answerRange) {
            throw PointOutOfRangeException();
        } else if (!answerName) {
            throw ExistingNameException();
        } else if (!alphaNumerical) {
            throw NameException();
        }
    } catch (StationException &ex){
        cout << ex.what() << endl;
    } catch (std::exception & ex) {
        cout << "Please give me correct values for integers " << ex.what() << endl;
        answerXY = false;
    }

    return answerXY && answerName && answerPoint && answerRange && alphaNumerical;
}

void Parser::insertStretch() {
    int howMany;
    std::string sFrom, sTo, sHowMany;

    bool isParsed = false;
    while(!isParsed) {
        cin >> sFrom >> sTo >> sHowMany;
        isParsed = this->parseStretch(sFrom, sTo, sHowMany, &howMany);
    }

    mGraph->addStretch(sFrom, sTo, howMany);

}

bool Parser::parseStretch(std::string sFrom, std::string sTo, std::string sHowMany, int * howMany) {
    bool answerEmpty = false, selfConnect = false, answerHM = true, existingFlag = false;
    try {
        *howMany = std::stoi(sHowMany);
        answerEmpty = checkConnEmpty(sFrom, sTo);
        selfConnect = checkSelfConn(sFrom, sTo);
        existingFlag = isConnExist(sFrom, sTo);

        if (selfConnect) {
            throw ItselfConnectionException();
        } else if (answerEmpty) {
            throw StationDoesNotExistException();
        } else if (existingFlag) {
            throw ExistingStretchException();
        }
        
    } catch (StretchException & ex) {
        cout << ex.what() << endl;
    } catch (std::exception &ex) {
        cout << "Give me integer value of capacity" << ex.what() << endl;
        answerHM = false;
    }

    return (!answerEmpty) && (!selfConnect) && answerHM;
}

bool Parser::stCheckName(std::string name) {
    bool answer = true;
    int length = mGraph->getStationsAmount();
    auto stations = mGraph->getStations();
    for (int i = 0; i < length; i++) {
        if (stations[i]->getName().compare(name) == 0) {
            answer = false;
        }
    }
    return answer;
}

bool Parser::checkPoint(int x, int y) {
    bool answer = true;

    // cout << "In check Point" << endl;
    // cout << "X = " << x << "Y = " << y << endl;
    auto stations = mGraph->getStations();
    for (int i = 0; i < mGraph->getStationsAmount(); i++) {
        // cout << "sX = " << stations[i]->getPoint()->getX() << " sY = " << stations[i]->getPoint()->getY() << " sName: " << stations[i]->getName() << endl;
        if (stations[i]->getPoint()->getX() == x && stations[i]->getPoint()->getY() == y) {
            answer = false;
        }
    }
    return answer;
}

// True if point is empty, False if not
bool Parser::stCheckCoords(int x, int y) {
    int size = mGraph->getArea()->getSize();
    return (x >= 0 && x < size) && (y >= 0 && y < size);
}

// true if stations' names are equal
bool Parser::checkSelfConn(string sFrom, string sTo) 
{
    return sFrom.compare(sTo) == 0;
}

bool Parser::checkConnNumber(int n) {
    int mStAm = mGraph->getStationsAmount();
    return (n <= mStAm * (mStAm - 1) / 2);
}

bool Parser::checkConnEmpty(std::string from, std::string to) {
    return (!mGraph->stExists(from) || !mGraph->stExists(to)); // True if at least one of the stations is empty
}

bool Parser::isConnExist(string s1, string s2) {
    bool answer = false;
    int length = mGraph->getStretchesAmount();
    auto connections =  mGraph->getStretches();
    for (int i = 0; i < length; i++) {
        if ( ( ( s1.compare( connections[i]->getFrom()->getName() ) == 0 ) && ( s2.compare( connections[i]->getTo()->getName() ) == 0 ) ) || 
            ( ( s1.compare( connections[i]->getFrom()->getName() ) == 0 )  && ( s1.compare( connections[i]->getFrom()->getName() ) == 0 ) ) )  {
            answer = true;
            break;
        }
    }

    return answer;
}

bool Parser::stExists(std::string sName) {
    bool answer = false;
    int length = mGraph->getStationsAmount();
    auto stations = mGraph->getStations();
    for (int i = 0; i < length; i++) {
        if (sName == stations[i]->getName()) {
            answer = true;
            break;
        }
    }
    return answer;
}

void Parser::safeNumStretches(int * i) {
    string sInt;
    bool isRead = false, isChecked = false;
    while (true) {
        cin >> sInt;
        try {
            *i = std::stoi(sInt);
            isChecked = checkConnNumber(*i);
            if (!isChecked) {
                throw StretchNumberException();
            }
        } catch (StretchException & ex) {
            cout << ex.what() << endl;
            continue;
        } catch (std::exception & ex) {
            cout << "Nie można wczytac ciagu znakow. Sprobuj ponownie..." << endl;
            continue;
        }
        break;
    }
    cout << endl;
}



bool Parser::safeInsertInt(int * i) {
    string sInt;
    bool isRead = false;
    while(true) {
        cin >> sInt;
        try {
            *i = std::stoi(sInt);
        } catch (std::exception & ex) {
            cout << "Nie mozna tu wczytac ciagu znakow. Sprobuj ponownie..." << endl;
            isRead = false;
            continue;
        }
        isRead = true;
        break;
    }
    return isRead;
}


int Parser::parseInt(std::string sInt) {
    int i = 0;
    try {
        i = std::stoi(sInt);
    } catch (std::exception & ex) {
        cout << "Can't parse a string" << endl;
    }
    return i;
}

// TRUE if string CONTAINS numbers
bool Parser::hasAnyDigits(std::string s) {
    return std::any_of(s.begin(), s.end(), ::isdigit);
}