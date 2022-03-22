#include "../Header Files/CommandProcessing.h"
#include "../Header Files/GameEngine.h"
#include "../Header Files/Drivers.h"
#include <iostream>


void commandProcessorMain() {

    string input = "";
    cout << "Hello" << endl;
    cout << "Do you want to read commands from a file(1) or console(2)?" << endl;
    cin >> input;

    bool play = true;

    GameState state = start;
    GameEngine game;
    auto* processor = new CommandProcessor();
    string in = "";

    if (input == "1") {
        cout << "Input command file name: ";
        string fileName;
        cin >> fileName;

        auto* flr = new FileLineReader(fileName);
        processor = new FileCommandProcessorAdapter(flr);
    }

    else if (input == "2") {

    }

    while (play) {

        switch (state) {
        case start:
            //in = game.startFunc();
            if (in == "loadmap") {
                state = mapLoaded;
            }
            continue;
        case mapLoaded:
            //in = game.maploadedFunc();
            if (in == "validatemap") {
                state = mapValidated;
            }
            continue;
        case mapValidated:
            //in = game.mapvalidatedFunc();
            if (in == "addplayer") {
                state = playersAdded;
            }
            continue;
        case playersAdded:
            //in = game.playeraddedFunc();
            if (in == "assigncountries") {
                state = assignReinforcement;
            }
            continue;
        case assignReinforcement:
            //in = game.assignreinforcementFunc();
            if (in == "issueorder") {
                state = issueOrders;
            }
            continue;
        case issueOrders:
            //in = game.issueordersFunc();
            if (in == "endissuorders") {
                state = executeOrders;
            }
            continue;
        case executeOrders:
            //in = game.executeordersFunc();
            if (in == "endexecorders") {
                state = assignReinforcement;
            }
            else if (in == "win") {
                state = win;
            }
            continue;
        case win:
            //in = game.winFunc();
            if (in == "play") {
                state = start;
            }
            else if (in == "end") {
                play = false;
                break;
            }
            continue;
        default:
            cout << "Error: Invalid input\n";
        }
    }
};