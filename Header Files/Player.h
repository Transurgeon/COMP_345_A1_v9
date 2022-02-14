#pragma once
#ifndef COMP_345_Player_h
#define COMP_345_Player_h

#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Map.h"
#include "../Header Files/Cards.h"
#include "../Header Files/Orders.h"
using namespace std;

class Player {

private:
	vector<Territory*> territoriesNum;
	Hand* playerCards; //changed vector<Cards>* to Hand*
	OrdersList* playerOrders;

public:
	Player();
	Player(vector<Territory*> t, Hand* h, OrdersList* o);
	Player(const Player& copy);
	Player& operator =(const Player& copy);

	void assignTerritories();
	vector<Territory*> toDefend(); // might do []Territory* instead of void
	void toAttack(); 
	vector<Territory*> getTerritoriesNum();
	Hand* getPlayerCards();
	OrdersList* getPlayerOrders();
	vector<OrdersList*> issueOrder();

	~Player();

	friend ostream& operator<<(ostream& output, Player& p);
};
#endif
