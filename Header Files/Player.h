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
	vector<Territory*> DefList;
	vector<Territory*> AtkList;
	Hand* playerCards; 
	OrdersList* playerOrders;
	//new player attributes
	int troops;
	int playerNum;
public:
	Player();
	Player(vector<Territory*> t, Hand* h, OrdersList* o);
	Player(const Player& copy);
	Player& operator =(const Player& copy);

	vector<Territory*> toDefend(); 
	vector<Territory*> toAttack();
	vector<Territory*> showTerritories();

	void attack(Territory* a);
	void defend(Territory* d);
	void add(Territory* t);

	//added getters and setters for troops and playerNum
	int getTroops();
	void setTroops(int t);
	int getPlayerNum();
	void setPlayerNum(int p);

	vector<Territory*> getTerritoriesNum();
	Hand* getPlayerCards();
	OrdersList* getPlayerOrders();
	void issueOrder(Order* order);

	~Player();

	friend ostream& operator<<(ostream& output, Player& p);
};
#endif
