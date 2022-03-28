#include "../Header Files/GameEngine.h"
#include "../Header Files/Map.h"


//runs game and follow structure of flow chart
void GameEngine::startupPhase() {

	cmdProc = new CommandProcessor();
	cout << "Starting Game " << endl;
	//int players = addPlayer();
	int currentPlayer = 0;
	do {
		cout << endl << "Player " << currentPlayer + 1 << " is playing:" << endl << endl;
		assignReinforcements();
		issueOrders();
		currentPlayer = (currentPlayer + 1) ;
	} while (false);//(!executeOrders());

	string input;
	cout << "Do you want to play again? (Type \"yes\" if you agree, anything else otherwise) ";
	cin >> input;
	if (input == "yes") {
		startupPhase();
	}
	else {
		gameOver();
	}
}

void GameEngine::loadMap(string fileName) {
	*state = GameState::mapLoaded;
	deleteMap();
	*currentMap = MapLoader::addMap(fileName);
}

bool GameEngine::validateMap() {

	if (currentMap->validate()) {
		*state = GameState::mapValidated;
		return true;
	}

	*state = GameState::start;
	deleteMap();
	return false;
}

void GameEngine::deleteMap() {
	if (currentMap != nullptr) {
		delete currentMap;
		currentMap = nullptr;
	}

}

void GameEngine::addPlayer() {

	cout << "Adding Players " << endl;
	string input;
	int players = 1;
	do {
		players++;
		cout << "Number of players: " << players << endl;
		cout << "Do you want to add another player? (Type \"yes\" if you agree, anything else otherwise) ";
		cin >> input;
	} while (input == "yes");
}

void GameEngine::gameStart() {
	cout << "Fairly distributing territories to the players" << endl;

	cout << "Determining a random order of play for the players" << endl;

	cout << "Giving 50 troops to each player" << endl;
	for (int j = 0; j < playersNum; j++) {
		//playerList.at(j)->setTroops(50);
	}

	cout << "Each player draws 2 cards from the deck to their hand" << endl;
	for (int j = 0; j < playersNum; j++) {
		//playerList.at(j)->getPlayerCards.draw();
		//playerList.at(j)->getPlayerCards.draw();
	}
}

void GameEngine::mainGameLoop() {
	cout << "reinforcementPhase" << endl;
	assignReinforcements();
	cout << "issueOrdersPhase" << endl;
	issueOrders();
	cout << "executeOrdersPhase" << endl;
	executeOrders();
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

void GameEngine::executeOrders() {
	cout << "Execute Orders Stage" << endl;
	string input;
	for (int i = 0; i < 5; i++) {
		cout << "**Executing Orders**" << endl;

	}
	cout << "Did you capture all territories? This means you won (Type \"yes\" if you agree, anything else otherwise) ";
	cin >> input;
}

void GameEngine::gameOver() {
	cout << "Thank you for playing!!" << endl <<
			"Please don't make us lose to many marks :)";
}

//void GameEngine::setState(GameState gs) {
//	state = gs;
//}
//
//GameState GameEngine::getState() {
//	return state;
//}
//
//void GameEngine::Transition() {
//	Notify(this);
//}
//
//string GameEngine::stringToLog() {
//	return "Running Game Engine: " + userCmd;
//}

GameEngine::GameEngine() {
	playersNum = 0;
	state = new GameState(GameState::start);
	cmdProc = new CommandProcessor();
	currentMap = nullptr;
}

GameEngine::GameEngine(GameEngine& copy) {}

GameEngine& GameEngine::operator =(const GameEngine& copy) { return *this; }

GameEngine::~GameEngine() {}

ostream& operator<<(ostream& output, GameEngine& t) { return output; }