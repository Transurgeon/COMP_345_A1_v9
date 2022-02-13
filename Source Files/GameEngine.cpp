#include "../Header Files/GameEngine.h"

	GameEngine::GameEngine() {

	}

	GameEngine::~GameEngine() {

	}

	void GameEngine::runGame() {

		
		cout << "Starting Game " << endl;
		
		bool gameOver = false;
		bool win = false;

		do {
			//initialising game 
			loadMap();
			addPlayers();
			assignReinforcements();

			do {


			} while (win == true);

		} while (gameOver == true);
	}

	void GameEngine::loadMap() {
		
		int choice = -1;
		cout << "Loading Map " << endl;
		
		cout << "Press 0 to validate map";
		cin >> choice;  cout << endl;
		if (choice == 0) {
			cout << "Validating Map....." << endl;
			//Map.validate();
		}
		else
		cout << "Invalid Input: your map might also be invalid!!!" << endl;
	}

	void GameEngine::addPlayers() {
		cout << "Adding Players " << endl;

	}

	void GameEngine::assignReinforcements() {
		cout << "Assigning Reinforcements " << endl;

	}

	void GameEngine::issueOrders() {
		cout << "Issuing Orders " << endl;

	}

	bool GameEngine::executeOrders() {
		return true;
	}

	bool GameEngine::gameOver() {
		return true;
	}


