#include "../Header Files/LoggingObserver.h"
using namespace std;


Subject::Subject() {
    new LogObserver(this);
}

Subject::~Subject() {}

void Subject::Attach(Observer* obs) {
    _observers.push_back(obs);
}

void Subject::Detach(Observer* obs) {
    _observers.remove(obs);
}

void Subject::Notify(ILoggable* il) {
    for (Observer* o : _observers) {
        o->Update(il);
    }
}

// Observer

Observer::Observer() {}
Observer::~Observer() {}
// LogObserver class methods

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

ILoggable::ILoggable() {

}

ILoggable::~ILoggable() {

}