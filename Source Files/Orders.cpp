#include "../Header Files/Orders.h"
#include <iostream>
#include <vector>


using namespace std;

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
    if (valid) {
        cout << "this order is valid and ready to be executed\n" << endl;
        return true;
    }
    else
        return false;
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

Deploy::Deploy() {
    setID(0);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
};

Deploy::Deploy(Player* player, Territory* targetTerritory, unsigned int armies) : Order(player) {
    setID(0);
    this->player = player; this->targetTerritory = targetTerritory;
    this->armies = armies;
    cout << "The Order" << " " << getOrderType() << " has been placed" << " by the Player: " 
        << player->getPlayerId() << " We added  " <<armies << " number of armies to this territory: " 
    << targetTerritory->getName() << "\n" << endl;
}

Deploy::~Deploy() 
{

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

    if (player->containsTerritory(targetTerritory) && player->getArmyNum() > armies) {
        cout << "Deploy has been validated and will be good to execute\n" << endl;
        return true;
    }
    else {
        cout << "Deploy is invalid\n" << endl;
        return false;
    }
}

void Deploy::execute() {

    if (validate()) {
        targetTerritory->setArmy(targetTerritory->getArmy() + armies);
        cout << "Deploy is being executed: " << armies << " armies have been deployed to the territory called: " << targetTerritory->getName() << "\n" << endl;
        Notify(this); 
        return;
    }
        cout << "Deploy cannot be executed\n" << endl;
        deployExecute = "Deploy cannot be executed\n";
    Notify(this);
}

string Deploy::stringToLog() {
    return "Deploy Order Executing: " + deployExecute;
}

