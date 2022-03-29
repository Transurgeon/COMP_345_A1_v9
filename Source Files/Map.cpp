#include "../Header Files/Map.h"
using namespace std;


/// <summary>
/// Territory
/// </summary>
Territory::Territory()
{
	continentNum = 0;
	countryNum = 0;
	title = "";
	playerNum = -1;
	numberOfArmies = 0;
}

Territory::Territory(int con, int cou, int arm, string t)
{
	continentNum = con;
	countryNum = cou;
	title = t;
	playerNum = -1;
	numberOfArmies = arm;
}

Territory::Territory(const Territory& copy)
{
	continentNum = copy.continentNum;
	countryNum = copy.countryNum;
	title = copy.title;
	playerNum = copy.playerNum;
	numberOfArmies = copy.numberOfArmies;
}

Territory& Territory::operator =(const Territory& copy)
{
	continentNum = copy.continentNum;
	countryNum = copy.countryNum;
	title = copy.title;
	playerNum = copy.playerNum;
	numberOfArmies = copy.numberOfArmies;
	return *this;
}

void Territory::setPlayer(int p)
{
	playerNum = p;
}

void Territory::setArmy(int a)
{
	numberOfArmies = a;
}

void Territory::addArmy(int a) 
{
	numberOfArmies += a;
}

int Territory::getContinentNum()
{
	return continentNum;
}

int Territory::getCountryNum()
{
	return countryNum;
}

string Territory::getName()
{
	return title;
}

int Territory::getPlayer()
{
	return playerNum;
}

int Territory::getArmy() {

	return numberOfArmies;
}

void Territory::neutralState() {
	playerNum = -1;
}

Territory::~Territory()
{
}

ostream& operator<<(ostream& output, Territory& t)
{
	if (t.getPlayer() == 0) {
		output << "Territory number " << t.getCountryNum() << ", " << t.getName() << ", is in continent number " << t.getContinentNum() << ", and is owned by no player." << endl;
	}
	else {
		output << "Territory number " << t.getCountryNum() << ", " << t.getName() << ", is in continent number " << t.getContinentNum() << "is owned by player " << t.getPlayer() << " and has " << t.getArmy() << " armies on it." << endl;
	}
	return output;
}
/// <summary>
/// Continent
/// </summary>
Continent::Continent()
{
	continentNum = -1;
	bonus = -1;
	continentName = "";
}

Continent::Continent(int c, int b, string n)
{
	continentNum = c;
	bonus = b;
	continentName = n;
}

Continent::Continent(const Continent& copy)
{
	continentNum = copy.continentNum;
	bonus = copy.bonus;
	continentName = copy.continentName;
}

Continent& Continent::operator =(const Continent& copy)
{
	continentNum = copy.continentNum;
	bonus = copy.bonus;
	continentName = copy.continentName;
	return *this;
}

int Continent::getContinentNum()
{
	return continentNum;
}

int Continent::getBonus()
{
	return bonus;
}

string Continent::getContinentName()
{
	return continentName;
}

ostream& operator<<(ostream& output, Continent& c)
{
	output << "Continent " << c.getContinentNum() << ", " << c.getContinentName() << ", gives " << c.getBonus() << " bonus troop(s)." << endl;
	return output;
}

Continent::~Continent()
{
}
/// <summary>
/// Border
/// </summary>
Border::Border()
{
	root = -1;
}

Border::Border(int r)
{
	root = r;
}

Border::Border(const Border& copy)
{
	root = copy.root;
	edges = copy.edges;
}

Border& Border::operator =(const Border& copy)
{
	root = copy.root;
	edges = copy.edges;
	return *this;
}

void Border::addRoot(int r)
{
	root = r;
}

void Border::addEdge(int e)
{
	edges.push_back(e);
}

int Border::getRoot()
{
	return root;
}

vector<int> Border::getEdges()
{
	return edges;
}

ostream& operator<<(ostream& output, Border& b)
{
	output << "The border connects from " << b.getRoot() << " to ";
	for (int i : b.getEdges())
	{
		output << i << ", ";
	}
	output << endl;
	return output;
}

Border::~Border()
{
	edges.clear();
}

/// <summary>
/// Map
/// </summary>
Map::Map()
{

}

Map::Map(const Map& copy)
{
	territories = copy.territories;
	continents = copy.continents;
	borders = copy.borders;
}

Map& Map::operator =(const Map& copy) //added Map::operator and put the Map reference in front to create a deep copy
{
	territories = copy.territories;
	continents = copy.continents;
	borders = copy.borders;
	return *this;
}

bool Map::validate()
{
	//check 0: are the arrays filled, the size of territories are equal to borders, and the size of territories is >= to continents
	if (continents.size() == 0 || territories.size() == 0 || borders.size() == 0 || borders.size() != territories.size() || continents.size() > territories.size()) {
		return false;
	}

	//check 1: map is a connected graph
	//check 2: each continent is a connected subgraph

	vector<int> reachedTerritories;
	vector<int> reachedContinents;
	int start = 1;

	checkTerritoriesAndContinents(start, &reachedTerritories, &reachedContinents);

	if (reachedTerritories.size() != territories.size() || reachedContinents.size() != continents.size())
		return false;


	//check 3: each country belongs to one and only one continent

	for (Territory* i : territories) {

		int continentMatch = 0;
		for (Continent* j : continents)
		{
			if (i->getContinentNum() == j->getContinentNum())
				continentMatch++;
		}
		if (continentMatch != 1) {
			return false;
		}
	}

	return true;
}

