#pragma once
#ifndef COMP_345_CommandProcessing_h
#define COMP_345_CommandProcessing_h

#include <iostream>;
#include "../Header Files/LoggingObserver.h"
using namespace std;

enum GameState {
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
	list<Command>* commandList;
public:
	//Constructors, Destructors and Operators
	~CommandProcessor();

	string stringToLog();
	string readCommand();
	void getCommand();
	void saveCommand(const string& c);
	string validate(GameState gs);
};

class FileLineReader {
private:
	ifstream inputFileStream;
public:
	FileLineReader(const string& filename);
	string readLine();
};

class FileCommandProcessorAdapter : public CommandProcessor {
private:
	FileLineReader* fileLineReader;
public:
	FileCommandProcessorAdapter(FileLineReader* flr);
	string readCommand();
};
#endif