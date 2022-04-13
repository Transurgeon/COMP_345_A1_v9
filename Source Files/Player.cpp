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
    aliveStatus = true;
}

//Player constructor (with name)
Player::Player(string name) {
    playerHand = new Hand();
    orderList = new Orderslist();
    armyNum = 50;
    aliveStatus = true;
    playerName = name;

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


vector<Territory*> Player::getAttackList() {
    return attackList;
}
vector<Territory*> Player::getDefendList() {
    return defendList;
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

void Player::killPlayer() {
    aliveStatus = false;
}

bool Player::isAlive() {
    return aliveStatus;
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