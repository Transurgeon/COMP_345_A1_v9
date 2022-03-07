#include "../Header Files/LoggingObserver.h"
#include <iostream>
using namespace std;

ILoggable::ILoggable() {
}

ILoggable::~ILoggable() {
}

Observer::Observer() {
}

Observer::~Observer() {
}

LogObserver::LogObserver(Subject* s) {
	_subjects = s;
	_subjects->Attach(this);
}

LogObserver::~LogObserver() {
	_subjects->Detach(this);
}

void LogObserver::Update(ILoggable* i) {
	ofstream fileStream;
	fileStream.open("gamelog.txt", ofstream::app);
	fileStream << i->stringToLog() << endl;
	fileStream.close();
}

Subject::Subject() {
	new LogObserver(this);
}

Subject::~Subject() {
}

void Subject::Attach(Observer* o) {
	_observers->push_back(o);
}
			
void Subject::Detach(Observer* o) {
	_observers->remove(o);
}

void Subject::Notify(ILoggable* i) {
	for (Observer* o : *_observers) {
		o->Update(i);
	}
}