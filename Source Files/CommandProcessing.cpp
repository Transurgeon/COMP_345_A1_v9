#include "../Header Files/CommandProcessing.h"
#include <regex>

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

string CommandProcessor::validate(GameState gs) {
	string cmd = commandList->back().getCommand();

	if (regex_match(cmd, regex("loadmap\\s.+")) && (gs == GameState::start || gs == GameState::mapLoaded))
		commandList->back().saveEffect("mapLoaded");

	else if (cmd == "validatemap" && gs == GameState::mapLoaded)
		commandList->back().saveEffect("mapValidated");

	else if (regex_match(cmd, regex("addplayer\\s.+")) && (gs == GameState::mapValidated || gs == GameState::playersAdded))
		commandList->back().saveEffect("playersAdded");

	else if (cmd == "gamestart" && gs == GameState::playersAdded)
		commandList->back().saveEffect("assignReinforcements");

	else if (cmd == "replay" && gs == GameState::win)
		commandList->back().saveEffect("starting a new game");

	else if (cmd == "quit" && gs == GameState::win)
		commandList->back().saveEffect("exiting the program");

	else
		commandList->back().saveEffect("Error: Invalid input.");
	return cmd;
}


FileLineReader::FileLineReader(const string& filename) {
	inputFileStream.open(filename, ios::in);
	if (!inputFileStream.is_open()) {
		cout << "File cannot be opened, please try again (it might not even exist...).\n";
		exit(0);
	}
}

string FileLineReader::readLine() {
	string cmd;

	// End if file is empty
	if (inputFileStream.eof())
	{
		cout << "We have reached the end of the file.\n";
		inputFileStream.close();
		exit(0);
	}

	getline(inputFileStream, cmd);
	cout << "Input from file is the following : " << cmd << endl;
	return cmd;
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(FileLineReader* flr) { 
	this->fileLineReader = flr;
}

string FileCommandProcessorAdapter::readCommand() {

	return fileLineReader->readLine();
}