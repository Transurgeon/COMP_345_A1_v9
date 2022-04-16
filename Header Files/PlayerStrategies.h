#pragma once
#ifndef COMP_345_PlayerStrategies_h
#define COMP_345_PlayerStrategies_h


#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Player.h"

using namespace std;
class Player;

class PlayerStrategy {
public:
	virtual void issueOrder(Map* m, Player* p, vector<Player*> pl) = 0;
	virtual void toAttack(Map* m, Player* p) = 0;
	virtual void toDefend(Map* m, Player* p) = 0;
};

class HumanPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m, Player* p, vector<Player*> pl);
	void toAttack(Map* m, Player* p);
	void toDefend(Map* m, Player* p);
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m, Player* p, vector<Player*> pl);
	void toAttack(Map* m, Player* p);
	void toDefend(Map* m, Player* p);
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m, Player* p, vector<Player*> pl);
	void toAttack(Map* m, Player* p);
	void toDefend(Map* m, Player* p);
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m, Player* p, vector<Player*> pl);
	void toAttack(Map* m, Player* p);
	void toDefend(Map* m, Player* p);
};

class CheaterPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m, Player* p, vector<Player*> pl);
	void toAttack(Map* m, Player* p);
	void toDefend(Map* m, Player* p);
};
#endif