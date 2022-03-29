#include "../Header Files/GameEngine.h"
#include "../Header Files/Map.h"


//runs game and follow structure of flow chart
void GameEngine::startupPhase() {

	cout << "Starting Game\n";
	cout << "Enter a command\n";

	do {
		cmdProc->getCommand();
		string commandType = cmdProc->validate(state);
		string commandArgument;
		if (commandType.find_first_of("<") != -1)
		{
			commandArgument = commandType.substr(commandType.find_first_of("<") + 1,
			commandType.find_first_of(">") - commandType.find_first_of("<") -1);
		}
		commandType = commandType.substr(0, commandType.find_first_of(" "));

		cout << "commandType: " + commandType + "    commandArgument: " + commandArgument << endl;
		if (commandType == "loadmap") {
			loadMap(commandArgument);
		}
		else if (commandType == "validatemap") {
			validateMap();
		}
		else if (commandType == "addplayer") {
			addPlayer(commandType);
		}
		else if (commandType == "gamestart") {
			gameStart();
		} 
	} while (state != GameState::exitProgram);
}

void GameEngine::loadMap(string fileName) {
	state = GameState::mapLoaded;
	deleteMap();
	currentMap = MapLoader::addMap(fileName);
	cout << "Adding or changing Map\n";
}

void GameEngine::validateMap() {

	if (currentMap->validate()) {
		state = GameState::mapValidated;
		cout << "Map is valid, please add players";
		return;
	}

	state = GameState::start;
	cout << "Map is not valid, return to start screen";
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
		playerList.push_back(name);
		cout << "Player " + name + " was added";
	}
	else {
		cout << "Too many players, " + name + " was not added";
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
		cout << playerList[i] + ", ";
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
			cout << "Remaining troops: " + troops << endl;
			while (territories[currentTerritory]->getPlayer() == i) {currentTerritory++;}

			cout << "How many troops do you want to place on " << territories[currentTerritory]->getName() <<"?\n";
			cin >> input;
			while (!checkNumber(input) || stoi(input) < 0 || stoi(input) > troops) {
				cout << "Incorrect input! Please make sure to write a whole number between 0 and " + troops << endl;
			}
			territories[currentTerritory]->addArmy(stoi(input));
			cout << input + " troops were added to " + territories[currentTerritory]->getName() + ", making the total troops "
				<< territories[currentTerritory]->getArmy() << " on that terrtitory.\n";

		} while (troops > 0);
		cout << "\n\n\n";
	}

	cout << "Each player draws 2 cards from the deck to their hand" << endl;
	for (int j = 0; j < playerList.size(); j++) {
		//playerList[j]->getPlayerCards.draw();
		//playerList[j]->getPlayerCards.draw();
	}
}

int random(int min, int max)
{
	static bool first = true;
	if (first){
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

bool checkNumber(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
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
string GameEngine::stringToLog() {
	return "Running Game Engine: ";
}

GameEngine::GameEngine() {
	playerList = vector<string>();
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