#pragma once
#ifndef COMP_345_PlayerStrategies_h
#define COMP_345_PlayerStrategies_h


#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Player.h"
using namespace std;


class PlayerStrategy {
private:
	Player* p;
public:
	virtual void issueOrder() = 0;
	virtual vector<Territory*> toAttack() = 0;
	virtual vector<Territory*> toDefend() = 0;
};

class HumanPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m);
	vector<Territory*> toAttack(Map* m);
	vector<Territory*> toDefend(Map* m);
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m);
	vector<Territory*> toAttack(Map* m);
	vector<Territory*> toDefend(Map* m);
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m);
	vector<Territory*> toAttack(Map* m);
	vector<Territory*> toDefend(Map* m);
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m);
	vector<Territory*> toAttack(Map* m);
	vector<Territory*> toDefend(Map* m);
};

class CheaterPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder(Map* m);
	vector<Territory*> toAttack(Map* m);
	vector<Territory*> toDefend(Map* m);
};
#endif