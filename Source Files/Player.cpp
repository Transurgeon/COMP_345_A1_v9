#include "../Header Files/Player.h"
#include <stack>


//Player constructor
Player::Player() {
    //player owns a hand
    playerHand = new Hand();
    playerTerritoryList = new vector<Territory*>;
    playerDefendList = new vector<Territory*>();
    playerAttackList = new vector<Territory*>();
    
    orderList = new Orderslist();
    playerId = 0;
    playerName;
    armyNum = 50;
}

//Player constructor (with name)
Player::Player(string name) {
    
    playerHand = new Hand();
    playerTerritoryList = new vector<Territory*>;
    playerDefendList = new vector<Territory*>();
    playerAttackList = new vector<Territory*>();
    
    orderList = new Orderslist();
    int playerId = 0;
    armyNum = 50;
    setPlayerName(name);
}

//Player destructor
Player::~Player()
{
    delete playerHand;
    for (int i = 0; i < playerTerritoryList->size(); i++) {
        delete playerTerritoryList->at(i);
    }
    delete playerTerritoryList;
    for (int i = 0; i < playerAttackList->size(); i++) {
        delete playerAttackList->at(i);
    }
    delete playerAttackList;
    for (int i = 0; i < playerDefendList->size(); i++) {
        delete playerDefendList->at(i);
    }
    delete playerDefendList;
    delete orderList;
}

Player::Player(
    const Player& player1) {
    this->playerHand = player1.playerHand;
    for (int i = 0; i < player1.playerTerritoryList->size(); i++) {
        this->playerTerritoryList->push_back(player1.playerTerritoryList->at(i));
    }

    for (int i = 0; i < player1.playerDefendList->size(); i++) {
        this->playerDefendList->push_back(player1.playerDefendList->at(i));
    }

    for (int i = 0; i < player1.playerAttackList->size(); i++) {
        this->playerAttackList->push_back(player1.playerAttackList->at(i));
    }

    for (int i = 0; i < player1.orderList->getOrderList()->size(); i++) {
        this->orderList->setOrderList(player1.orderList->getOrderList()->at(i));
    }

    this->playerId = player1.playerId;
}

Player& Player::operator=(const Player& player1) {
    this->playerHand = player1.playerHand;
    for (int i = 0; i < player1.playerTerritoryList->size(); i++) {
        this->playerTerritoryList->push_back(player1.playerTerritoryList->at(i));
    }

    for (int i = 0; i < player1.playerDefendList->size(); i++) {
        this->playerDefendList->push_back(player1.playerDefendList->at(i));
    }

    for (int i = 0; i < player1.playerAttackList->size(); i++) {
        this->playerAttackList->push_back(player1.playerAttackList->at(i));
    }

    for (int i = 0; i < player1.orderList->getOrderList()->size(); i++) {
        this->orderList->setOrderList(player1.orderList->getOrderList()->at(i));
    }


    this->playerId = player1.playerId;

    return *this;
}


//Player stream insertion
std::ostream& operator<<(ostream& os, const Player& player) {
    os << "Hi I am player :" << player.playerName << endl;
    return os;
}

void Player::attackTerritory(Territory* territory) {
    //validating if the territory already in the list
    if (std::count(playerAttackList->begin(), playerAttackList->end(), territory)) {
    }
    else {
        //add territory to the attack list
        playerAttackList->push_back(territory);
    }

}

void Player::defendTerritory(Territory* territory) {

    //validating if the territory already in the list
    if (std::count(playerDefendList->begin(), playerDefendList->end(), territory)) {
        std::cout << "Element already existed, cannot be added to the player " << playerName << "'s defend list: "
            << territory->getName() << endl;
    }
    else {
        //add territory to the defended list
        playerDefendList->push_back(territory);
        std::cout << "Element has been added to the player " << playerName << "'s defend list: "
            << territory->getName() << endl;
    }
}

void Player::addTerritory(Territory* territory) {

    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory)) {
    }
    else {
        //add territory to the list
        playerTerritoryList->push_back(territory);
    }
}

