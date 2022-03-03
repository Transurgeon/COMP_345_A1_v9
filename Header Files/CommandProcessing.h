#pragma once
#ifndef COMP_345_CommandProcessing_h
#define COMP_345_CommandProcessing_h

#include <iostream>;
using namespace std;

class Command {
public:
	//Constructors, Destructors and Operators
	Command();
	Command(const Command& copy);
	Command& operator =(const Command& copy);
	~Command();
	friend ostream& operator<<(ostream& output, Command& o);
};

class CommandProcessor {
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

class FileCommandProcessorAdapter {
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