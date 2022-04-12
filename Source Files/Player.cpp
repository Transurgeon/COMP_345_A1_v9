#include "../Header Files/Player.h"
#include <stack>


//Player constructor
Player::Player() {
    //player owns a hand
    playerHand = new Hand();
    orderList = new Orderslist();
    playerName = "";
    armyNum = 50;
    aliveStatus = true;
}

//Player constructor (with name)
Player::Player(string name) {
    playerHand = new Hand();
    orderList = new Orderslist();
    playerName = name;
    armyNum = 50;
    aliveStatus = true;
}

//Player destructor
Player::~Player()
{
    delete playerHand;
    delete orderList;
}

Player::Player(const Player& player1) {
    
}

Player& Player::operator=(const Player& player1) {
    return *this;
}

vector<Territory*> Player::toAttack(Map* m) {

    for (int i = 0; i < attackList.size(); i++) {
        attackList.pop_back();
    }

    bool repeat;
    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == playerName) {
            for (int j = 0; j < m->getBorders()[i]->getEdges().size(); j++) {
                if (m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]->getPlayerName() != playerName) {
                    repeat = false;
                    for (int k = 0; k < attackList.size(); k++) {
                        if (attackList[k]->getCountryNum() == m->getBorders()[i]->getEdges()[j]) {
                            repeat = true;
                        }
                    }
                    if (!repeat) {
                        attackList.push_back(m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]);
                    }
                }
            }
        }
    }

    return attackList;
}

vector<Territory*> Player::toDefend(Map* m) {

    for (int i = 0; i < defendList.size(); i++) {
        defendList.pop_back();
    }

    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == playerName) {
            defendList.push_back(m->getTerritories()[i]);
        }
    }

    return defendList;
}

void Player::displayTerritories(vector<Territory*> territoryList) {

    for (int i = 0; i < territoryList.size(); ++i) {
        cout << territoryList[i]->getName() << '\n' << endl;
    }
}

void Player::issueOrder(Map* m) {

}

Orderslist* Player::getOrderList() {
    return orderList;
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

Hand* Player::getHand() {
    return playerHand;
}