#include "../Header Files/GameEngine.h"
#include "../Header Files/Map.h"



//runs game and follow structure of flow chart
void GameEngine::startupPhase() {

	
	cout << "------------\nCommand list:\nloadmap <mapfile>\nvalidatemap\naddplayer <playername>\ngamestart\nreplay\nquit\n------------\n\n\n";
	cout << "Starting game, load a map\n";
	string commandType;
	string commandArgument;
	do {
		cmdProc->getCommand();
		commandType = cmdProc->validate(state);
		commandArgument = "";
		if (commandType.find_first_of("<") != -1)
		{
			commandArgument = commandType.substr(commandType.find_first_of("<") + 1,
			commandType.find_first_of(">") - commandType.find_first_of("<") -1);
		}
		commandType = commandType.substr(0, commandType.find_first_of(" "));

		if (commandType == "loadmap") {
			loadMap(commandArgument);
		}
		else if (commandType == "validatemap") {
			validateMap();
		}
		else if (commandType == "addplayer") {
			addPlayer(commandArgument);
		}
		else if (commandType == "gamestart") {
			gameStart();
		}
		else if (commandType == "replay") {
			cout << "Starting a new game, load a map \n";
			state = GameState::start;
			playerList.clear();
			delete deck;
			deck = new Deck(50);
		}
		else if (commandType == "quit") {
			cout << "Thanks for playing, all it cost you to play this was your time, it cost me my sanity.";
		}
		else {
			cout << "Invalid command/command cannot be called!";
		}
	} while (commandType != "quit");
}

void GameEngine::loadMap(string fileName) {
	state = GameState::mapLoaded;
	deleteMap();
	currentMap = MapLoader::addMap(fileName);
	cout << "Adding or changing Map\n\n";
}

void GameEngine::validateMap() {

	if (currentMap->validate()) {
		state = GameState::mapValidated;
		cout << "Map is valid, please add players\n\n";
		return;
	}

	state = GameState::start;
	cout << "Map is not valid, return to start screen\n\n";
}

void GameEngine::deleteMap() {
	if (currentMap != nullptr) {
		delete currentMap;
		currentMap = nullptr;
	}
}

void GameEngine::addPlayer(string name) {

	state = GameState::playersAdded;
	if (playerList.size() < 6) {
		
		playerList.push_back(new Player(name));
		if (name == "Aggressive" || name == "Benevolent" || name == "Neutral" || name == "Cheater")
			cout << "Bot " + name + " was added\n\n";
		else
			cout << "Player " + name + " was added\n\n";
	}
	else {
		cout << "Too many players, " + name + " was not added\n\n";
	}
}

void GameEngine::gameStart() {
	cout << "\nFairly distributing territories to the players" << endl;
	vector<Territory*> territories = currentMap->getTerritories();
	int leftOverTerritories = territories.size();
	int currentTerritory = random(0, territories.size() -1);
	int currentPlayer = 0;
	while (leftOverTerritories > 0) {
		if (territories[currentTerritory]->getPlayerName() == "") {
			territories[currentTerritory]->setPlayer(playerList[currentPlayer]->getName());
			currentPlayer = (currentPlayer + 1) % playerList.size();
			leftOverTerritories--;
		}
		currentTerritory = (currentTerritory + random(1, leftOverTerritories)) % territories.size();
	}
	cout << "\nDetermining a random order of play for the players" << endl;

	std::random_shuffle(playerList.begin(), playerList.end());

	cout << "\nThe order will be: ";
	for (int i = 0; i < playerList.size()-1;i++)
	{
		cout << playerList[i]->getName() + ", ";
	}
	cout << playerList[playerList.size() - 1]->getName() << endl;

	cout << "\nGiving 50 troops to each player" << endl;
	int troops;
	string input;
	for (int i = 0; i < playerList.size(); i++) {
		playerList[i]->addArmyNum(50);
	}
	cout << "\n\nGame is starting\n\n";
	
	do {} while (mainGameLoop());

	cout << "Sombody has won the game, do you want to play again?";
	state = GameState::win;
}

int random(int a, int b) {
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	if (a == b)
		return a;

	return a + rand() % (abs(b-a));
}

bool GameEngine::mainGameLoop() {
	cout << "Reinforcement Phase" << endl;
	assignReinforcements();
	cout << "Issue Orders Phase" << endl;
	issueOrders();
	cout << "Execute Orders Phase" << endl;
	return executeOrders();
}

