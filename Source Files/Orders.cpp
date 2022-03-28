#include "../Header Files/Orders.h"
#include <iostream>
#include <vector>


using namespace std;
/// <summary>
/// Order
/// </summary>

//Constructors, Destructors and Operators
Order::Order() {
	this->orderNum = 0;
}
Order::Order(Player* player) {
	this->player = player;
}

Order::Order(const Order& copy) {
	this->Order_types = *new vector<string>();
	this->orderNum = *new int(copy.orderNum);
}

Order& Order::operator =(const Order& copy) {
	this->Order_types = *new vector<string>();
	this->orderNum = *new int(copy.orderNum);
	return *this;
}

//Getters and Setters
string Order::getType() {
	return Order_types.at(orderNum);
}

void Order::set_orderNum(int o) {
	orderNum = o;
}

Order::~Order() {
}

ostream& operator<<(ostream& output, Order& o) {

	return output << "The Order is of Type: " << o.getType();
}

//Executes the order
void Order::execute() {

	bool validated = Order::validate();

	if (validated == true)
		cout << "The order is valid, executing now!";
	else
		cout << "The order is not valid, pls double check your order!";
}

//Validates the order
bool Order::validate() {
	if (isValid) {
		cout << "Order is valid and ready to execute";
		return true;
	}
	else
	{
		return false;
	}
}

//Executes the order with a Map object parameter
void Order::execute2(Map* map) {
	bool validated = Order::validate2(map);

	if (validated == true)
		cout << "The order is valid, executing now!";
	else
		cout << "The order is not valid, pls double check your order!";
}
//Validates the order with a Map onject pointer parameter
bool Order::validate2(Map* map) {
	if (isValid) {
		cout << "Order is valid and ready to execute";
		return true;
	}
	else
	{
		return false;
	}
}
// To get who is the player issues the order
const Player* Order::getOrderIssuer() {
	return player;
}

// TO set who is the player issues the order
void Order::setOrderIssuer(Player* issuer) {
	player = issuer;
}

/// <summary>
/// OrdersList
/// </summary>

//Constructors, Destructors and Operators
OrdersList::OrdersList() {

}

OrdersList::OrdersList(vector<Order*> o) {
	this->OrderList = o;
}

OrdersList::OrdersList(const OrdersList& copy) {
	for (int i = 0; i < copy.OrderList.size(); i++)
	{

		if (copy.OrderList[i]->getType() == "DEPLOY")
		{
			this->OrderList.push_back(new Deploy());
		}
		else if (copy.OrderList[i]->getType() == "ADVANCE")
		{
			this->OrderList.push_back(new Advance());
		}
		else if (copy.OrderList[i]->getType() == "BOMB")
		{
			this->OrderList.push_back(new Bomb());
		}
		else if (copy.OrderList[i]->getType() == "BLOCKADE")
		{
			this->OrderList.push_back(new Blockade());
		}
		else if (copy.OrderList[i]->getType() == "AIRLIFT")
		{
			this->OrderList.push_back(new AirLift());
		}
		else if (copy.OrderList[i]->getType() == "NEGOTIATE")
		{
			this->OrderList.push_back(new Negotiate());
		}
	}
}

OrdersList& OrdersList::operator =(const OrdersList& copy) {
	OrderList = copy.OrderList;
	return *this;
}

vector<Order*> OrdersList::getOrderList() {
	return OrderList;
}

OrdersList::~OrdersList() {
	for (Order* order : OrderList)
	{
		delete order;
		order = nullptr;
	}
}

ostream& operator<<(ostream& output, OrdersList& ol) {

	for (int i = 0; i < ol.getOrderList().size(); i++)
	{
		output << "Order Number " << i + 1 << " is of type : " << ol.getOrderList().at(i)->getType() << endl;
	}

	return output;
}

//add, move and remove orders in the list
void OrdersList::add(Order* order) {
	OrderList.push_back(order);
}

void OrdersList::move(int currentPos, int newPos) {
	Order* temp = OrderList[currentPos];
	OrderList.erase(OrderList.begin() + (currentPos));
	OrderList.insert(OrderList.begin() + newPos, temp);
}

void OrdersList::remove(int pos) {

	int i = 0;
	for (Order* order : OrderList)
	{
		if (i == pos)
		{
			delete order;
			order = nullptr;
		}
		i++;
	}
	OrderList.erase(OrderList.begin() + pos);
}

/// <summary>
/// Deploy
/// </summary>

