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
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class CheaterPlayerStrategy : public PlayerStrategy {
public:
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};
#endif