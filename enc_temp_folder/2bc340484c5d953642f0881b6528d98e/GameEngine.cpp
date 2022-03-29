#include "../Header Files/GameEngine.h"
#include "../Header Files/Map.h"


//runs game and follow structure of flow chart
void GameEngine::startupPhase() {

	cout << "Starting game, load a map\n";
	cout << "\n\n------------\nCommand list:\nloadmap <mapfile>\nvalidatemap\naddplayer <playername>\ngamestart\nreplay\nquit\n------------\n\n\n";
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
	
	cout << "Fairly distributing territories to the players" << endl;
	vector<Territory*> territories = currentMap->getTerritories();
	int leftOverTerritories = territories.size();
	int currentTerritory = random(0, territories.size() -1);
	int currentPlayer = 0;
	while (leftOverTerritories > 0) {
		if (territories[currentTerritory]->getPlayer() == -1) {
			territories[currentTerritory]->setPlayer(currentPlayer);
			//playerList[currentPlayer].addTerritory(currentTerritory);
			currentPlayer = (currentPlayer + 1) % playerList.size();
			leftOverTerritories--;
		}
		currentTerritory = (currentTerritory + random(1, leftOverTerritories)) % territories.size();
	}
	cout << "Determining a random order of play for the players" << endl;

	std::random_shuffle(playerList.begin(), playerList.end());

	cout << "The order will be: ";
	for (int i = 0; i < playerList.size()-1;i++)
	{
		cout << playerList[i]->getPlayerName() + ", ";
	}
	cout << playerList[playerList.size() - 1] << endl;

	cout << "Giving 50 troops to each player" << endl;
	int troops;
	string input;
	for (int i = 0; i < playerList.size(); i++) {
		cout << playerList[i] << " will choose where to place their troops:\n";
		troops = 50;
		currentTerritory = 0;
		do {
			cout << "Remaining troops: " << troops << endl;
			while (territories[currentTerritory]->getPlayer() == i) {currentTerritory = (currentTerritory + 1) % territories.size();}

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

	cout << "Each player draws 2 cards from the deck to their hand" << endl;
	for (int j = 0; j < playerList.size(); j++) {
		//playerList[j]->getPlayerCards.draw();
		//playerList[j]->getPlayerCards.draw();
	}
	cout << "\n\nGame is starting\n\n";
	
	do {} while (mainGameLoop());
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
			if (territories[j]->getPlayer() == i); {
				troops++;
				countriesOwned++;
			}
		}
		troops /= 3;
		bool bonus;
		for (int j = 0; j < currentMap->getContinents().size(); j++) {
			bonus = true;
			for (int k = 0; k < territories.size(); k++) {

				if (territories[k]->getContinentNum() == k + 1 && territories[k]->getPlayer() != i + 1) {
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
		
		cout << "Assigned " << troops << " troops for " << playerList[i]->getPlayerName()<<", owning "<< countriesOwned <<
			" territories and " << continentsOwned << " continents.\n\n";
	}
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
	cout << "Did you capture all territories? This means you won (Type \"yes\" if you agree, anything else otherwise) ";
	cin >> input;

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
//void GameEngine::Transition() {
//	Notify(this);
//}
//
string GameEngine::stringToLog() {
	return "Running Game Engine: ";
}

GameEngine::GameEngine() {
	playerList = vector<Player*>();
	state = GameState::start;
	cmdProc = new CommandProcessor();
	currentMap = nullptr;
}

GameEngine::GameEngine(GameEngine& copy) {}

GameEngine& GameEngine::operator =(const GameEngine& copy) { return *this; }

GameEngine::~GameEngine() {
	delete cmdProc;
	delete currentMap;
	cmdProc = nullptr;
	currentMap = nullptr;
}

ostream& operator<<(ostream& output, GameEngine& t) { return output; }