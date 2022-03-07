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
public:
	//Constructors, Destructors and Operators
	Command();
	Command(const Command& copy);
	Command& operator =(const Command& copy);
	~Command();
	friend ostream& operator<<(ostream& output, Command& o);
};

class CommandProcessor : public ILoggable, Subject {
private:
	Command* commandList;
public:
	//Constructors, Destructors and Operators
	CommandProcessor();
	CommandProcessor(const CommandProcessor& copy);
	CommandProcessor& operator =(const CommandProcessor& copy);
	~CommandProcessor();
	friend ostream& operator<<(ostream& output, CommandProcessor& o);

	void readCommand();
	void getCommand();
	void saveEffect();
	void saveCommand();
	bool validate();
};

class FileCommandProcessorAdapter : public CommandProcessor {
private:
	Command* commandList;
public:
	//Constructors, Destructors and Operators
	FileCommandProcessorAdapter();
	FileCommandProcessorAdapter(const FileCommandProcessorAdapter& copy);
	FileCommandProcessorAdapter& operator =(const FileCommandProcessorAdapter& copy);
	~FileCommandProcessorAdapter();
	friend ostream& operator<<(ostream& output, FileCommandProcessorAdapter& o);

};
#endif