Deploy::Deploy(Player* p1, Territory* t1, int troopNum) {
	set_orderNum(0);
	this->p1 = p1;
	this->targetTerritory = t1;
	this->troopNum = troopNum;
}
//Constructors, Destructors and Operators
Deploy::Deploy() {
	set_orderNum(0);
	cout << "Deploy has been added" << endl;
}

Deploy::Deploy(const Deploy& deploy) {
	//this->type = deploy.type;
	this->p1 = deploy.p1;
	this->targetTerritory = deploy.targetTerritory;
	this->troopNum = deploy.troopNum;
}

Deploy& Deploy::operator=(const Deploy& deploy) {
	Order::operator=(deploy);
	player = deploy.player;
	targetTerritory = deploy.targetTerritory;
	troopNum = deploy.troopNum;
	return *this;
}

ostream& operator<<(std::ostream& output, Deploy& deploy) {
	output << "The Order is Deploy" << endl;
	return output;
}

//string* deploy::gettype() {
//	return &type;
//}

Deploy::~Deploy() {

}

//Validates the order
bool Deploy::validate() {
	if (player->containsTerritory(targetTerritory) && player->getArmyNum() > troopNum) {
		cout << "Deploy is valid and can be executed\n" << endl;
		return true;
	}
	else {
		cout << "Deploy is invalid\n" << endl;
		return false;
	}
}
bool Deploy::validate2(Map* map) {
	if (player->containsTerritory(targetTerritory) && player->getArmyNum() > troopNum) {
		cout << "Deploy is valid and can be executed\n" << endl;
		return true;
	}
	else {
		cout << "Deploy is invalid\n" << endl;
		return false;
	}
}

//Executes the order
void Deploy::execute() {
	if (validate()) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() + troopNum);
		cout << "Deploy is executed: " << troopNum << " armies has been deployed to the territory " << targetTerritory->getName() << "\n" << endl;
		auto armyNumber = std::to_string(troopNum);
		deployExecute = "Deploy is executed: " + armyNumber + " armies has been deployed to the territory " + targetTerritory->getName() + "\n";
	}
	else {
		cout << "deploy cannot be executed\n" << endl;
		deployExecute = "deploy cannot be executed\n";
	}
	Notify(this);
}
void Deploy::execute2(Map* map) {
	if (validate()) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() + troopNum);
		cout << "Deploy is executed: " << troopNum << " armies has been deployed to the territory " << targetTerritory->getName() << "\n" << endl;
		auto armyNumber = std::to_string(armies);
		deployExecute = "Deploy is executed: " + armyNumber + " armies has been deployed to the territory " + targetTerritory->getName() + "\n";
	}
	else {
		cout << "deploy cannot be executed\n" << endl;
		deployExecute = "deploy cannot be executed\n";
	}
	Notify(this);
}
string Deploy::stringToLog() {
	return deployExecute;
}

/// <summary>
/// Advance
/// </summary>

Advance::Advance(Player* p1,Player* p2, Territory* t1, Territory* targetTerritory, int troopNum) :Order(player) {
	this->p1 = p1;
	this->p2 = p2;
	this->t1 = t1;
	this->targetTerritory = targetTerritory;
	this->troopNum = troopNum;
	cout << "The order advance is been placed with issuer " << player->getPlayerId() << " from Territory " << t1->getName() << " to Territory " << targetTerritory->getName() << "with number of armies " << troopNum << "\n" << endl;
}
//Constructors, Destructors and Operators
Advance::Advance() :Order() {
	set_orderNum(1);
	cout << "Advance has been added" << endl;
}

//Advance::Advance(const Advance& Advance) {
//	this->type = *new string(Advance.type);
//}

Advance& Advance::operator=(const Advance& Advance) {
	Order::operator=(Advance);
	player = Advance.player;
	t1 = Advance.t1;
	targetTerritory = Advance.targetTerritory;
	troopNum = Advance.troopNum;
	return *this;
}

ostream& operator<<(std::ostream& output, Advance& Advance) {
	output << "The Order is Advance" << endl;
	return output;
}

//string* Advance::getType() {
//	return &type;
//}

Advance::~Advance() {
	delete this->t1;
	delete this->targetTerritory;
	delete this;
}

