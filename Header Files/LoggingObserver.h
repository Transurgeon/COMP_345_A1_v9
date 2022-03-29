#pragma once
#ifndef COMP_345_LoggingObserver_h
#define COMP_345_LoggingObserver_h

#include <iostream>
#include <fstream>
#include <list>
#pragma once

using namespace std;

/// <summary>
/// ILoggable class
/// </summary>
class ILoggable {
public:
    ILoggable();
    ~ILoggable();
    virtual string stringToLog() = 0; //pure virtual method to add input to gameLog
};
/// <summary>
/// Observer class
/// </summary>
class Observer {
public:
    Observer();
    ~Observer();
    //observer method: pure virtual update for logging
    virtual void Update(ILoggable* il) = 0;
};
/// <summary>
/// Subject class 
/// </summary>
class Subject {
private:
    list<Observer*> _observers;
public:
    Subject();
    ~Subject();
    //subject methods: attach/detach for observer link and Notify for Logging
    void Detach(Observer* o);
    void Notify(ILoggable* i);
    void Attach(Observer* o);
};
/// <summary>
/// LogObserver class child of Observer
/// </summary>
class LogObserver : public Observer {
protected:
    Subject* _subjects;
public:
    LogObserver() = default; //default constructor
    ~LogObserver();
    LogObserver(Subject* s); //subject constructor
    void Update(ILoggable* il) override;
};

#endif