#include "../Header Files/CommandProcessing.h"
#include <regex>
#include <utility>

Command::Command(string cmd) {
    command = std::move(cmd);
}

void Command::saveEffect(string e) {
    effect = std::move(e);
    Notify(this);
}
string Command::stringToLog() {
    return "Command stringToLog: " + effect;
}
/////////////////

void CommandProcessor::getCommand() {
    string cmd = readCommand();
    saveCommand(cmd);
}

string CommandProcessor::readCommand() {
    string cmd;
    cout << "Please enter a command: \n";
    getline(cin, cmd);
    return cmd;
}

void CommandProcessor::saveCommand(const string& cmd) {
    Command c(cmd);
    // Save effect
    lc->push_back(c);
    Notify(this);
}

// If valid, returns the passing command
string CommandProcessor::validate(GameState gs) {
    string c = lc->back().getCommandText();

    regex loadRegex("loadmap\\s.+");
    regex playerRegex("addplayer\\s.+");

    // Loadmap is usable
    if (regex_match(c, loadRegex) && (gs == GameState::start || gs == GameState::mapLoaded))
        lc->back().saveEffect("maploaded");
    // Validatemap is usable
    else if (c == "validatemap" && gs == GameState::mapLoaded)
        lc->back().saveEffect("mapvalidated");
    // Addplayer is usable
    else if (regex_match(c, playerRegex) && (gs == GameState::mapValidated || gs == GameState::playersAdded))
        lc->back().saveEffect("playersadded");
    // Gamestart is usable
    else if (c == "gamestart" && gs == GameState::playersAdded)
        lc->back().saveEffect("assignreinforcement");
    // Replay is usable
    else if (c == "replay" && gs == GameState::win)
        lc->back().saveEffect("start");
    // Quit is usable
    else if (c == "quit" && gs == GameState::win)
        lc->back().saveEffect("exit program");
    // Command is not usable
    else
        lc->back().saveEffect("Error: Invalid input.");
    return c;
}
string CommandProcessor::stringToLog() {
    return "CommandProcessor stringToLog: " + lc->back().getCommandText();
}
//////////////

string FileCommandProcessorAdapter::readCommand() {
    return flr->readLineFromFile();
}

//////////////

FileLineReader::FileLineReader(const string& filename) {
    inputFileStream.open(filename, ios::in);
    if (!inputFileStream.is_open()) {
        cout << "File does not exist or cannot be opened.\n";
        exit(0);
    }
}

string FileLineReader::readLineFromFile() {
    string cmd;

    // End if file is empty
    if (inputFileStream.eof())
    {
        cout << "End of file.\n";
        inputFileStream.close();
        exit(0);
    }

    getline(inputFileStream, cmd);
    cout << "INPUT: " << cmd << endl;
    return cmd;
}