//Validates the order
bool Advance::validate() {
	if (player->containsTerritory(t1) && map->isAdjacentTerritory(t1, targetTerritory) && t1->getNumArmies() >= troopNum) {
		cout << "Advance is valid and can be executed.\n" << endl;
		return true;
	}// &&map->isAdjacentTerritory(fromTerritory, toTerritory)
	else {
		cout << "advance is invalid\n" << endl;
		return false;
	}
}
bool Advance::validate2(Map* map) {
	if (player->containsTerritory(t1) && map->isAdjacentTerritory(t1, targetTerritory) && t1->getNumArmies() >= troopNum) {
		cout << "Advance is valid and can be executed.\n" << endl;
		return true;
	}// &&map->isAdjacentTerritory(fromTerritory, toTerritory)
	else {
		cout << "advance is invalid\n" << endl;
		return false;
	}

}

//Executes the order
void Advance::execute() {
	auto armyNumber = std::to_string(troopNum);

	if (validate()) {
		if (player->containsTerritory(t1) && player->containsTerritory(targetTerritory))
		{

			t1->setNumArmies(t1->getNumArmies() - troopNum);
			targetTerritory->setNumArmies(targetTerritory->getNumArmies() + troopNum);
			cout << "Advance is executed: Advance " << troopNum << " armies from " << t1->getName() << " to " << targetTerritory->getName() << "\n" << endl;
		}
		else {
			if (getAttackable()) {
				t1->setNumArmies(t1->getNumArmies() - troopNum);
				while (targetTerritory->getNumArmies() > 0 && troopNum > 0) {

					srand(time(NULL));
					if (rand() % 10 < 6) {// Each attacking army unit involved has 60% chances of killing one defending army
						targetTerritory->setNumArmies(targetTerritory->getNumArmies() - 1);
						cout << "Advance is executed: There is one army on " << targetTerritory->getName() << "has been killed.\n";
						advanceExecute = "Advance is executed: There is one army on " + targetTerritory->getName() + " as defender has been killed.\n";
					}
					else if (rand() % 10 < 7) {//each defending army unit has 70% chances of killing one attacking army unit.
						troopNum--;
						cout << "Advance is executed: There is one army from" + t1->getName() + " as attacker has been killed. \n";
						advanceExecute = "Advance is executed: There is one army on " + t1->getName() + " as attacker has been killed. \n";
					}
					auto armyOnTarget = std::to_string(targetTerritory->getNumArmies());
					cout << "Now there is " << targetTerritory->getNumArmies() << " armies left on the " << targetTerritory->getName() << endl;
					advanceExecute = "Now there is " + armyOnTarget + " armies left on the " + targetTerritory->getName() + "\n.";
				}
				if (targetTerritory->getNumArmies() == 0) {
					targetTerritory->setPlayer(player->getPlayerId());
					player->addTerritory(targetTerritory);
					p2->removeTerritory(targetTerritory);
					//                    switch territory from 2 players
					//                    targetPlayer->switchTerritories(toTerritory,targetPlayer,player);
					targetTerritory->setNumArmies(targetTerritory->getNumArmies() + troopNum);
					player->getHand()->addCard(card);
					cout << "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card" << endl;
					advanceExecute += "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card";
				}

			}
		}
	}
	else {
		cout << " advance cannot be executed\n" << endl;
		advanceExecute = " advance cannot be executed\n";
	}
	Notify(this);
}
void Advance::execute2(Map* map) {
	auto armyNumber = std::to_string(armies);

	if (validate2(map)) {
		if (player->containsTerritory(fromTerritory) && player->containsTerritory(toTerritory))
		{

			fromTerritory->setNumArmies(fromTerritory->getNumArmies() - armies);
			toTerritory->setNumArmies(toTerritory->getNumArmies() + armies);
			cout << "Advance is executed: Advance " << armies << " armies from " << fromTerritory->getName() << " to " << toTerritory->getName() << "\n" << endl;
			//  advanceExecute = "Advance is executed: Advance "+armyNumber+" armies from "+fromTerritory->getName()+" to "+toTerritory->getName()+"\n";
		}
		else {
			if (getAttackable()) {
				fromTerritory->setNumArmies(fromTerritory->getNumArmies() - armies);
				while (toTerritory->getNumArmies() > 0 && armies > 0) {

					srand(time(NULL));
					int randAtk = rand() % 10;
					int randDef = rand() % 10;
					if (randAtk <= 6 && randDef <= 7) {
						//both die both army --
						toTerritory->setNumArmies(toTerritory->getNumArmies() - 1);
						armies--;
						cout << "Advance is executed:Both sides lost one army each .\n";
						advanceExecute = "Advance is executed:Both sides lost one army each .\n";
					}
					else if (randAtk <= 6 && randDef > 7) {
						//def army --
						toTerritory->setNumArmies(toTerritory->getNumArmies() - 1);
						cout << "Advance is executed: There is one army on " << toTerritory->getName() << "has been killed.\n";
						advanceExecute = "Advance is executed: There is one army on " + toTerritory->getName() + " as defender has been killed.\n";
					}
					else if (randAtk > 6 && randDef <= 7) {
						//akt army --
						armies--;
						cout << "Advance is executed: There is one army from" + fromTerritory->getName() + " as attacker has been killed. \n";
						advanceExecute = "Advance is executed: There is one army on " + fromTerritory->getName() + " as attacker has been killed. \n";
					}
					else {
						//nothing happend continue;
						cout << "There is nothing happened through advance order. \n" << endl;
					};
					/* if(rand() % 10 < 6){// Each attacking army unit involved has 60% chances of killing one defending army
						 toTerritory->setNumArmies(toTerritory->getNumArmies()-1);
						 cout<<"Advance is executed: There is one army on "<<toTerritory->getName()<<"has been killed.\n" ;
						  advanceExecute = "Advance is executed: There is one army on "+toTerritory->getName()+" as defender has been killed.\n" ;
					 }
					 if(rand() % 10 < 7){//each defending army unit has 70% chances of killing one attacking army unit.
						 armies--;
						 cout<<"Advance is executed: There is one army from"+fromTerritory->getName()+" as attacker has been killed. \n";
						 advanceExecute = "Advance is executed: There is one army on "+fromTerritory->getName()+" as attacker has been killed. \n";
					 }*/
					auto armyOnTarget = std::to_string(toTerritory->getNumArmies());
					cout << "Now there is " << toTerritory->getNumArmies() << " armies left on the " << toTerritory->getName() << endl;
					// advanceExecute = "Now there is " +armyOnTarget+" armies left on the "+toTerritory->getName()+"\n.";
				}
				if (toTerritory->getNumArmies() == 0) {
					toTerritory->setPlayer(player->getPlayerId());
					//                    player->addTerritory(toTerritory);
					targetPlayer->switchTerritories(toTerritory, targetPlayer, player);
					toTerritory->setNumArmies(toTerritory->getNumArmies() + armies);
					player->getHand()->addCard(card);
					cout << "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card" << endl;
					advanceExecute += "The target territory now is belongs to player" + player->getPlayerName() + " and gets a random card";
				}

			}
		}
	}
	else {
		cout << " advance cannot be executed\n" << endl;
		advanceExecute = " advance cannot be executed\n";
	}
	Notify(this);
}

