#pragma once
#ifndef COMP_345_Map_h
#define COMP_345_Map_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

class Territory{
private:
    int *continentNum;
    int *countryNum;
    string* title;
    int* playerNum;

public:
    Territory();
    Territory(int con, int cou, string t); //use constructor initialization list
    Territory(const Territory &copy);
    Territory &operator =(const Territory &copy);

    void setPlayer(int p);
    int getContinentNum();
    int getCountryNum();
    string getName();
    int getPlayer();

    ~Territory();
};


class Continent{
private: 
    int *continentNum;
    int *bonus;
    string *continentName;

public:
    Continent();
    Continent(int *c, int *b, string *n);
    Continent(const Continent& copy);
    Continent& operator =(const Continent& copy);

    int getContinentNum();
    int getBonus();
    string getContinentName();

    ~Continent();
};

class Border {

private:
    int *root;
    vector<int*> edges;

public:
    Border();
    Border(const Border &copy);

    Border &operator =(const Border &copy);
    void addRoot(int r);
    void addEdge(int e);
    int getRoot();
    vector<int*> getEdges();

    ~Border();
};

class Map {
private:
    vector<Territory*> territories;
    vector<Continent*> continents;
    vector<Border*> borders;

public:
    Map();
    Map(const Map& copy);
    Map& operator =(const Map& copy);

    bool validate();
    void checkTerritoriesAndContinents(int* currentTerritory, vector<int>* passedTerritories, vector<int>* passedContinents);
    bool checkDuplicates(int* currentTerritory, vector<int>* passedTerritories);

    void addTerritory(Territory* t);
    void addContinent(Continent* c);
    void addBorder(Border* b);
    vector<Territory*> getTerritories();
    vector<Continent*> getContinents();
    vector<Border*> getBorders();

    ~Map();
};

class MapLoader {
public:
    //should add string = path file, maybe use user input instead
    MapLoader();
    MapLoader(const MapLoader& copy);
    MapLoader& operator =(const MapLoader& copy);

    Map CreateMap(); //create a map object from reading the .map file
    void readMapFile(); //might need to add input stream or remove completely

    ~MapLoader();
};


ostream& operator<<(ostream& output, Territory& t);
ostream& operator<<(ostream& output, Continent& c);
ostream& operator<<(ostream& output, Border& b);
ostream& operator<<(ostream& output, Map& m);
ostream& operator<<(ostream& output, MapLoader& ml);

#endif