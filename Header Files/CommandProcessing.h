#pragma once
#ifndef COMP_345_CommandProcessing_h
#define COMP_345_CommandProcessing_h

#include <iostream>;
#include "../Header Files/LoggingObserver.h"
using namespace std;

enum class GameState {
	start, mapLoaded, mapValidated, playersAdded, assignReinforcement, issueOrders, executeOrders, win,
};

class Command : public ILoggable, Subject {
private:
	string cmd;
	string effect;
public:
	//Constructors, Destructors and Operators
	Command(string c);
	Command(const Command& copy);
	Command& operator =(const Command& copy);
	
	//getters
	string getEffect();
	string getCommand();
	string stringToLog();
	void saveEffect(string e);

	~Command();
	friend ostream& operator<<(ostream& output, Command& o);
};

class CommandProcessor : public ILoggable, Subject {
private:
	Command* commandList;
public:
	//Constructors, Destructors and Operators
	~CommandProcessor();

	string stringToLog();
	string readCommand();
	void getCommand();
	void saveCommand();
	bool validate();
};

class FileCommandProcessorAdapter : public CommandProcessor {
private:
	Command* commandList;
public:
	
};
#endif