string Advance::stringToLog() {
	return advanceExecute;
}


/// <summary>
/// Bomb
/// </summary>

Bomb::Bomb(Player* p1, Territory* targetTerritory) :Order(player) {
	this->player = p1;
	this->targetTerritory = targetTerritory;
	cout << "The order Bomb is been placed with issuer " << p1->getPlayerId() << " targeting to the territory " << targetTerritory->getName() << "\n" << endl;

}
//Constructors, Destructors and Operators
Bomb::Bomb() {
	set_orderNum(2);
	cout << "Bomb has been added" << endl;
}

Bomb::Bomb(const Bomb& Bomb) {
	this->targetTerritory = Bomb.targetTerritory;
	this->player = Bomb.player;
}

Bomb& Bomb::operator=(const Bomb& Bomb) {
	Order::operator=(Bomb);
	player = Bomb.player;
	targetTerritory = Bomb.targetTerritory;
	return *this;
}

ostream& operator<<(std::ostream& output, Bomb& Bomb) {
	output << "The Order is Bomb" << endl;
	return output;
}

//string* Bomb::getType() {
//	return &type;
//}

Bomb::~Bomb() {
	delete this->targetTerritory;
	delete this;
}

//Validates the order
bool Bomb::validate() {
	if (!player->containsTerritory(targetTerritory)) {
		cout << "Bomb is valid and can be executed. \n" << endl;
		return true;
	}
	else
		cout << "the player cannot issue bomb order on own territories.\n" << endl;
	return false;
}
bool Bomb::validate2(Map* map) {
	if (!player->containsTerritory(targetTerritory)) {
		cout << "Bomb is valid and can be executed. \n" << endl;
		return true;
	}
	else
		cout << "the player cannot issue bomb order on own territories.\n" << endl;
	return false;

}

