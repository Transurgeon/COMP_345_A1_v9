#include "../Header Files/Orders.h"
#include <iostream>
#include <vector>


using namespace std;

/// <summary>
/// OrderList class, a class that saves orders into a list
/// </summary>

Orderslist::Orderslist(const Orderslist& cl) {
    this->orderlist = *new vector<Order*>(cl.orderlist);
}

Orderslist& Orderslist::operator = (const Orderslist& Ol) {
    return *this;
}

bool Orderslist::addOrder(Order* order) {
    if (order->validate()) {
        orderlist.push_back(order);
        return true;
    }
    return false;
}


void Orderslist::executeOrder() {
    orderlist[0]->execute();
    orderlist.erase(orderlist.begin());
}

bool Orderslist::hasOrder() {
    return orderlist.size() > 0;
}

void Orderslist::move(int origin, int targetPosition) {

    if (origin >= 0 && origin < orderlist.size() && targetPosition >= 0 && targetPosition < orderlist.size())
    {
        orderlist.insert(orderlist.begin() + targetPosition, orderlist.at(origin));
        orderlist.erase(orderlist.begin() + origin);
    }
    else if (targetPosition == orderlist.size())
    {
        orderlist.push_back(orderlist.at(origin));
        orderlist.erase(orderlist.begin() + origin);
    }
    else {
        cout << "\n Cannot move order to the desired position" << endl;
    }
}

void Orderslist::printOrderlist() {
    auto it = orderlist.begin();
    for (; it != orderlist.end(); it++)
    {
        cout << (*it)->getOrderType() << " " << endl;
    }
    cout << endl;

}
//string to log function for the orderlist
string Orderslist::stringToLog() {
    string toLog = "OrderList Calling stringToLog: Order to be added is of type: ";
    toLog.append(orderlist.back()->getOrderType());

    return toLog;
}

/// <summary>
/// Order class (Parent)
/// </summary>
Order::Order()
{
}

Order::Order(Player* player) {
    this->player = player;
}

Order::~Order() {
}

Order::Order(const Order& copiedO) {
    this->orders = *new vector<string>(copiedO.orders);
    this->id = *new int(copiedO.id);
    this->valid = *new bool(copiedO.valid);
}

Order& Order::operator = (const Order& O) {
    return *this;
};

ostream& operator << (ostream& out, const Order& o)
{
    out << "id: " << o.id;
    out << "validation: " << o.valid << endl;
    return out;
}

istream& operator >> (istream& in, Order& o)
{
    cout << "Enter id ";
    in >> o.id;
    cout << "Enter Imaginary Part ";
    in >> o.valid;
    return in;
}

bool Order::validate() {
    return valid;
}

void Order::execute() {
    if (validate()) {
        cout << "the order has been executed\n" << endl;
        return;
    }
    cout << "the order is invalid and cannot be executed\n" << endl;
}

void Order::setID(int i) {
    id = i;
}

string Order::getOrderType() {
    return orders.at(id);
}

const Player* Order::getOrderIssuer() {
    return player;
}

