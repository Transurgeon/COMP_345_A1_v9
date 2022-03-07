#include "../Header Files/CommandProcessing.h"

Command::Command(string c) {
	cmd = c;
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

	return "Calling the Command stringToLog";
}

void Command::saveEffect(string e) {

}

Command::~Command() {

}

ostream& operator<<(ostream& output, Command& o) {
	return output;
}

CommandProcessor::CommandProcessor() {

}

CommandProcessor::CommandProcessor(const CommandProcessor& copy) {

}

CommandProcessor& CommandProcessor::operator =(const CommandProcessor& copy) {

}

CommandProcessor::~CommandProcessor() {

}

ostream& operator<<(ostream& output, CommandProcessor& o) {

}

string CommandProcessor::stringToLog() {

	return "Calling the CommandProcessor stringToLog";
}

string CommandProcessor::readCommand() {

}

void CommandProcessor::getCommand() {

}

void CommandProcessor::saveCommand() {

}

bool CommandProcessor::validate() {

}