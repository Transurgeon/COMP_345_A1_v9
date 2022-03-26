#include "../Header Files/CommandProcessing.h"
#include "../Header Files/GameEngine.h"
#include "../Header Files/Drivers.h"
#include <iostream>


void commandProcessingMain() {

    bool play = true;
    bool* playPtr = &play;
    bool readFromFile = false;
    // Initialize var for keeping user's choice
    string userChoice;
    string* userChoicePtr = &userChoice;

        cout << "test" << endl;
    // Initialize logObserver
    auto* logObserver = new LogObserver();
    auto* cp = new CommandProcessor();

    if (readFromFile) {
        string filename = "C:\\Users\\Admin\\Documents\\Github-VS_projects\\COMP_345_A1_v9\\Map Files\\test.txt";
        auto* flr = new FileLineReader(filename);
        cp = new FileCommandProcessorAdapter(flr);
    }
    else
        cp = new CommandProcessor();

    auto* gameState = new GameEngine(cp);
    GameEngine ge = *gameState;

    ge.setState(GameState::start);

    // while true keep the game playing.
    while (*playPtr) {
        switch (ge.getState()) {
        case GameState::start:
            //call 
            *userChoicePtr = "loadmap";
            if (*userChoicePtr == "loadmap") {
                ge.Transition();
                ge.setState(GameState::mapLoaded);
            }
        case GameState::mapLoaded:
            //
            *userChoicePtr = "validatemap";
            if (*userChoicePtr == "validatemap") {
                ge.Transition();
                ge.setState(GameState::mapValidated);
            }
        case GameState::mapValidated:
            //
            *userChoicePtr = "addplayer";
            if (*userChoicePtr == "addplayer") {
                ge.Transition();
                ge.setState(GameState::playersAdded);
            }
            /*case playeradded:
                *userChoicePtr = ge.playeraddedFunc();
                if (userChoice == "gamestart") {
                    ge.setState(assignreignforcement);
                }*/
        case GameState::assignReinforcement:
            //
            *userChoicePtr = "issueorder";
            if (userChoice == "issueorder") {
                ge.setState(GameState::issueOrders);
            }
        case GameState::issueOrders:
            //
            *userChoicePtr = "endissuorders";
            if (userChoice == "endissuorders") {
                ge.setState(GameState::executeOrders);
            }
        case GameState::executeOrders:
            //
            *userChoicePtr = "endexecorders";
            if (userChoice == "endexecorders") {
                ge.setState(GameState::assignReinforcement);
            }
            else if (userChoice == "win") {
                ge.setState(GameState::win);
            }
        case GameState::playersAdded:
            //
            *userChoicePtr = "assigncountries";
            if (*userChoicePtr == "assigncountries") {
                ge.Transition();
                ge.setState(GameState::win);
            }
        case GameState::win:
            //
            *userChoicePtr = "quit";
            if (*userChoicePtr == "replay") {
                ge.Transition();
                ge.setState(GameState::start);
            }
            else if (*userChoicePtr == "quit") {
                // since the user chose to quit, therefore, change the bool to play false, to close.
                ge.Transition();
                *playPtr = false;
                break;
            }
            continue;
        default:
            cout << "Error: Invalid input\n";
        }
    }
};