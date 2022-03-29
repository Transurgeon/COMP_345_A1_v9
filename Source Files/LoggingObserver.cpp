#include "../Header Files/LoggingObserver.h"
using namespace std;

/// <summary>
/// ILoggable constructors
/// </summary>

//Empty Constructor and Destructor for ILoggable
ILoggable::ILoggable() {

}

ILoggable::~ILoggable() {

}

/// <summary>
/// Subject class
/// </summary>
Subject::Subject() {
    new LogObserver(this);
}

Subject::~Subject() {}

void Subject::Attach(Observer* o) {
    _observers.push_back(o);
}

void Subject::Detach(Observer* o) {
    _observers.remove(o);
}
//Notify is called when a change is happening to the objects of the game, then update will log and do console output
void Subject::Notify(ILoggable* i) {
    for (Observer* o : _observers) {
        o->Update(i);
    }
}

/// <summary>
/// Observer
/// </summary>

//Empty Constructor and Destructor for Observer
Observer::Observer() 
{

}
Observer::~Observer() 
{

}

/// <summary>
/// LogObserver methods
/// </summary>
LogObserver::LogObserver(Subject* s) {
    _subjects = s;
    _subjects->Attach(this);
}

LogObserver::~LogObserver() {
    _subjects->Detach(this);
}

void LogObserver::Update(ILoggable* il) {
    ofstream ofs;
    ofs.open("gameLog.txt", ofstream::app);
    ofs << il->stringToLog() << endl;
    ofs.close();
}
