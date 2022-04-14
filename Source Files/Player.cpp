#include "../Header Files/Player.h"
#include <stack>


//Player constructor
Player::Player() {
    //player owns a hand
    playerHand = new Hand();
    orderList = new Orderslist();
    playerName = "";
    ps = new HumanPlayerStrategy();
    isNeutral = false;
    armyNum = 50;
}

//Player constructor (with name)
Player::Player(string name) {
    playerHand = new Hand();
    orderList = new Orderslist();
    armyNum = 50;
    playerName = name;
    defendList = vector<Territory*>();
    isNeutral = false;
    if (name == "Aggressive") {
        ps = new AggressivePlayerStrategy();
    }
    else if (name == "Benevolent") {
        ps = new BenevolentPlayerStrategy();
    } 
    else if (name == "Neutral") {
        ps = new NeutralPlayerStrategy();
        isNeutral = true;
    }
    else if (name == "Cheater") {
        ps = new CheaterPlayerStrategy();
    }
    else {
        ps = new HumanPlayerStrategy();
    }
}

//Player destructor
Player::~Player(){

    delete playerHand;
    delete orderList;
}

Player::Player(const Player& player1) {
    
}

Player& Player::operator=(const Player& player1) {
    return *this;
}

void Player::toAttack(Map* m) {
    ps->toAttack(m, this);
}

void Player::toDefend(Map* m) {
    ps->toDefend(m, this);
}

void Player::issueOrder(Map* m) {
    ps->issueOrder(m, this);
}


void Player::addOrder(Order* o) {
    orderList->addOrder(o);
}

void Player::executeOrder() {
    orderList->executeOrder();
}

bool Player::hasOrder() {
    return orderList->hasOrder();
}


bool Player::ownsTerritory(Territory* t) {
    return t->getPlayerName() == playerName;
}

string Player::getName() {
    return playerName;
}

int Player::getArmyNum() {
    return armyNum;
}

void Player::addArmyNum(int number) {
    armyNum += number;
}

void Player::subtractArmyNum(int number) {
    armyNum -= number;
}

void Player::checkAggressive() {
    if (isNeutral) {
        isNeutral = false;
        delete ps;
        ps = new AggressivePlayerStrategy();
    }
}

Hand* Player::getHand() {
    return playerHand;
}