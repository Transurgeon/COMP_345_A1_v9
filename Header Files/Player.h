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
    vector<Territory*> defendList;
    vector<Territory*> attackList;
    PlayerStrategy* ps;
    bool isNeutral;
public:
    Player();
    Player(string name);
    ~Player();
    Player(const Player& player1);
    Player& operator=(const Player& player);

    void toAttack(Map* m);
    void toDefend(Map* m);
    vector<Territory*> getAttackList();
    vector<Territory*> getDefendList();
    void issueOrder(Map* map);
    void executeOrder();
    bool hasOrder();

    bool ownsTerritory(Territory* t);

    string getName();

    void addArmyNum(int number);
    void subtractArmyNum(int number);
    int getArmyNum();

    //new code for A3
    void checkAggressive();
    Hand* getHand();
};
#endif
