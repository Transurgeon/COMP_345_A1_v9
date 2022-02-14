#include "../Header Files/GameEngine.h"
#include "../Header Files/Map.h"

GameEngine::GameEngine() {


}

GameEngine::GameEngine(GameEngine& copy) {


}

GameEngine& GameEngine::operator =(const GameEngine& copy) {

	return *this;
}

GameEngine::~GameEngine() {


}

ostream& operator<<(ostream& output, GameEngine& t) {

	return output;
}

void GameEngine::runGameEngine() {


	cout << "Starting Game " << endl;

	loadAndValidateMap();
	addPlayers();
	do {
		assignReinforcements();
		issueOrders();

	} while (!executeOrders());

	string input;
	cout << "Do you want to play again? (Type \"yes\" if you agree, anything else otherwise) ";
	cin >> input;
	if (input == "yes") {
		MapLoader::deleteAllMaps();
		runGameEngine();
	}
	else {
		gameOver();
	}

}

void GameEngine::loadAndValidateMap() {

	string input;
	cout << "Welcome to the map loader function, please choose a file name from the Map Files folder and we will validate them." << endl;

	do {
		MapLoader::addMap();
		cout << "Do you want to add another map? (Type \"yes\" if you agree, anything else otherwise) ";
		cin >> input;
	} while (input == "yes");

	MapLoader::validateMaps();

}

void GameEngine::addPlayers() {

	cout << "Adding Players " << endl;
	string input;
	int players = 0;
	do {
		players++;
		cout << "Number of players :" << players << endl;
		cout << "Do you want to add another player? (Type \"yes\" if you agree, anything else otherwise) ";
		cin >> input;
	} while (input == "yes");
}

void GameEngine::assignReinforcements() {

	cout << "Assign Reinforcements Stage" << endl;
	string input;
	do {
		cout << "**Assiging Reinforcements**" << endl;
		cout << "Are you done assigning reinforcements? (Type \"yes\" if you agree, anything else otherwise) ";
		cin >> input;
	} while (input != "yes");
}

void GameEngine::issueOrders() {

	cout << "Issue Orders Stage" << endl;
	string input;
	do {
		cout << "**Issuing Orders**" << endl;
		cout << "Are you done issuing orders? (Type \"yes\" if you agree, anything else otherwise) ";
		cin >> input;
	} while (input != "yes");
}

bool GameEngine::executeOrders() {
	cout << "Execute Orders Stage" << endl;
	string input;
	for (int i = 0; i < 5; i++) {
		cout << "**Executing Orders**" << endl;

	}
	cout << "Do you feel like you won? (Type \"yes\" if you agree, anything else otherwise) ";
	cin >> input;
	if (input == "yes")
		return true;
	return false;
}

void GameEngine::gameOver() {
	cout << "Thank you for playing!!" << endl <<
		"Please don't make us lose to many marks :)";
}
