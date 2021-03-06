#pragma once
#ifndef COMP_345_GameEngine_h
#define COMP_345_GameEngine_h

#include "../Header Files/Map.h"
#include "../Header Files/Cards.h"
#include "../Header Files/Orders.h"
#include "../Header Files/Player.h"
#include "../Header Files/CommandProcessing.h"
#include "../Header Files/LoggingObserver.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Player;

class GameEngine : public ILoggable, public Subject {
private:
	//adding private variables for the GameEngine
	vector<Player*> playerList;
	GameState state;
	CommandProcessor* cmdProc;
	Map* currentMap;
	int maxTurns;
	int turns;
	string output;
public:
	
	//Begins game engine
	//changed runGameEngine to startupPhase();
	void startupPhase();
	
	void tournamentMode(string command);
	//Follows structure of flow chart
	void loadMap(string fileName);
	void validateMap();
	void deleteMap();
	void addPlayer(string name);
	
	//added new function called gameStart() and mainGameLoop;
	void gameStart();
	bool mainGameLoop();

	void assignReinforcements();
	void issueOrders();
	bool executeOrders();

	//Methods for Game
	/*void setState(GameState gs);
	GameState getState();*/
	void Transition();
	string stringToLog() override;

	//Constructors, Assignment Operator and Destructor
	GameEngine();
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();
};

int random(int min, int max);
bool checkNumber(string str);
string format(string str);

ostream& operator<<(ostream& output, GameEngine& t);

#endif