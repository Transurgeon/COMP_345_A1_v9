#include "../Header Files/Player.h"
#include <vector>
#include <stack>

Player::Player() { //Default Constructor.
	territoriesNum = vector<Territory*>();
	DefList = vector<Territory*>();
	AtkList = vector<Territory*>();
	playerCards = new Hand();
	playerOrders = new OrdersList();
}

Player::Player(vector<Territory*> t, Hand* h, OrdersList* o) { //Paramatrized Constructor.
	territoriesNum = t;
	playerCards = h;
	playerOrders = o;
}

Player::Player(const Player& copy) { //Copy Constructor.
	territoriesNum = copy.territoriesNum;
	DefList = copy.DefList;
	AtkList = copy.AtkList;
	playerCards = new Hand(*copy.playerCards); //By adding new this allows a deep copy of the player Cards.
	playerOrders = new OrdersList(*copy.playerOrders); //By adding new this allows a deep copy of player orders.
}

Player& Player::operator =(const Player& copy) { //Operator method for player.
	territoriesNum = copy.territoriesNum;
	DefList = copy.DefList;
	AtkList = copy.AtkList;
	playerCards = new Hand(*copy.playerCards);
	playerOrders = new OrdersList(*copy.playerOrders);
	return *this;
}

vector<Territory*> Player::toDefend() { //To defend method shows the list of territories the player has and must defend from opponent.
	cout << '\n' << "Here is the list of territories the player needs to defend: " << '\n' << endl;
	for (int i = 0; i < DefList.size(); ++i) {
		cout << DefList.at(i)->getName() << endl;
	}
	return DefList;
}

vector<Territory*> Player::toAttack() { //To attack method displays the list of territories the players need to attack.
	cout << '\n' << "Here is the list of territories the player needs to attack: " << '\n' << endl;
	for (int i = 0; i < AtkList.size(); ++i) {
		cout << AtkList.at(i)->getName() << endl;
	}
	return AtkList;
}

vector<Territory*> Player::showTerritories() { //This method outputs a list of territories each player owns.
	cout << '\n' << "This is the list of territories that the player owns: " << '\n' << endl;
	for (int i = 0; i < territoriesNum.size(); ++i) {
		cout << territoriesNum.at(i)->getName() << endl;
	}
	return territoriesNum;
}

void Player::attack(Territory* a) { //A method that adds a territory to the end of ATK list.
	AtkList.push_back(a);
}

void Player::defend(Territory* d) { //A method that adds a territory to the end of Def List.
	DefList.push_back(d);
}

void Player::add(Territory* t) { //A method that adds a territory to the number of territories you have.
	territoriesNum.push_back(t);
}

vector<Territory*> Player::getTerritoriesNum() { //Accessor for territoriesNum.
	return territoriesNum;
}
Hand* Player::getPlayerCards() {//Accessor for playerCards
	return playerCards;
}
OrdersList* Player::getPlayerOrders() { //Accessor for playerOrders.
	cout << endl;
	cout << "Showing player's orders list" << endl;
	cout << endl;
	cout << *playerOrders << endl;
	return playerOrders;
}

void Player::issueOrder(Order* order) { //Adds an order pointer to playerOrders OrdersList. Uses class OrdersList method add.
	playerOrders->add(order);
}

Player::~Player() { //Destructor for player and its pointers. Deletes all vectors, pointers, and object pointers.
	
	for (int i = 0; i < territoriesNum.size(); i++) {
		delete territoriesNum.at(i);
		territoriesNum.at(i) = NULL;
	}
	for (int i = 0; i < AtkList.size(); i++) {
		delete AtkList.at(i);
		AtkList.at(i) = NULL;
	}
	for (int i = 0; i < DefList.size(); i++) {
		delete DefList.at(i);
		DefList.at(i) = NULL;
	}
	delete playerCards;
	delete playerOrders;
	playerCards = NULL;
	playerOrders = NULL;
}

ostream& operator<<(ostream& output, Player& p) { //Output stream for basic ready player
	output << "Ready Player -- ;)";

	return output;
}