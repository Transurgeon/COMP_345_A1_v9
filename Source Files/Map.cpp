#include "../Header Files/Map.h"
using namespace std;


/// <summary>
/// Territory
/// </summary>
Territory::Territory()
{
	continentNum = new int(0);
	countryNum = new int(0);
	title = new string("");
	playerNum = new int(0);
	numberOfArmies = new int(0);
}

Territory::Territory(int con, int cou, string t)
{
	continentNum = new int(con);
	countryNum = new int(cou);
	title = new string(t);
	playerNum = new int(0);
	numberOfArmies = new int(0);
}

Territory::Territory(const Territory& copy)
{
	continentNum = new int(*copy.continentNum);
	countryNum = new int(*copy.countryNum);
	title = new string(*copy.title);
	playerNum = new int(*copy.playerNum);
	numberOfArmies = new int(*copy.numberOfArmies);
}

Territory& Territory::operator =(const Territory& copy)
{
	continentNum = new int(*copy.continentNum);
	countryNum = new int(*copy.countryNum);
	title = new string(*copy.title);
	playerNum = new int(*copy.playerNum);
	numberOfArmies = new int(*copy.numberOfArmies);
	return *this;
}

void Territory::setPlayer(int p)
{
	*playerNum = p;
}

void Territory::setArmy(int a)
{
	*numberOfArmies = a;
}

int Territory::getContinentNum()
{
	return *continentNum;
}

int Territory::getCountryNum()
{
	return *countryNum;
}

string Territory::getName()
{
	return *title;
}

int Territory::getPlayer()
{
	return *playerNum;
}

int Territory::getArmy() {

	return *numberOfArmies;
}

Territory::~Territory()
{
	delete continentNum;
	delete countryNum;
	delete title;
	delete playerNum;
	delete numberOfArmies;
	continentNum = NULL;
	countryNum = NULL;
	title = NULL;
	playerNum = NULL;
	numberOfArmies = NULL;
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
	continentNum = new int(-1);
	bonus = new int(-1);
	continentName = new string("");
}

Continent::Continent(int c, int b, string n)
{
	continentNum = new int(c);
	bonus = new int(b);
	continentName = new string(n);
}

Continent::Continent(const Continent& copy)
{
	continentNum = new int(*copy.continentNum);
	bonus = new int(*copy.bonus);
	continentName = new string(*copy.continentName);
}

Continent& Continent::operator =(const Continent& copy)
{
	continentNum = new int(*copy.continentNum);
	bonus = new int(*copy.bonus);
	continentName = new string(*copy.continentName);
	return *this;
}

int Continent::getContinentNum()
{
	return *continentNum;
}

int Continent::getBonus()
{
	return *bonus;
}

string Continent::getContinentName()
{
	return *continentName;
}

ostream& operator<<(ostream& output, Continent& c)
{
	output << "Continent " << c.getContinentNum() << ", " << c.getContinentName() << ", gives " << c.getBonus() << " bonus troop(s)." << endl;
	return output;
}

Continent::~Continent()
{
	delete continentNum;
	delete bonus;
	delete continentName;
	continentNum = NULL;
	bonus = NULL;
	continentName = NULL;
}
/// <summary>
/// Border
/// </summary>
Border::Border()
{
	root = new int(-1);
}

Border::Border(int r)
{
	root = new int(r);
}

Border::Border(const Border& copy)
{
	root = new int(*copy.root);
	edges = copy.edges;
}

Border& Border::operator =(const Border& copy)
{
	root = new int(*copy.root);
	edges = copy.edges;
	return *this;
}

void Border::addRoot(int r)
{
	*root = r;
}

void Border::addEdge(int e)
{
	edges.push_back(new int(e));
}

int Border::getRoot()
{
	return *root;
}

vector<int*> Border::getEdges()
{
	return edges;
}

ostream& operator<<(ostream& output, Border& b)
{
	output << "The border connects from " << b.getRoot() << " to ";
	for (int* i : b.getEdges())
	{
		output << *i << ", ";
	}
	output << endl;
	return output;
}

