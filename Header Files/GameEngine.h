#pragma once
#ifndef COMP_345_GameEngine_h
#define COMP_345_GameEngine_h

#include <iostream>
using namespace std;


class GameEngine {
public:
	GameEngine();
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();

	static void runGameEngine();
	static void loadAndValidateMap();
	static void addPlayers();
	static void assignReinforcements();
	static void issueOrders();
	static bool executeOrders();
	static void gameOver();
};

ostream& operator<<(ostream& output, GameEngine& t);

#endif