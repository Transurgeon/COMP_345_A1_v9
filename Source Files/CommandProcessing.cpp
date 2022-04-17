#include "../Header Files/CommandProcessing.h"
#include "../Header Files/Map.h"
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
    regex tournamentRegex("tournament -M <[a-zA-Z0-9.,\\s]+> -P <[a-zA-Z,\\s]+> -G <[1-5]> -D <([1-4][0-9]|50)>");

    //new code for tournament mode
    if (regex_match(c, tournamentRegex) && (gs == GameState::start)) {
        for (string s : getVector(getParameter(c,1)))
            if (!MapLoader::addMap(s)->validate()) {
                lc->back().saveEffect("Error: Invalid input.");
                cout << "test1";
                return "";
            }
        string counter ="";

        for (string s : getVector(getParameter(c, 2)))

            if (s == "Aggressive")
                counter += "0";

            else if (s == "Benevolent")
                counter += "1";

            else if (s == "Neutral")
                counter += "2";

            else if (s == "Cheater")
                counter += "3";

            else {
                lc->back().saveEffect("Error: Invalid input.");
                cout << "test2"; return "";
            }
        if (counter.length() < 2) {
            lc->back().saveEffect("Error: Invalid input.");
            cout << "test2.5"; return "";
        }
        
        for (int i = 0; i < 4; i++) {
            if (count(counter.begin(), counter.end(), '0' + i) > 1){
                lc->back().saveEffect("Error: Invalid input.");
                cout << "test3"; return "";
            }
        }

        cout << "test4";
        lc->back().saveEffect("tournament");
    }
    else if (regex_match(c, loadRegex) && (gs == GameState::start || gs == GameState::mapLoaded))
        lc->back().saveEffect("maploaded");
    else if (c == "validatemap" && gs == GameState::mapLoaded) {
        lc->back().saveEffect("mapvalidated");
        players = 0;
    }
    else if (regex_match(c, playerRegex) && (gs == GameState::mapValidated || gs == GameState::playersAdded) && players < 6) {
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


string getParameter(string c, int i) {

    for (int j = 0; j < i; j++) {
        c = c.substr(c.find_first_of("<")+1);
    }
    return c.substr(0, c.find_first_of(">"));
}

vector<string> getVector(string c) {

    int pos;
    while ((pos = c.find(" ")) != -1) {
        c.replace(pos, 1, "");
    }
    vector<string> list;

    if (!c.empty()) {
        while ((pos = c.find(",")) != -1) {
            list.push_back(c.substr(0, pos));
            c = c.substr(pos + 1);
        }
        if (!c.empty()) {
            list.push_back(c);
        }
    }

    return list;

}
