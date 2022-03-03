#pragma once
#ifndef COMP_345_LoggingObserver_h
#define COMP_345_LoggingObserver_h

#include <list>;
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();
private:
	list<Observer*>* _observers;
};


#endif