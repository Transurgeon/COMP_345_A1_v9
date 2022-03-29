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
    lc->push_back(c);
    Notify(this);
}

string CommandProcessor::validate(GameState gs) {
    string c = lc->back().getCommandText();
    static int players = 0;
    

    regex loadRegex("loadmap <[a-zA-Z0-9.]+>");
    regex playerRegex("addplayer <[a-zA-Z]+>");
    if (regex_match(c, loadRegex) && (gs == GameState::start || gs == GameState::mapLoaded))
        lc->back().saveEffect("maploaded");
    else if (c == "validatemap" && gs == GameState::mapLoaded) {
        lc->back().saveEffect("mapvalidated");
        players = 0;
    }
    else if (regex_match(c, playerRegex) && (gs == GameState::mapValidated || gs == GameState::playersAdded)) {
        lc->back().saveEffect("playersadded");
        players++;
    }
    else if (c == "gamestart" && gs == GameState::playersAdded && players >= 2 && players <= 6)
        lc->back().saveEffect("assignreinforcement");
    else if (c == "replay" && gs == GameState::win)
        lc->back().saveEffect("start");
    else if (c == "quit" && gs == GameState::win)
        lc->back().saveEffect("exit program");
    else {
        lc->back().saveEffect("Error: Invalid input.");
        return "";
    }
    return c;
}
string CommandProcessor::stringToLog() {
    return "CommandProcessor stringToLog: " + lc->back().getCommandText();
}


string FileCommandProcessorAdapter::readCommand() {
    return flr->readLineFromFile();
}


FileLineReader::FileLineReader(const string& filename) {
    inputFileStream.open(filename, ios::in);
    if (!inputFileStream.is_open()) {
        cout << "File does not exist or cannot be opened.\n";
        exit(0);
    }
}

string FileLineReader::readLineFromFile() {
    string cmd;

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