Advance::Advance() {
    setID(1);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Advance::Advance(Player* player, Player* targetPlayer, Territory* fromTerritory, Territory* toTerritory, unsigned int armies) : Order(player) {
    setID(1);
    this->targetPlayer = targetPlayer;
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    cout << "The Order Advance has been placed by the player called: " << player->getPlayerId() << " it transports "<< armies <<" number of armies "
        <<"from Territory called: " << fromTerritory->getName() << " to Territory called: " << toTerritory->getName() << "\n" << endl;
}

Advance::Advance(const Advance& copiedAd) {
    this->fromTerritory = copiedAd.fromTerritory;
    this->toTerritory = copiedAd.toTerritory;
    this->armies = copiedAd.armies;
}

Advance::~Advance() {
    delete this->fromTerritory;
    delete this->toTerritory;
}

Advance& Advance::operator = (const Advance& Adva) {
    Order::operator=(Adva);
    player = Adva.player;
    fromTerritory = Adva.fromTerritory;
    toTerritory = Adva.toTerritory;
    armies = Adva.armies;
    return *this;
}

bool Advance::validate() {
    if (player->containsTerritory(fromTerritory) && map->isAdjacentTerritory(fromTerritory, toTerritory) && fromTerritory->getArmy() >= armies) {
        cout << "Advance has been validated and will be good to execute.\n" << endl;
        return true;
    }
    else {
        cout << "Advance is invalid\n" << endl;
        return false;
    }

}

void Advance::execute() {

    if (validate()) {
        if (player->containsTerritory(fromTerritory) && player->containsTerritory(toTerritory))
        {
            fromTerritory->setArmy(fromTerritory->getArmy() - armies);
            toTerritory->setArmy(toTerritory->getArmy() + armies);
            cout << "Advance is executed: Advance " << armies << " armies from " << fromTerritory->getName() << " to " << toTerritory->getName() << "\n" << endl;
        }
        else {
            if (getAttackable()) {
                fromTerritory->setArmy(fromTerritory->getArmy() - armies);
                while (toTerritory->getArmy() > 0 && armies > 0) {

                    srand(time(NULL));
                    if (rand() % 10 < 6) {
                        toTerritory->setArmy(toTerritory->getArmy() - 1);
                        cout << "Advance is executed: There is one army on " << toTerritory->getName() << "has been killed.\n";
                        advanceExecute = "Advance is executed: There is one army on " + toTerritory->getName() + " as defender has been killed.\n";
                    }
                    else if (rand() % 10 < 7) {
                        armies--;
                        cout << "Advance is executed: There is one army from" + fromTerritory->getName() + " as attacker has been killed. \n";
                        advanceExecute = "Advance is executed: There is one army on " + fromTerritory->getName() + " as attacker has been killed. \n";
                    }
                    cout << "Now there is " << toTerritory->getArmy() << " armies left on the " << toTerritory->getName() << endl;
                }
                if (toTerritory->getArmy() == 0) {
                    toTerritory->setPlayer(player->getPlayerId());
                    player->addTerritory(toTerritory);
                    targetPlayer->removeTerritory(toTerritory);
                    toTerritory->setArmy(toTerritory->getArmy() + armies);
                    player->getHand()->addCard(card);
                    cout << "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card" << endl;
                    advanceExecute += "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card";
                }
            }
        }
        Notify(this);
        return;
    }
    cout << " advance cannot be executed\n" << endl;
    advanceExecute = " advance cannot be executed\n";
    Notify(this);
}

string Advance::stringToLog() {
    return "Advance Order Executing: " + advanceExecute;
}

Bomb::Bomb() {
    setID(2);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Bomb::Bomb(Player* player, Territory* targetTerritory) : Order(player) {
    setID(2);
    this->player = player;
    this->targetTerritory = targetTerritory;
    cout << "The order Bomb is been placed with issuer " << player->getPlayerId() << " targeting to the territory " << targetTerritory->getName() << "\n" << endl;

}

Bomb::Bomb(const Bomb& copiedBo) {
    this->targetTerritory = copiedBo.targetTerritory;
    this->player = copiedBo.player;
}


Bomb::~Bomb() {
    delete this->targetTerritory;
    delete this;
}

Bomb& Bomb::operator = (const Bomb& Bo) {
    Order::operator=(Bo);
    player = Bo.player;
    targetTerritory = Bo.targetTerritory;
    return *this;
}

bool Bomb::validate() {
    if (!player->containsTerritory(targetTerritory)) {
        cout << "Bomb has been validated and will be good to execute. \n" << endl;
        return true;
    }
    else
        cout << "the player cannot issue bomb order on own territories.\n" << endl;
    return false;

}

void Bomb::execute() {
    if (validate() && player->getHand()->getCardByType(bomb) && getAttackable()) {
        targetTerritory->setArmy(targetTerritory->getArmy() / 2);
        cout << "Bomb is executed: the armies on target Territory " << targetTerritory->getName() << " has been removed half by the issuer. \n" << endl;
        bombExecute = "Bomb is executed: the armies on target Territory " + targetTerritory->getName() + " has been removed half by the issuer. \n";
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

Blockade::Blockade() {
    setID(3);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Blockade::Blockade(Player* player, Territory* targetTerritory) : Order(player) {
    setID(3);
    this->targetTerritory = targetTerritory;
    this->player = player;
    cout << "The order Blockade is been placed with issuer " << player->getPlayerId() << " targeting to the territory "
        << targetTerritory->getName() << "\n" << endl;
}

Blockade::Blockade(const Blockade& copiedBl) {
    /*    this->type = *new string (copiedBl.type);*/
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
    if (player->containsTerritory(targetTerritory)) {
        cout << "Blockade has been validated and will be good to execute.\n" << endl;
        return true;
    }
    else
        cout << "this territory is not belongs to the order issuer, the blockade is invalid" << endl;
    return false;
}

void Blockade::execute() {
    if (validate() && player->getHand()->getCardByType(blockade)) {
        targetTerritory->setArmy(targetTerritory->getArmy() * 2);
        targetTerritory->neutralState();
        cout << "Blockade is executed: The army on territory " << targetTerritory->getName() 
            << " has been doubled ,and the ownership of this territory has been transferred to neutral.\n" << endl;
        blockadeExecute = "Blockade is executed: The army on territory " + targetTerritory->getName() + 
            " has been doubled ,and the ownership of this territory has been transferred to neutral.\n";
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

Airlift::Airlift() {
    setID(4);
    cout << "The order" << " " << getOrderType() << " is been placed" << endl;
}
Airlift::Airlift(Player* player, Territory* fromTerritory, Territory* toTerritory, unsigned int armies) : Order(player) {
    setID(4);
    this->fromTerritory = fromTerritory;
    this->toTerritory = toTerritory;
    this->armies = armies;
    cout << "The order Blockade is been placed with issuer " << player->getPlayerId() << " from territory " << fromTerritory->getName() 
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
    if (player->containsTerritory(fromTerritory) && player->containsTerritory(toTerritory) && fromTerritory->getArmy() > armies) {
        cout << "Airlift has been validated and will be good to execute\n" << endl;
        return true;
    }
    else
        cout << "The airlift order is invalid\n";
    return false;
}

void Airlift::execute() {
    
    if (validate() && player->getHand()->getCardByType(airlift)) {
        fromTerritory->setArmy(fromTerritory->getArmy() - armies);
        toTerritory->setArmy(toTerritory->getArmy() + armies);
        cout << "Airlift is executed: The player has moved " << armies << " armies from the source territory "
            << fromTerritory->getName() << " to the target territory " << toTerritory->getName() << "\n" << endl;
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

Negotiate::Negotiate() {
    setID(5);
    cout << "The order" << " " << getOrderType() << " has been placed to the OrderList\n" << endl;
}

Negotiate::Negotiate(Player* player, Player* targetPlayer) : Order(player) {
    setID(5);
    this->player = player;
    this->targetPlayer = targetPlayer;
    cout << "The order Negotiate is been placed by player " << player->getPlayerId() << " to target player " << targetPlayer->getPlayerId() << "\n" << endl;
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
    if (targetPlayer->getPlayerId() == player->getPlayerId()) {
        cout << "Target player cannot be the Negotiate Issuer\n" << endl;
        return false;
    }
    else {
        cout << "Negotiate has been validated and will be good to execute\n" << endl;
        return true;
    }
}

void Negotiate::execute() {
    if (validate() && player->getHand()->getCardByType(diplomacy)) {
        if (player->containsOrder("bomb") || player->containsOrder("advance")) {
            player->getOrderbyType("bomb")->setAttackable(false);
            player->getOrderbyType("advance")->setAttackable(false);
            cout << "Negotiate is executed: The Negotiate has been executed by player " << player->getPlayerId() << " targeting to player " << targetPlayer->getPlayerId() << ". No attack can be executed between them\n" << endl;
            negotiateExecute = "Negotiate is executed: The Negotiate has been executed by player " + player->getPlayerName() + " targeting to player " + targetPlayer->getPlayerName() + ". No attack can be executed between them\n";
        }
        else if (targetPlayer->containsOrder("bomb") || targetPlayer->containsOrder("advance")) {
            Order* targetBomb = targetPlayer->getOrderbyType("bomb");
            targetBomb->setAttackable(false);
            Order* targetAdvance = targetPlayer->getOrderbyType("advance");
            targetAdvance->setAttackable(false);
            cout << "Negotiate is executed: The Negotiate has been executed by player " << player->getPlayerId() << " targeting to player " << targetPlayer->getPlayerId() << ". No attack can be executed between them\n" << endl;
            negotiateExecute = "Negotiate is executed: The Negotiate has been executed by player " + player->getPlayerName() + " targeting to player " + targetPlayer->getPlayerName() + ". No attack can be executed between them\n";
        }
    }
    else {
        cout << "The Negotiate order cannot be executed\n" << endl;
        negotiateExecute = "The Negotiate order cannot be executed\n";
    }
    Notify(this);
}

string Negotiate::stringToLog() {
    return "Negotiate Order Executing: " + negotiateExecute;
}

Orderslist::Orderslist() = default;

Orderslist::~Orderslist() = default;

Orderslist::Orderslist(const Orderslist & copiedOl) {
    this->orderlist = *new vector<Order*>(copiedOl.orderlist);
}

Orderslist& Orderslist::operator = (const Orderslist & Ol) {
    return *this;
}

ostream& operator << (ostream & out, const Orderslist & o)
{
    return out;
}

istream& operator >> (istream & in, Orderslist & o)
{
    return in;
}

void Orderslist::setOrderList(Order * order) {
    orderlist.push_back(order);

    cout << "Adding a " + order->getOrderType() << " order to  " << order->player->getPlayerName() << "\n" << endl;
    observer_Order = "OrderList add order: " + order->player->getPlayerName() + " added " + order->getOrderType() + " to the list.\n";
    Notify(this);
}

vector<Order*>* Orderslist::getOrderList() {
    return &orderlist;
}

void Orderslist::remove(Order * order) {
    for (int i = 0; i < orderlist.size(); i++) {
        if (order->getOrderType() == orderlist.at(i)->getOrderType()) {
            orderlist.erase(orderlist.begin() + i);
            cout << "The order " << order->getOrderType() << " has been removed from the list" << endl;
            return;
        }
    }
}

void Orderslist::move(int origin, int targetPosition)
{
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

string Orderslist::stringToLog() {
    string toLog = "OrderList Calling stringToLog: Order to be added is of type: ";
    toLog.append(orderlist.back()->getOrderType());

    return toLog;
}
