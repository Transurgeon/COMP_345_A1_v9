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
		if (territories[currentTerritory]->getName() == "") {
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
		cout << playerList[i]->getName() << " will choose where to place their troops:\n";
		troops = 50;
		currentTerritory = 0;
		do {
			cout << "Remaining troops: " << troops << endl;
			while (territories[currentTerritory]->getName() == playerList[i]->getName()) {currentTerritory = (currentTerritory + 1) % territories.size();}

			cout << "How many troops do you want to place on " << territories[currentTerritory]->getName() <<"?\n";
			cin >> input;
			while (!checkNumber(input) || stoi(input) < 0 || stoi(input) > troops) {
				cout << "Incorrect input! Please make sure to write a whole number between 0 and " << troops << endl;
				cin >> input;
			}
			territories[currentTerritory]->addArmy(stoi(input));
			troops -= stoi(input);
			cout <<"\n" + input + " troops were added to " + territories[currentTerritory]->getName() + ", making the total troops "
				<< territories[currentTerritory]->getArmy() << " on that terrtitory.\n";

			currentTerritory = (currentTerritory+1)%territories.size();
		} while (troops > 0);
		cout << "\n\n";
	}

	cout << "\nEach player draws 2 cards from the deck to their hand" << endl;
	for (int j = 0; j < playerList.size(); j++) {
		cout << playerList[j]->getName() << " picks the following 2 cards:";
		deck->draw(*playerList[j]->getHand());
		deck->draw(*playerList[j]->getHand());
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

bool checkNumber(string str) {
	for (int i = 0; i < str.length(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

bool GameEngine::mainGameLoop() {
	cout << "reinforcementPhase" << endl;
	assignReinforcements();
	cout << "issueOrdersPhase" << endl;
	issueOrders();
	cout << "executeOrdersPhase" << endl;
	return executeOrders();
}

void GameEngine::assignReinforcements() {

	state = GameState::assignReinforcements;
	string input;
	int troops;
	int countriesOwned;
	int continentsOwned;
	vector<Territory*> territories = currentMap->getTerritories();
	for (int i = 0; i < playerList.size(); i++) {
		
		
		troops = 0;
		countriesOwned = 0;
		continentsOwned = 0;
		for (int j = 0; j < territories.size(); j++) {
			if (territories[j]->getName() == playerList[i]->getName()) {
				troops++;
				countriesOwned++;
			}
		}
		troops /= 3;
		bool bonus;
		for (int j = 0; j < currentMap->getContinents().size(); j++) {
			bonus = true;
			for (int k = 0; k < territories.size(); k++) {

				if (territories[k]->getContinentNum() == j + 1 && territories[k]->getName() != playerList[i]->getName()) {
					bonus = false;
				}
			}
			if (bonus) {
				troops += currentMap->getContinents()[j]->getBonus();
				continentsOwned++;
			}
		}
		if (troops < 3)
			troops = 3;

		playerList[i]->addArmyNum(troops);
		
		cout << "Assigned " << troops << " troops for " << playerList[i]->getName()<<", owning "<< countriesOwned <<
			" territories and " << continentsOwned << " continents.\n\n";
	}
}

void GameEngine::issueOrders() {
	state = GameState::issueOrders;
	
	for (int i = 0; i < playerList.size(); i++) {
		cout << "Issue Orders Stage 1: Deploying \n" << endl;
	}

	string input = "";
	for (int i = 0; i < playerList.size(); i++) {
		cout << "Issue Orders Stage 2: Other Orders \n" << endl;
		cout << "Here is the list of orders\n1.Advance\n2.Bomb\n3.Blockade\n4.Airlift\n5.Negotiate\n";
		cin >> input;
	if (input == "Advance") {
		cout << "Preparation for advance order :\n";
		}

	}
	
	string buffer;
	vector<Territory*> list;
	for (int i = 0; i < playerList.size(); i++) {
		cout << playerList[i]->getName() << " has " <<playerList[i]->getArmyNum() << " troops in reserve.\n";
		cout << "Territories to attack:\n";

		list = playerList[i]->toAttack(currentMap);
		for (int j = 0; j < list.size(); j++) {
			cout << *list[j] << endl;
		}
		

		cout << "\n\nTerritories to defend: \n";

		list = playerList[i]->toDefend(currentMap);
		for (int j = 0; j < list.size(); j++) {
			cout << *list[j] << endl;
		}
		

		cin >> buffer;

	}
}

bool GameEngine::executeOrders() {
	state = GameState::executeOrders;
	cout << "Execute Orders Stage" << endl;
	string input;
	for (int i = 0; i < 5; i++) {
		cout << "**Executing Orders**" << endl;

	}
	if (random(1, 3) == 1) {
		cout << "Somebody has captured all territries\n";
		return false;
	}

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