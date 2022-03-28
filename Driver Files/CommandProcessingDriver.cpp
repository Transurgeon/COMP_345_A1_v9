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

    while (*playPtr) {
        switch (ge.getState()) {
        case GameState::start:
            ge.startupPhase();
            ge.mainGameLoop();
            
        case GameState::win:
            *userChoicePtr = ge.winFunc();
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