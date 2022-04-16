#pragma once
#ifndef COMP_345_Map_h
#define COMP_345_Map_h

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;

class Territory {
private:
    int continentNum;
    int countryNum;
    string title;
    string playerName;
    int numberOfArmies;

public:
    //Constructors, Assignment Operator and Destructor
    Territory();
    Territory(int con, int cou, int arm, string t); 
    Territory(const Territory& copy);
    Territory& operator =(const Territory& copy);
    ~Territory();

    //Setters and Getters
    void setPlayer(string p);
    void addArmy(int a);
    void subtractArmy(int a);
    int getContinentNum();
    int getCountryNum();
    string getName();
    string getPlayerName();
    int getArmy();

    void neutralState();
};

bool compareTerritory(Territory* a, Territory*);

class Continent {
private:
    int continentNum;
    int bonus;
    string continentName;

public:
    //Constructors, Assignment Operator and Destructor
    Continent();
    Continent(int c, int b, string n);
    Continent(const Continent& copy);
    Continent& operator =(const Continent& copy);
    ~Continent();

    //Getters
    int getContinentNum();
    int getBonus();
    string getContinentName();

    
};

class Border {

private:
    int root;
    vector<int> edges;

public:
    //Constructors, Assignment Operator and Destructor
    Border();
    Border(int r);
    Border(const Border& copy);
    Border& operator =(const Border& copy);
    ~Border();
    void print();

    //Setters and Getters
    void addRoot(int r);
    void addEdge(int e);
    int getRoot();
    bool containsTerritory(int t);
    vector<int> getEdges();

    
};

class Map {
private:
    vector<Territory*> territories;
    vector<Continent*> continents;
    vector<Border*> borders;

public:
    //Constructors, Assignment Operator and Destructor
    Map();
    Map(const Map& copy);
    Map& operator =(const Map& copy);
    ~Map();

    //Validate method, used to check if class is valid
    bool validate();
    //Method used to check if all nodes are connected
    void checkTerritoriesAndContinents(int currentTerritory, vector<int>* passedTerritories, vector<int>* passedContinents);
    //Custom defined .contains() function for vector since C++ does not have one
    bool checkDuplicates(int currentTerritory, vector<int>* passedTerritories);

    //Adds objects to map object using constructors
    void addTerritory(int con, string t);
    void addContinent(int b, string n);
    void addBorderRoot(int r);
    void addBorderEdge(int r, int e);
    void printTerritory(int index);
    void printMap();
    vector<Territory*> getTerritories();
    vector<Continent*> getContinents();
    vector<Border*> getBorders();
    //new functions
    bool isAdjacentTerritory(Territory* source, Territory* target);
    vector<int> getAllAdjacentTerritories(Territory territory);
    int getNumOfTerritoriesInContinent(int id);
    int getArmyContinentBonus(int continentId);
};

class MapLoader {

public:
    //Constructors, Assignment Operator and Destructor
    //Not used, only here to fulfill assignment rubric
    MapLoader();
    MapLoader(const MapLoader& copy);
    MapLoader& operator =(const MapLoader& copy);
    ~MapLoader();

    //Add maps and reads file user inputs
    static Map* addMap(string fileName);
};
//Helper .split() method for reading lines in map files
vector<string> splitString(string str);

//OutputStream operators for all classes
ostream& operator<<(ostream& output, Territory& t);
ostream& operator<<(ostream& output, Continent& c);
ostream& operator<<(ostream& output, Border& b);
ostream& operator<<(ostream& output, Map& m);
ostream& operator<<(ostream& output, MapLoader& ml);

#endif