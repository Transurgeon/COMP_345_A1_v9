#pragma once
#ifndef COMP_345_LoggingObserver_h
#define COMP_345_LoggingObserver_h

#include <list>;
#include <iostream>;
#include <fstream>;

using namespace std;

class ILoggable {
public:
	ILoggable();
	~ILoggable();
	virtual string stringToLog() = 0;
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
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(ILoggable* i);
	Subject();
	~Subject();
private:
	list<Observer*>* _observers;
};

class LogObserver : public Observer {
public:
	~LogObserver();

	LogObserver(Subject* s);
	void Update(ILoggable* i) override;
protected:
	LogObserver();
	Subject* _subjects;
};



#endif