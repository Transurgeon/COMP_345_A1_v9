#pragma once
#ifndef COMP_345_GameEngine_h
#define COMP_345_GameEngine_h

#include "../Header Files/Map.h"
#include "../Header Files/Cards.h"
#include "../Header Files/Orders.h"
#include "../Header Files/Player.h"
#include <iostream>
using namespace std;


class GameEngine {
private:
	//adding private variables for the GameEngine
	int playersNum;
	vector<Player*> playerList;
public:
	//Dummy Constructors, Assignment Operator and Destructor
	GameEngine();
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();

	//Begins game engine
	//changed runGameEngine to startupPhase();
	static void startupPhase();
	

	//Follows structure of flow chart
	static void loadAndValidateMap();
	static int addPlayers();
	
	//added new function called gameStart() and mainGameLoop;
	void gameStart();
	void mainGameLoop();

	static void assignReinforcements();
	static void issueOrders();
	static bool executeOrders();
	
	
	static void gameOver();
};

ostream& operator<<(ostream& output, GameEngine& t);

#endif