//add an assignment to remove territories
void Player::removeTerritory(Territory* territory) {
    //validating if the territory already in the list
    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory)) {
        //remove the territory from the list
        playerTerritoryList->erase(std::remove(playerTerritoryList->begin(), playerTerritoryList->end(), territory),
            playerTerritoryList->end());

        std::cout << "Element removed from the player " << playerName << "'s Territory list: "
            << territory->getName() << endl;

    }
    else {

        std::cout << "The player does not have such territory, so the remove from player " << playerName
            << "'s territory list failed: " << territory->getName() << endl;
    }


}

void Player::cancelAttack(Territory* territory) {
    if (std::count(playerAttackList->begin(), playerAttackList->end(), territory)) {

        playerAttackList->erase(std::remove(playerAttackList->begin(), playerAttackList->end(), territory),
            playerAttackList->end());

        std::cout << "Element removed from the player " << playerName << "'s Attacking list: "
            << territory->getName() << endl;

    }
    else {

        std::cout << "The player " << playerName
            << " didn't want to attack the following territory, so the remove failed: "
            << territory->getName() << endl;
    }


}

bool Player::containsTerritory(Territory* territory) {
    if (std::count(playerTerritoryList->begin(), playerTerritoryList->end(), territory)) {
        cout << "player " << playerName << " has " << territory->getName() << endl;
        return true;
    }
    else {
        cout << "player " << playerName << " does not have this territory" << endl;
        return false;
    }
}

bool Player::canAttack(Territory* territory) {
    for (int i = 0; i < playerAttackList->size(); i++) {
        if (playerAttackList->at(i)->getCountryNum() == territory->getCountryNum()) {
            return false;
        }

    }
    return true;
}

bool Player::alreadyOwn(Territory* territory) {
    for (int i = 0; i < playerTerritoryList->size(); i++) {
        if (playerTerritoryList->at(i)->getCountryNum() == territory->getCountryNum()) {
            return true;
        }

    }
    return false;
}

bool Player::containTerritoryByName(string territoryName, vector<Territory*>* territoryList) {
    for (int i = 0; i < territoryList->size(); i++) {
        if (territoryList->at(i)->getName().compare(territoryName)) {
            cout << "player " << playerName << " can attack this territory" << endl;
            return true;
        }
    }

    cout << "player " << playerName << " cannot attack this territory" << endl;
    return false;

}

void Player::cancelDefend(Territory* territory) {
    if (std::count(playerDefendList->begin(), playerDefendList->end(), territory)) {
        playerDefendList->erase(std::remove(playerDefendList->begin(), playerDefendList->end(), territory),
            playerDefendList->end());

        std::cout << "Element removed from the player " << playerName << "'s defending list: "
            << territory->getName() << endl;

    }
    else {

        std::cout << "The player " << playerName
            << " did not need to defend the following territory, so the remove failed: "
            << territory->getName() << endl;
    }


}

vector<Territory*>* Player::toAttack(Map* map) {

    return playerAttackList;

}

vector<Territory*>* Player::toDefend() {

    return playerTerritoryList;
}

void Player::displayTerritory(vector<Territory*>* territoryList) {

    std::cout << '\n' << "Player " << playerName << "'s Territory List:" << '\n' << endl;

    for (int i = 0; i < territoryList->size(); ++i) {
        cout << territoryList->at(i)->getName() << '\n' << endl;
    }

}

int Player::getHandLimit() {

    cout << '\n' << "Hand Limit for this player " << playerName << ": " << '\n' << endl;
    cout << playerHand->getHandLimit() << '\n' << endl;

    return playerHand->getHandLimit();

}

Territory* Player::getTerritoryByName(string name, vector<Territory*>* territoryList) {
    for (int i = 0; i < territoryList->size(); i++) {
        if (territoryList->at(i)->getName().compare(name)) {
            return territoryList->at(i);
        }
    }

}
void Player::issueOrders(Order* order) {
 
    orderList->setOrderList(order);

}