void GameEngine::assignReinforcements() {

	cout << "Current map state:\n";
	currentMap->printMap();
	cout << "\n\n";
	state = GameState::assignReinforcements;
	string input;
	int troops;
	int countriesOwned;
	int continentsOwned;
	vector<Territory*> territories = currentMap->getTerritories();
	for (int i = 0; i < playerList.size(); i++) {
		
		//add troops based on number of territories/3
		troops = 0;
		countriesOwned = 0;
		continentsOwned = 0;
		for (int j = 0; j < territories.size(); j++) {
			if (territories[j]->getPlayerName() == playerList[i]->getName()) {
				troops++;
				countriesOwned++;
			}
		}
		troops /= 3;

		//add bonuses based off continents held
		bool bonus;
		for (int j = 0; j < currentMap->getContinents().size(); j++) {
			bonus = true;
			for (int k = 0; k < territories.size(); k++) {

				if (territories[k]->getContinentNum() == j + 1 && territories[k]->getPlayerName() != playerList[i]->getName()) {
					bonus = false;
				}
			}
			if (bonus) {
				troops += currentMap->getContinents()[j]->getBonus();
				continentsOwned++;
			}
		}

		//sets mininum troop limit of 3 troops, then adds to reserves
		if (troops < 3)
			troops = 3;

		playerList[i]->addArmyNum(troops);

		cout << "Assigned " << troops << " troops for " << playerList[i]->getName() << ", owning " << countriesOwned <<
			" territories and " << continentsOwned << " continents.\n\n";

	}
}

void GameEngine::issueOrders() {
	state = GameState::issueOrders;
	//generates defend list and attack list with toAttack and toDefend
	//Then let's player issue orders based on the player strategy

	for (int i = 0; i < playerList.size(); i++) {
		cout << playerList[i]->getName() << " is issuing orders:\n";

		playerList[i]->toDefend(currentMap);
		playerList[i]->toAttack(currentMap);
		playerList[i]->issueOrder(currentMap);
	}
}

bool GameEngine::executeOrders() {
	state = GameState::executeOrders;
	
	//Executes orders for all players in round robin fashion
	int i = 0, skipCounter = 0;
	vector<bool> skip(playerList.size());
	for (bool b : skip) {b = false;}

	do {
		if (!skip[i]) {
			cout << "-------------------------------------------\n";
			cout << "Executing orders phase: Checking if the player has an order\n";
			if (playerList[i]->hasOrder()) {
				cout << "executing order for : " + playerList[i]->getName() + "\n";
				playerList[i]->executeOrder();
			}
			else {
				skip[i] = true;
				skipCounter++;
			}
		}
		i = (i + 1) % playerList.size();
	} while (skipCounter!= playerList.size());

	//Kills players without territories

	bool kill;
	for (int i = playerList.size()-1; i >= 0; i--) {
		kill = true;

		for (Territory* t : currentMap->getTerritories()) {
			if (t->getPlayerName() == playerList[i]->getName()) {
				kill = false;
			}
		}
		if (kill) {
			cout << playerList[i]->getName() << " has been killed\n";
			playerList.erase(playerList.begin() + i);
		}
	}

	//Checks if one players is left, meaning all territories are captured, game over

	if (playerList.size()==1) {
		cout << playerList[0]->getName() << " has captured all territories!!\n";
		return false;
	}
	
	//Checks if move rule is reached, if so, game is drawn

	/*
	if (rounds == limit) {
		cout << "Move limit has been reached, game is a draw!";
		return false;
	}
	*/

	//Next round continues

	cout << "next round\n";
	return true;
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
void GameEngine::Transition() {
	Notify(this);
}

string GameEngine::stringToLog() {
	return "Running Game Engine: ";
}

GameEngine::GameEngine() {
	playerList = vector<Player*>();
	state = GameState::start;
	cmdProc = new CommandProcessor();
	currentMap = nullptr;
	deck = new Deck(50);
}

GameEngine::GameEngine(GameEngine& copy) {}

GameEngine& GameEngine::operator =(const GameEngine& copy) { return *this; }

GameEngine::~GameEngine() {
	delete cmdProc;
	delete currentMap;
	delete deck;
	cmdProc = nullptr;
	currentMap = nullptr;
	deck = nullptr;
}

ostream& operator<<(ostream& output, GameEngine& t) { return output; }