//Executes the order
void Bomb::execute() {
	if (validate() && player->getHand()->getCardByType(bomb) && getAttackable()) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() / 2);
		cout << "Bomb is executed: the armies on target Territory " << targetTerritory->getName() << " has been removed half by the issuer. \n" << endl;
		bombExecute = "Bomb is executed: the armies on target Territory " + targetTerritory->getName() + " has been removed half by the issuer. \n";
	}
	else {
		cout << " Bomb cannot be executed \n" << endl;
		bombExecute = " Bomb cannot be executed \n";
	}

	Notify(this);
}
void Bomb::execute2(Map* map) {
	if (validate2(map) && player->getHand()->getCardByType(bomb) && getAttackable()) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() / 2);
		cout << "Bomb is executed: the armies on target Territory " << targetTerritory->getName() << " has been removed half by the issuer. \n" << endl;
		bombExecute = "Bomb is executed: the armies on target Territory " + targetTerritory->getName() + " has been removed half by the issuer. \n";
	}
	else {
		cout << " Bomb cannot be executed \n" << endl;
		bombExecute = " Bomb cannot be executed \n";
	}

	Notify(this);
}

string Bomb::stringToLog() {
	return bombExecute;
}
/// <summary>
/// Blockade
/// </summary>

Blockade::Blockade(Player* player, Territory* targetTerritory) : Order(player) {
	this->targetTerritory = targetTerritory;
	this->player = player;
	cout << "The order Blockade is been placed with issuer " << player->getPlayerId() << " targeting to the territory " << targetTerritory->getName() << "\n" << endl;
}
//Constructors, Destructors and Operators
Blockade::Blockade() {
	set_orderNum(3);
	cout << "Blockade has been added" << endl;
}

Blockade::Blockade(const Blockade& Blockade) {
	this->player = Blockade.player;
	this->targetTerritory = Blockade.targetTerritory;
}

Blockade& Blockade::operator=(const Blockade& Blockade) {
	Order::operator=(Blockade);
	player = Blockade.player;
	targetTerritory = Blockade.targetTerritory;
	return *this;
};

//string* Blockade::getType() {
//	return &type;
//}

Blockade::~Blockade() {
	delete this->targetTerritory;
	delete this;
}

//Validates the order
bool Blockade::validate() {
	if (player->containsTerritory(targetTerritory)) {
		cout << "blockade is valid and can be executed.\n" << endl;
		return true;
	}
	else
		cout << "this territory is not belongs to the order issuer, the blockade is invalid" << endl;
	return false;
}

bool Blockade::validate2(Map* map) {
	if (player->containsTerritory(targetTerritory)) {
		cout << "blockade is valid and can be executed.\n" << endl;
		return true;
	}
	else
		cout << "this territory is not belongs to the order issuer, the blockade is invalid" << endl;
	return false;
}

//Executes the order
void Blockade::execute() {
	if (validate() && player->getHand()->getCardByType(blockade)) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() * 2);
		targetTerritory->neutralState();
		cout << "Blockade is executed: The army on territory " << targetTerritory->getName() << " has been doubled ,and the ownership of this territory has been transferred to neutral.\n" << endl;
		blockadeExecute = "Blockade is executed: The army on territory " + targetTerritory->getName() + " has been doubled ,and the ownership of this territory has been transferred to neutral.\n";
	}
	else {
		cout << "Blockade cannot be executed" << endl;
		blockadeExecute = "Blockade cannot be executed";
	}

	Notify(this);
}
//If the target territory belongs to the player issuing the order,
// the number of armies on the territory is doubled and the ownership of the territory is transferred to the Neutral player,
// which must be created if it does not already exist.
void Blockade::execute2(Map* map) {
	if (validate2(map) && player->getHand()->getCardByType(blockade)) {
		targetTerritory->setNumArmies(targetTerritory->getNumArmies() * 2);
		targetTerritory->neutralState();
		cout << "Blockade is executed: The army on territory " << targetTerritory->getName() << " has been doubled ,and the ownership of this territory has been transferred to neutral.\n" << endl;
		blockadeExecute = "Blockade is executed: The army on territory " + targetTerritory->getName() + " has been doubled ,and the ownership of this territory has been transferred to neutral.\n";
	}
	else {
		cout << "Blockade cannot be executed" << endl;
		blockadeExecute = "Blockade cannot be executed";
	}

	Notify(this);
}


string Blockade::stringToLog() {
	return blockadeExecute;
}

/// <summary>
/// AirLift
/// </summary>