//Checks if all territories can be reached from one node
void Map::checkTerritoriesAndContinents(int currentTerritory, vector<int>* passedTerritories, vector<int>* passedContinents) {

	int index = currentTerritory - 1;
	int continentNum = territories[index]->getContinentNum();

	if (!checkDuplicates(continentNum, passedContinents))
		passedContinents->push_back(continentNum);

	if (!checkDuplicates(currentTerritory, passedTerritories)) {

		passedTerritories->push_back(currentTerritory);
		for (int i : (*borders[index]).getEdges()) {
			checkTerritoriesAndContinents(i, passedTerritories, passedContinents);
		}
	}
}

bool Map::checkDuplicates(int currentTerritory, vector<int>* passedTerritories) {

	for (int i : *passedTerritories) {
		if (i == currentTerritory)
			return true;
	}
	return false;
}


void Map::addTerritory(int con, string t) {
	territories.push_back(new Territory(con, territories.size() + 1, 0, t));
}

void Map::addContinent(int b, string n) {
	int size = continents.size() + 1;
	continents.push_back(new Continent(continents.size(), b, n));
}

void Map::addBorderRoot(int r) {
	borders.push_back(new Border(r));
}

void Map::addBorderEdge(int r, int e) {
	borders.back()->addEdge(e);
}

vector<Territory*> Map::getTerritories() {
	return territories;
}

vector<Continent*> Map::getContinents() {
	return continents;
}

vector<Border*> Map::getBorders() {
	return borders;
}

bool Map::isAdjacentTerritory(Territory* source, Territory* target) {
	for (int i = 0; i < this->borders.size(); ++i) {
		if (borders[i]->getRoot() == source->getCountryNum()) {
			for (int j = 0; j < borders[i]->getEdges().size(); j++) {
				if (borders[i]->getEdges()[j] == target->getCountryNum())
					return true;
			}
		}
	}
	return false;
}

vector<Territory*> Map::getAllAdjacentTerritories(Territory territory) {
	int territoryId = territory.getCountryNum();
	vector<Territory*> adjTerritories;

	return adjTerritories;
}

int Map::getNumOfTerritoriesInContinent(int id) {
	int numOfTerritories = 0;
	for (int index = 0; index < this->territories.size(); ++index) {
		if (territories[index][0].getContinentNum() == id) {
			numOfTerritories++;
		}
	}
	return numOfTerritories;
}

int Map::getLastContinentId() {
	Territory lastTerritory = territories[this->territories.size() - 1][0];
	return lastTerritory.getContinentNum();
}

int Map::getArmyContinentBonus(int continentId) {
	for (int index = 0; index < this->territories.size(); ++index) {
		if (territories[index][0].getContinentNum() == continentId) {

		}
	}
	return 0;
}
ostream& operator<<(ostream& output, Map& m)
{
	for (Territory* i : m.getTerritories())
	{
		output << *i << endl;
	}
	for (Continent* i : m.getContinents())
	{
		output << *i << endl;
	}
	for (Border* i : m.getBorders())
	{
		output << *i << endl;
	}
	return output;
}

Map::~Map()
{
	territories.clear();
	continents.clear();
	borders.clear();
}

/// <summary>
/// MapLoader
/// </summary>
MapLoader::MapLoader() {}

MapLoader::MapLoader(const MapLoader& copy) {}

MapLoader& MapLoader::operator =(const MapLoader& copy) { return *this; }

MapLoader::~MapLoader() {}

ostream& operator<<(ostream& output, MapLoader& ml) { return output; }


Map MapLoader::addMap(string fileName) {
	//adds empty map object
	Map returnMap;
	int section = 0;
	bool skip;

	
	//reads file and fill map object
	string myText;
	ifstream myReadFile("./Map Files/" + fileName);
	if (myReadFile.good()) {
		while (getline(myReadFile, myText)) {
			try {
				skip = false;
				if (myText == "[continents]") {
					section = 1;
					skip = true;
				}
				else if (myText == "[countries]") {
					section = 2;
					skip = true;
				}
				else if (myText == "[borders]") {
					section = 3;
					skip = true;
				}
				if (!myText.empty() & !skip) {
					vector<string> split = splitString(myText);
					switch (section) {
					case 1:
						if (split.size() >= 3) {
							returnMap.addContinent(stoi(split[1]), split[0]);
						}
						break;
					case 2:
						if (split.size() >= 3) {
							returnMap.addTerritory(stoi(split[2]), split[1]);
						}
						break;
					case 3:
						if (split.size() >= 1) {
							returnMap.addBorderRoot(stoi(split[0]));
							for (int i = 1; i < split.size(); i++) {
								returnMap.addBorderEdge(stoi(split[0]), stoi(split[i]));
							}
						}
						break;
					}
				}
			}
			catch (const std::exception&) {}
		}
	}
	myReadFile.close();
	return returnMap;
}

vector<string> splitString(string str) {
	vector<string> split;
	if (!str.empty()) {
		while (str.find(" ") != -1) {
			split.push_back(str.substr(0, str.find(" ")));
			str = str.substr(str.find(" ") + 1);
		}
		if (!str.empty()) {
			split.push_back(str);
		}
	}

	return split;
}