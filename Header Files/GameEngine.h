#pragma once
#ifndef COMP_345_GameEngine_h
#define COMP_345_GameEngine_h

#include <iostream>
using namespace std;


class GameEngine {
public:
	//Dummy Constructors, Assignment Operator and Destructor
	GameEngine();
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();

	//Begins game engine
	static void runGameEngine();

	//Follows structure of flow chart
	static void loadAndValidateMap();
	static int addPlayers();
	static void assignReinforcements();
	static void issueOrders();
	static bool executeOrders();
	static void gameOver();
};

ostream& operator<<(ostream& output, GameEngine& t);

#endif