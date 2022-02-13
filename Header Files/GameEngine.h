#pragma once
#ifndef COMP_345_GameEngine_h
#define COMP_345_GameEngine_h

#include <iostream>
using namespace std;

void runGame();

namespace GameEngine {

	void loadMap();
	void addPlayers();
	void assignReinforcements();
	void issueOrders();
	bool executeOrders();
	bool gameOver();
};

#endif