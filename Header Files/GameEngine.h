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
using namespace std;


class GameEngine : public ILoggable, public Subject {
private:
	//adding private variables for the GameEngine
	int playersNum;
	// vector<Player*> playerList;
	GameState* state;
	CommandProcessor* cmdProc;
	Map* currentMap;
public:
	

	
	//Begins game engine
	//changed runGameEngine to startupPhase();
	void startupPhase();
	
	//Follows structure of flow chart
	void loadMap(string fileName);
	bool validateMap();
	void deleteMap();
	void addPlayer();
	
	//added new function called gameStart() and mainGameLoop;
	void gameStart();
	void mainGameLoop();

	void assignReinforcements();
	void issueOrders();
	void executeOrders();
	
	
	void gameOver();



	//Methods for Game
	/*void setState(GameState gs);
	GameState getState();
	void Transition();
	string stringToLog() override;*/

	//Constructors, Assignment Operator and Destructor
	GameEngine();
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();
};

ostream& operator<<(ostream& output, GameEngine& t);

#endif