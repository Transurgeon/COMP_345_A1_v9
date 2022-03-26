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
	//vector<Player*> playerList;
	GameState state;
	CommandProcessor* cmdProc;
	string userCmd;
public:
	//Dummy Constructors, Assignment Operator and Destructor
	GameEngine();
	GameEngine(CommandProcessor* cp);
	GameEngine(GameEngine& copy);
	GameEngine& operator =(const GameEngine& copy);
	~GameEngine();

	void setState(GameState gs);
	GameState getState();
	void Transition();
	string stringToLog() override;
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