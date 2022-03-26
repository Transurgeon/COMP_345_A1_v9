#pragma once
#ifndef COMP_345_LoggingObserver_h
#define COMP_345_LoggingObserver_h

#include <iostream>
#include <fstream>
#include <list>
#pragma once

using namespace std;
class ILoggable;
class LogObserver;
class Observer;

class Subject {
public:
    Subject();
    ~Subject();

    void Detach(Observer* obs);
    void Notify(ILoggable* il);

    void Attach(Observer* obs);

private:
    list<Observer*> _observers;
};

class Observer {
public:
    Observer();
    ~Observer();
    virtual void Update(ILoggable* il) = 0;
};

class ILoggable {
public:
    ILoggable();
    ~ILoggable();
    virtual string stringToLog() = 0;

};

class LogObserver : public Observer {
public:
    LogObserver() = default;
    LogObserver(Subject* s);
    ~LogObserver();
    void Update(ILoggable* il) override;

protected:
    Subject* _subjects;
};



#endif