Border::~Border()
{
	delete root;
	root = nullptr;

	for (int* i : edges)
	{
		delete i;
		i = nullptr;
	}
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

	checkTerritoriesAndContinents(&start, &reachedTerritories, &reachedContinents);

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

void Map::checkTerritoriesAndContinents(int* currentTerritory, vector<int>* passedTerritories, vector<int>* passedContinents) {

	int continentNum = territories[(*currentTerritory) - 1]->getContinentNum();

	if (!checkDuplicates(&continentNum, passedContinents))
		passedContinents->push_back(continentNum);

	if (!checkDuplicates(currentTerritory, passedTerritories)) {

		passedTerritories->push_back(*currentTerritory);
		for (int* i : (*borders[(*currentTerritory) - 1]).getEdges()) {
			checkTerritoriesAndContinents(i, passedTerritories, passedContinents);
		}
	}
}

bool Map::checkDuplicates(int* currentTerritory, vector<int>* passedTerritories) {

	for (int i : *passedTerritories) {
		if (i == *currentTerritory)
			return true;
	}
	return false;
}


void Map::addTerritory(int con, string t) {
	territories.push_back(new Territory(con, territories.size() + 1, t));
}

void Map::addContinent(int b, string n) {
	continents.push_back(new Continent(continents.size() + 1, b, n));
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
	for (Territory* i : territories)
	{
		delete i;
		i = nullptr;
	}
	for (Continent* i : continents)
	{
		delete i;
		i = nullptr;
	}
	for (Border* i : borders)
	{
		delete i;
		i = nullptr;
	}
}

/// <summary>
/// MapLoader
/// </summary>
MapLoader::MapLoader()
{

}

MapLoader::MapLoader(const MapLoader& copy)
{

}

MapLoader& MapLoader::operator =(const MapLoader& copy)
{
	return *this;
}

MapLoader::~MapLoader()
{

}

ostream& operator<<(ostream& output, MapLoader& ml)
{
	return output;
}

vector<Map*> MapLoader::loadedMaps;

void MapLoader::loadMaps() {


}

void MapLoader::addMap() {
	loadedMaps.push_back(new Map());
	int section = 0;
	bool skip;

	cout << "Input map file name: ";
	string fileName; //= "europe.map";
	cin >> fileName;

	string myText;
	ifstream myReadFile("./Map Files/" + fileName);
	if (myReadFile.good()) {
		while (getline(myReadFile, myText)) {
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
					loadedMaps.back()->addContinent(stoi(split[1]), split[0]);
					break;
				case 2:
					loadedMaps.back()->addTerritory(stoi(split[2]), split[1]);
					break;
				case 3:
					loadedMaps.back()->addBorderRoot(stoi(split[0]));
					for (int i = 1; i < split.size(); i++) {
						loadedMaps.back()->addBorderEdge(stoi(split[0]), stoi(split[i]));
					}
					break;
				}
			}
		}
	}
	myReadFile.close();
}

void MapLoader::validateMaps() {
	int i = 1;
	for (Map* m : loadedMaps) {
		try {
			if (!m->validate()) {
				cout << "Map " << i << " is not valid" << endl;
				delete m;
				m = nullptr;
				loadedMaps.erase(loadedMaps.begin() + i - 1);
			}
			else
			{
				cout << "Map " << i << " is valid" << endl;
			}
			i++;
		}
		catch (const std::exception&) {

			cout << "Map " << i << " is not valid" << endl;
			delete m;
			m = nullptr;
			loadedMaps.erase(loadedMaps.begin() + i - 1);
		}
	}
}

void MapLoader::showMap(int index) {
	cout << *loadedMaps[index];
}

void MapLoader::showAllMaps() {
	int index = 1;
	for (Map* i : loadedMaps) {
		cout << endl << "*****************************************"
			<< endl << "               Map " << index
			<< endl << "*****************************************"
			<< endl << endl;
		cout << *i;
		index++;
	}
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

void MapLoader::deleteAllMaps() {

	for (Map* i : loadedMaps) {
		delete i;
		i = nullptr;
	}
}