vector<Territory*>* Player::getTerritoryList() {

    return playerTerritoryList;
}

vector<Territory*> Player::getAttackList(Map* m) {

    vector<Territory*> attacklist;
    bool repeat;
    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == playerName) {
            for (int j = 0; j < m->getBorders()[i]->getEdges().size(); j++) {
                if (m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]->getPlayerName() != playerName) {
                    repeat = false;
                    for (int k = 0; k < attacklist.size(); k++) {
                        if (attacklist[k]->getCountryNum() == m->getBorders()[i]->getEdges()[j]) {
                            repeat = true;
                        }
                    }
                    if (!repeat) {
                        attacklist.push_back(m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]);
                    }
                }
            }
        }
    }

    return attacklist;
}

vector<Territory*> Player::getDefendList(Map* m) {

    vector<Territory*> defendlist;
    bool repeat;
    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == playerName) {
            for (int j = 0; j < m->getBorders()[i]->getEdges().size(); j++) {
                if (m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]->getPlayerName() != playerName) {
                    repeat = false;
                    for (int k = 0; k < defendlist.size(); k++) {
                        if (defendlist[k]->getCountryNum() == i+1) {
                            repeat = true;
                        }
                    }
                    if (!repeat) {
                        defendlist.push_back(m->getTerritories()[i]);
                    }
                }
            }
        }
    }

    return defendlist;
}

void Player::setPlayerId(int id) {
    playerId = id;

}

int Player::getPlayerId() {

    return playerId;
}

void Player::setPlayerName(string name) {
    playerName = name;

}

Orderslist* Player::getOrderList() {
    return orderList;
}
string Player::getPlayerName() {

    return playerName;
}

int Player::getArmyNum() {
    return armyNum;
}

int Player::addArmyNum(int number) {
    armyNum += number;
    return armyNum;
}

int Player::removeArmyNum(int number) {
    armyNum -= number;
    return armyNum;
}

void Player::switchTerritories(Territory* territory, Player* player1, Player* player2) {
    player1->removeTerritory(territory);
    player2->addTerritory(territory);

    cout << "the territory :" << territory->getName() << "has been removed from player " << player1->getPlayerName()
        << " and added to player " << player2->getPlayerName() << endl;
}

int Player::getPlayerNumOfTerritoriesInContinent(int id) {
    int numOfTerritories = 0;
    for (int index = 0; index < playerTerritoryList->size(); index++) {
        if (playerTerritoryList->at(index)->getContinentNum() == id) {
            numOfTerritories++;
        }
    }
    return numOfTerritories;

}


void Player::calculateBonus(Map* map) {
    cout << "Init" << endl;
    int continentNum = map->getLastContinentId();
    for (int i = 1; i <= continentNum; i++) {
        int x = this->getPlayerNumOfTerritoriesInContinent(i);
        int y = map->getNumOfTerritoriesInContinent(i);

        if (x == y) {
            armyNum += map->getArmyContinentBonus(i);
        }
    }

}

void Player::calculateArmy(Map* map) {
    armyNum += playerTerritoryList->size() / 3;
    this->calculateBonus(map);
    if (armyNum < 3) {
        armyNum = 3;
    }
}

bool Player::containsOrder(string orderType) {
    vector<Order*>* listOfOrders = orderList->getOrderList();
    auto iter = listOfOrders->begin();
    for (; iter != listOfOrders->end(); iter++) {
        if ((*iter)->getOrderType() == orderType) {
            cout << "the list contains the order" << endl;
            return true;
        }

    }
    return false;
}

Order* Player::getOrderbyType(string orderType) {
    vector<Order*>* listOfOrders = orderList->getOrderList();
    auto iter = listOfOrders->begin();
    for (; iter != listOfOrders->end(); iter++) {
        if ((*iter)->getOrderType() == orderType) {
            cout << "the list contains the order" << endl;
            return *iter;
        }
    }
    cout << "this player does not contain this order" << endl;
    return nullptr;
}