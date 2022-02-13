#include "../Header Files/Map.h"
using namespace std;



/// <summary>
/// Territory
/// </summary>
Territory::Territory() 
{
	continentNum = new int(-1);
	countryNum = new int(-1);
	title = new string("");
	playerNum = new int(-1);
}

Territory::Territory(int con, int cou, string t) 
{
	continentNum = new int(con);
	countryNum = new int (cou);
	title = new string(t);
	playerNum = new int(-1);
}

Territory::Territory(const Territory& copy)
{
	continentNum = new int(*copy.continentNum);
	countryNum = new int(*copy.countryNum);
	title = new string(*copy.title);
	playerNum = new int(*copy.playerNum);
}

Territory& Territory::operator =(const Territory& copy)
{
	continentNum = new int(*copy.continentNum);
	countryNum = new int(*copy.countryNum);
	title = new string(*copy.title);
	playerNum = new int(*copy.playerNum);
	return *this;
}

void Territory::setPlayer(int p)
{
	*playerNum = p;
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

Territory::~Territory()
{
	delete continentNum;
	delete countryNum;
	delete title;
	delete playerNum;
	continentNum = NULL;
	countryNum = NULL;
	title = NULL;
	playerNum =	NULL;
}

ostream& operator<<(ostream& output, Territory& t) 
{
	output << " This territory is called " << t.getName() << " the country number is: " << t.getCountryNum()<< endl;
	output << " This territory is part of the continent number: " << t.getContinentNum() << " it is owned by player " << t.getPlayer() << endl;
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

Continent::Continent(int* c, int* b, string* n)
{
	continentNum = c;
	bonus = b;
	continentName = n;
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
	output << " This continent is called : " << c.getContinentName() << " and is the continent number :" << c.getContinentNum() << endl;
	output << " Holding this continent gives a bonus of : " << c.getBonus() << " troups per round" << endl;
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

void Border:: addRoot(int r)
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
	//should try catch be used?

	/*Pseudo-Code for validate();
	//NEED TO IMPLEMENT bool DepthSearch(vector<Territory>* territories) RIGHT?
	check 1: map is a connected graph
	https://www.geeksforgeeks.org/check-if-a-directed-graph-is-connected-or-not/

	if (DepthSearch(Map.getTerritories) == false)
		return false;
	check 2: each continent is a connected subgraph
	for (each continent) {
		vector<Territories>* Territories_In_continent;
		for (each Territory) {
			if (Territory.getContinent == Continent)
				Territories_In_continent.push_back(Territory);
		}
		if (DepthSearch(Territories_In_continent) == false)
		return false;
	}

	check 3: each country belongs to one and only one continent
	for (each territory) {
		int continentMatch = 0;

		for (each continent) {
			if (territory.getContinentNum == Continent)
				continentMatch++;
		}
		if (continentMatch != 1) {
			return false;
		}
	}*/

	return true;
}

void Map::addTerritory(Territory* t) {
	territories.push_back(t);
}

void Map::addContinent(Continent* c) {
	continents.push_back(c);
}

void Map::addBorder(Border* b) {
	borders.push_back(b);
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
	output << "Number of territories: " << m.getTerritories().size() << ", number of continents: " << m.getContinents().size() << ", number of borders: " << m.getBorders().size() << endl;
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

Map MapLoader::CreateMap()
{
	return Map();
}

void MapLoader::readMapFile()
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
	/*output << " This territory is called" << t.getName() << " the country number is:" << t.getCountryNum() << endl;
	output << " This territory is part of the continent number: " << t.getContinent() << " it is owned by" << t.getName() << endl;
	return output;*/
	output << "hi";
	return output;
}