void Order::setOrderIssuer(Player* issuer) {
    player = issuer;
}
/// <summary>
/// Deploy Class
/// </summary>
Deploy::Deploy() {
    setID(0);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Deploy::Deploy(Player* player, Territory* targetTerritory, unsigned int armies) : Order(player) {
    setID(0);
    this->player = player; this->targetTerritory = targetTerritory;
    this->armies = armies;
}

Deploy::~Deploy() 
{
    targetTerritory = nullptr;
}

Deploy::Deploy(const Deploy& copiedDe) {
    this->player = copiedDe.player;
    this->targetTerritory = copiedDe.targetTerritory;
    this->armies = copiedDe.armies;
}

Deploy& Deploy::operator = (const Deploy& Deo) {
    Order::operator=(Deo);
    player = Deo.player;
    targetTerritory = Deo.targetTerritory;
    armies = Deo.armies;
    return *this;
}


bool Deploy::validate() {

    return player->ownsTerritory(targetTerritory) && player->getArmyNum() >= armies && armies > 0;
}

void Deploy::execute() {

    if (validate()) {
        targetTerritory->addArmy(armies);
        player->subtractArmyNum(armies);
        cout << armies << " troops have been deployed to " << targetTerritory->getName() << "\n" << endl;
        deployExecute = "Deploy was executed\n";
        return;
    }
    cout << "Deploy was not executed\n" << endl;
    deployExecute = "Deploy was not executed\n";
}

string Deploy::stringToLog() {
    return "";
}
/// <summary>
/// Advance
/// </summary>
Advance::Advance() {
}

Advance::Advance(Player* player, Territory* fromTerritory, Territory* toTerritory, Map* map, vector<Player*> playerList, unsigned int armies) : Order(player) {
    cheat = false;
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    pl = playerList;
    m = map;
}

Advance::Advance(Player* player, Territory* toTerritory, Map* map, vector<Player*> playerList) : Order(player) {
    cheat = true;
    this->toTerritory = toTerritory;
    pl = playerList;
    m = map;
}


bool Advance::validate() {
    if (cheat) {
        for (int i : m->getBorders()[toTerritory->getCountryNum() - 1]->getEdges())
            if (m->getTerritories()[i - 1]->getPlayerName() == "Cheater")
                return true;
        return false;
    }

    return player->ownsTerritory(fromTerritory) && fromTerritory->getCountryNum() != toTerritory->getCountryNum() && m->isAdjacentTerritory(fromTerritory, toTerritory) && armies <= fromTerritory->getArmy() && armies > 0;
    
}

void Advance::execute() {

    if (!validate()) {
        cout << "Advance was not executed\n" << endl;
        advanceExecute = " Advance was not executed\n";
        return;
    }


    advanceExecute = " Advance was executed\n";

    if (cheat) {
        for (Player* p : pl) {
            if (p->getName() == toTerritory->getPlayerName())
                p->checkAggressive();
        }
        toTerritory->setPlayer(player->getName());
        toTerritory->subtractArmy(toTerritory->getArmy());
        cout << "The cheater claims "<< toTerritory->getName() <<"\n";
        return;
    }

    if (player->ownsTerritory(toTerritory)) {

        fromTerritory->subtractArmy(armies);
        toTerritory->addArmy(armies);
        cout << armies << " troops were transfered from " << fromTerritory->getName() <<" to " << toTerritory->getName()<< "\n";
        return;
    }

    for (Player* p : pl) {
        if (p->getName() == toTerritory->getPlayerName())
            p->checkAggressive();
    }

    fromTerritory->subtractArmy(armies);

    while (toTerritory->getArmy() > 0 && armies > 0) {

        if (random(1, 10) <= 6)
            toTerritory->subtractArmy(1);

        if (random(1, 10) <= 7)
            armies--;
    }

    if (toTerritory->getArmy() == 0) {
        cout << player->getName() << " has captured " << toTerritory->getName() << " from " << toTerritory->getPlayerName() << " and placed " << armies << " troops\n";
        toTerritory->setPlayer(player->getName());
        toTerritory->addArmy(armies);
        return;
    } 

    cout << player->getName() << " failed to attack " << toTerritory->getName() << " from " << toTerritory->getPlayerName() << ", leaving it with " << toTerritory->getArmy() << " troops left\n";;
}

string Advance::stringToLog() {
    return "";
}

Advance::Advance(const Advance& copiedAd) {
    this->fromTerritory = copiedAd.fromTerritory;
    this->toTerritory = copiedAd.toTerritory;
    this->armies = copiedAd.armies;
}

Advance::~Advance() {
    fromTerritory = nullptr;
    toTerritory = nullptr;
    m = nullptr;
}

Advance& Advance::operator = (const Advance& Adva) {
    Order::operator=(Adva);
    player = Adva.player;
    fromTerritory = Adva.fromTerritory;
    toTerritory = Adva.toTerritory;
    armies = Adva.armies;
    return *this;
}
/// <summary>
/// Bomb class
/// </summary>
Bomb::Bomb() {
    setID(2);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Bomb::Bomb(Player* player, Territory* targetTerritory) : Order(player) {
    setID(2);
    this->player = player;
    this->targetTerritory = targetTerritory;
    cout << "The order Bomb is been placed with issuer " << player->getName() << 
        " targeting to the territory " << targetTerritory->getName() << "\n" << endl;

}

Bomb::Bomb(const Bomb& copiedBo) {
    this->targetTerritory = copiedBo.targetTerritory;
    this->player = copiedBo.player;
}


Bomb::~Bomb() {
    delete this->targetTerritory;
}

Bomb& Bomb::operator = (const Bomb& Bo) {
    Order::operator=(Bo);
    player = Bo.player;
    targetTerritory = Bo.targetTerritory;
    return *this;
}

bool Bomb::validate() {
    /*if (!player->containsTerritory(targetTerritory)) {
        cout << "Bomb has been validated and will be good to execute. \n" << endl;
        return true;
    }
    else
        cout << "the player cannot issue bomb order on own territories.\n" << endl;*/
    return false;

}

void Bomb::execute() {
   if (validate() && player->getHand()->getCardByType(bomb) && getAttackable()) {
        targetTerritory->subtractArmy(targetTerritory->getArmy() / 2);
        cout << "The armies on target Territory called: " << targetTerritory->getName() << " were cut in half by the issuer. \n" << endl;
        Notify(this);
        return;
    }
    cout << " Bomb cannot be executed \n" << endl;
    bombExecute = " Bomb cannot be executed \n";
    Notify(this);
}

string Bomb::stringToLog() {
    return "Bomb Order Executing: " + bombExecute;
}
/// <summary>
/// Blockade class 
/// </summary>
Blockade::Blockade() {
    setID(3);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Blockade::Blockade(Player* player, Territory* targetTerritory) : Order(player) {
    setID(3);
    this->targetTerritory = targetTerritory;
    this->player = player;
    cout << "The order Blockade has been placed by the player number: " << player->getName() << " to the territory called: "
        << targetTerritory->getName() << "\n" << endl;
}

Blockade::Blockade(const Blockade& copiedBl) {
    this->player = copiedBl.player;
    this->targetTerritory = copiedBl.targetTerritory;
}

Blockade::~Blockade() {
    delete this->targetTerritory;
    delete this;
}

Blockade& Blockade::operator = (const Blockade& Blo) {
    Order::operator=(Blo);
    player = Blo.player;
    targetTerritory = Blo.targetTerritory;
    return *this;
}

bool Blockade::validate() {
    /*if (player->containsTerritory(targetTerritory)) {
        cout << "Blockade has been validated and will be good to execute.\n" << endl;
        return true;
    }
    else
        cout << "this territory is not belongs to the order issuer, the blockade is invalid" << endl;*/
    return false;
}

void Blockade::execute() {
    if (validate() && player->getHand()->getCardByType(blockade)) {
        targetTerritory->addArmy(targetTerritory->getArmy());
        cout << "Blockade is executed: The army on territory " << targetTerritory->getName() 
            << " has been doubled ,and the ownership of this territory has been transferred to neutral.\n" << endl;
        Notify(this);
        return;
    }
    cout << "Blockade cannot be executed" << endl;
    blockadeExecute = "Blockade cannot be executed";
    Notify(this);
}

string Blockade::stringToLog() {
    return "Blockade Order Executing: " + blockadeExecute;
}
/// <summary>
/// AirLift class
/// </summary>
Airlift::Airlift() {
    setID(4);
    cout << "The order" << " " << getOrderType() << " is been placed" << endl;
}
Airlift::Airlift(Player* player, Territory* fromTerritory, Territory* toTerritory, unsigned int armies) : Order(player) {
    setID(4);
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    cout << "The order airlift has been placed with by the player " << player->getName() << " from territory " << fromTerritory->getName() 
        << " to territory " << toTerritory->getName() << "\n" << endl;

}

Airlift::Airlift(const Airlift& copiedAir) {
    this->fromTerritory = copiedAir.fromTerritory;
    this->toTerritory = copiedAir.toTerritory;
}

Airlift::~Airlift() {
    delete this->fromTerritory;
    delete this->toTerritory;
    delete this;
}

Airlift& Airlift::operator = (const Airlift& Airo) {
    Order::operator=(Airo);
    fromTerritory = Airo.fromTerritory;
    toTerritory = Airo.toTerritory;
    return *this;
}

bool Airlift::validate() {
    /*if (player->containsTerritory(fromTerritory) && player->containsTerritory(toTerritory) && fromTerritory->getArmy() > armies) {
        cout << "Airlift has been validated and will be good to execute\n" << endl;
        return true;
    }
    else
        cout << "The airlift order is invalid\n";*/
    return false;
}

void Airlift::execute() {
    
    if (validate() && player->getHand()->getCardByType(airlift)) {
        fromTerritory->subtractArmy(armies);
        toTerritory->addArmy(armies);
        cout << "Airlift is executed: The player has moved " << armies << " armies from the source territory called: "
            << fromTerritory->getName() << " to the target territory called: " << toTerritory->getName() << "\n" << endl;
        Notify(this);
        return;
    }
    cout << "No airlift card is creating or airlift order is invalid" << endl;
    airliftExecute = "No airlift card is creating or airlift order is invalid";
    Notify(this);
}

string Airlift::stringToLog() {
    return "Airlift Order Executing: " + airliftExecute;
}
/// <summary>
/// Negotiate class
/// </summary>
Negotiate::Negotiate() {
    setID(5);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Negotiate::Negotiate(Player* player, Player* targetPlayer) : Order(player) {
    setID(5);
    this->player = player;
    this->targetPlayer = targetPlayer;
    cout << "The order Negotiate is been placed by player " << player->getName() << " to target player " << targetPlayer->getName() << "\n" << endl;
}
Negotiate::~Negotiate() {
    delete this->player;
    delete this->targetPlayer;
    delete this;
}

Negotiate::Negotiate(const Negotiate& copiedNe) {
    this->player = copiedNe.player;
    this->targetPlayer = copiedNe.targetPlayer;
}

Negotiate& Negotiate::operator = (const Negotiate& Negot) {
    Order::operator=(Negot);
    player = Negot.player;
    targetPlayer = Negot.targetPlayer;
    return *this;
}

bool Negotiate::validate() {
    if (targetPlayer->getName() == player->getName()) {
        cout << "Target player cannot be the Negotiate Issuer\n" << endl;
        return false;
    }
    else {
        cout << "Negotiate has been validated and will be good to execute\n" << endl;
        return true;
    }
}

void Negotiate::execute() {
    //if (validate() && player->getHand()->getCardByType(diplomacy)) {
    //    if (player->containsOrder("bomb") || player->containsOrder("advance")) {
    //        player->getOrderbyType("bomb")->setAttackable(false);player->getOrderbyType("advance")->setAttackable(false);

    //        //outputting negotiate if our player has bomb or advance order
    //        cout << "Negotiate is executed: The Negotiate has been executed by player " << player->getName() << 
    //            " targeting to player " << targetPlayer->getName() << ". No attack can be executed between them\n" << endl;
    //    }


    //    else if (targetPlayer->containsOrder("bomb") || targetPlayer->containsOrder("advance")) {
    //        Order* targetBomb = targetPlayer->getOrderbyType("bomb"); targetBomb->setAttackable(false);
    //        Order* targetAdvance = targetPlayer->getOrderbyType("advance"); targetAdvance->setAttackable(false);

    //        //outputting negotiate if our player has bomb or advance order
    //        cout << "Negotiate is executed: The Negotiate has been executed by player " << player->getName() << 
    //            " targeting to player " << targetPlayer->getName() << ". No attack can be executed between them\n" << endl;
    //    }
    //}
    //else {
    //    cout << "The Negotiate order cannot be executed\n" << endl;
    //    negotiateExecute = "The Negotiate order cannot be executed\n";
    //}
    //Notify(this);
}

string Negotiate::stringToLog() {
    return "Negotiate Order Executing: " + negotiateExecute;
}