AirLift(Player* p1, Territory* t1, Territory* t2, int troopNum) {
	this->t1 = t1;
	this->t2 = t2;
	this->troopNum = troopNum;
	cout << "The order Blockade is been placed with issuer " << player->getPlayerId() << " from territory " << t1->getName() << " to territory " << t2->getName() << "\n" << endl;

}
//Constructors, Destructors and Operators
AirLift::AirLift() {
	set_orderNum(4);
	cout << "AirLift has been added" << endl;
}

AirLift::AirLift(const AirLift& AirLift) {
	this->t1 = AirLift.t1;
	this->t2 = AirLift.t2;
}

AirLift& AirLift::operator=(const AirLift& AirLift) {
	Order::operator=(AirLift);
	t1 = AirLift.t1;
	t2 = AirLift.t2;
	return *this;
}

//string* AirLift::getType() {
//	return &type;
//}

AirLift::~AirLift() {
	delete this->t1;
	delete this->t2;
	delete this;
}

bool AirLift::validate() {
	if (player->containsTerritory(t1) && player->containsTerritory(t2) && t1->getNumArmies() > armies) {
		cout << "airlift is valid and can be executed\n" << endl;
		return true;
	}
	else
		cout << "The airlift order is invalid\n";
	return false;
}

//• The target territory does not need to be adjacent to the source territory.
//• If the source or target does not belong to the player that issued the order, the order is invalid.
bool Airlift::validate2(Map* map) {
	if (player->containsTerritory(t1) && player->containsTerritory(t2) && t1->getNumArmies() > armies) {
		cout << "airlift is valid and can be executed\n" << endl;
		return true;
	}
	else
		cout << "The airlift order is invalid\n";
	return false;
}

void Airlift::execute() {
	if (validate() && player->getHand()->getCardByType(airlift)) {
		auto armyNumber = std::to_string(troopNum);
		fromTerritory->setNumArmies(fromTerritory->getNumArmies() - troopNum);
		t2->setNumArmies(t2->getNumArmies() + armies);
		cout << "Airlift is executed: The player has moved " << armies << " armies from the source territory " << fromTerritory->getName() << " to the target territory " << toTerritory->getName() << "\n" << endl;
		airliftExecute = "Airlift is executed: The player has moved " + armyNumber + " armies from the source territory " + fromTerritory->getName() + " to the target territory " + toTerritory->getName() + "\n";
	}
	else {
		cout << "No airlift card is creating or airlift order is invalid" << endl;
		airliftExecute = "No airlift card is creating or airlift order is invalid";
	}

	Notify(this);
}
//If both the source and target territories belong to the player that issue the airlift order,
// then the selected number of armies is moved from the source to the target territory.
void Airlift::execute2(Map* map) {
	if (validate2(map) && player->getHand()->getCardByType(airlift)) {
		auto armyNumber = std::to_string(armies);
		fromTerritory->setNumArmies(fromTerritory->getNumArmies() - armies);
		toTerritory->setNumArmies(toTerritory->getNumArmies() + armies);
		cout << "Airlift is executed: The player has moved " << armies << " armies from the source territory " << fromTerritory->getName() << " to the target territory " << toTerritory->getName() << "\n" << endl;
		airliftExecute = "Airlift is executed: The player has moved " + armyNumber + " armies from the source territory " + fromTerritory->getName() + " to the target territory " + toTerritory->getName() + "\n";
	}
	else {
		cout << "No airlift card is creating or airlift order is invalid" << endl;
		airliftExecute = "No airlift card is creating or airlift order is invalid";
	}

	Notify(this);
}

string Airlift::stringToLog() {
	return airliftExecute;
}

/// <summary>
/// Negotiate
/// </summary>

Negotiate::Negotiate(Player* p1, Player* p2) {

}
//Constructors, Destructors and Operators
Negotiate::Negotiate() {
	set_orderNum(5);
	cout << "Negotiate has been added" << endl;
}

Negotiate::Negotiate(const Negotiate& Negotiate) {
	this->type = *new string(Negotiate.type);
}

Negotiate& Negotiate::operator=(const Negotiate& Negotiate) {
	this->type = *new string(Negotiate.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Negotiate& Negotiate) {
	output << "The Order is Negotiate" << endl;
	return output;
}

string* Negotiate::getType() {
	return &type;
}

Negotiate::~Negotiate() {

}

//Validates the order
bool Negotiate::validate() {
	return true;
}

//Executes the order
void Negotiate::execute() {
	if (validate())
	{
		cout << "Order is Valid: Executing Negotiate Order" << endl;
	}

	else
	{
		cout << "Order is Invalid: Invalid Negotiate Order" << endl;
	}
}
