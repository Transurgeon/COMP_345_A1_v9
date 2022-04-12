#pragma once
#ifndef COMP_345_Player_h
#define COMP_345_Player_h

#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Map.h"
#include "../Header Files/Cards.h"
#include "../Header Files/Orders.h"
#include "../Header Files/PlayerStrategies.h"
using namespace std;


class Orderslist;
class Territory;
class Map;

class Player {
private:
    Hand* playerHand;
    Orderslist* orderList;
    int armyNum;
    string playerName;
    bool aliveStatus;
    vector<Territory*> defendList;
    vector<Territory*> attackList;
    PlayerStrategy* ps;
public:
    Player();
    Player(string name);
    ~Player();
    Player(const Player& player1);
    Player& operator=(const Player& player);

    vector<Territory*> toAttack(Map* m);
    vector<Territory*> toDefend(Map* m);
    void issueOrder(Map* map);

    void displayTerritories(vector<Territory*>);
    Orderslist* getOrderList();
    string getName();

    void addArmyNum(int number);
    void subtractArmyNum(int number);
    int getArmyNum();

    void killPlayer();
    bool isAlive();

    //new code for A3
    void setPlayerStrategy(PlayerStrategy* newStrat);
    Hand* getHand();
};
#endif
