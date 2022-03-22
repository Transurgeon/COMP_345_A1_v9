#pragma once
#ifndef COMP_345_LoggingObserver_h
#define COMP_345_LoggingObserver_h

#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class ILoggable {
public:
	~ILoggable();
	virtual string stringToLog() = 0;
protected:
	ILoggable();
};

class Observer {
public:
	~Observer();
	virtual void Update(ILoggable* i) = 0;
protected:
	Observer();
};

class Subject {
public:
	Subject();
	~Subject();
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(ILoggable* i);
	
private:
	list<Observer*>* _observers;
};

class LogObserver : public Observer {
public:
	~LogObserver();

	LogObserver(Subject* s);
	void Update(ILoggable* i);
protected:
	Subject* _subjects;
};



#endif