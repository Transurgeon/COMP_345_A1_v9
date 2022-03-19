#include "../Header Files/CommandProcessing.h"

Command::Command(string c) {
	cmd = std::move(c);
}

Command::Command(const Command& copy) {

}

Command& Command::operator =(const Command& copy) {
	return *this;
}

string Command::getEffect() {
	return effect;
}

string Command::getCommand() {
	return cmd;
}

string Command::stringToLog() {

	return "Calling the Command stringToLog \n The effect is : " + effect;
}

void Command::saveEffect(string e) {
	effect = std::move(e);
	Notify(this);
}

Command::~Command() {

}

ostream& operator<<(ostream& output, Command& o) {
	return output;
}

CommandProcessor::~CommandProcessor() {

}

string CommandProcessor::stringToLog() {

	return "Calling the CommandProcessor stringToLog \n The command is : " + commandList->back().getCommand();
}

string CommandProcessor::readCommand() {
	string input;
	cout << "Hello, please enter a command: ";
	cin >> input;
	return input;
}

void CommandProcessor::getCommand() {
	saveCommand(readCommand());
}

void CommandProcessor::saveCommand(const string& c) {
	Command cmd (c);
	commandList->push_back(cmd);
	Notify(this);
}

bool CommandProcessor::validate() {
	return true;
}


FileLineReader::FileLineReader(const string& filename) {
	inputFileStream.open(filename, ios::in);
	if (!inputFileStream.is_open()) {
		cout << "File cannot be opened, please try again (it might not even exist...).\n";
		exit(0);
	}
}

string FileLineReader::readLine() {

}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(FileLineReader* flr) { 
	this->fileLineReader = flr;
}

string FileCommandProcessorAdapter::readCommand() {

	return fileLineReader->readLine();
}