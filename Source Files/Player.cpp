#include "../Header Files/Player.h"
#include <vector>
#include <stack>

Player::Player() {
	territoriesNum = vector<Territory*>();
	DefList = vector<Territory*>();
	AtkList = vector<Territory*>();
	playerCards = new Hand();
	playerOrders = new OrdersList();
}

Player::Player(vector<Territory*> t, Hand* h, OrdersList* o) {
	territoriesNum = t;
	playerCards = h;
	playerOrders = o;
}

Player::Player(const Player& copy) {
	territoriesNum = copy.territoriesNum;
	DefList = copy.DefList;
	AtkList = copy.AtkList;
	playerCards = new Hand(*copy.playerCards);
	playerOrders = new OrdersList(*copy.playerOrders);
}

Player& Player::operator =(const Player& copy) {
	territoriesNum = copy.territoriesNum;
	DefList = copy.DefList;
	AtkList = copy.AtkList;
	playerCards = new Hand(*copy.playerCards);
	playerOrders = new OrdersList(*copy.playerOrders);
	return *this;
}

vector<Territory*> Player::toDefend() { 
	cout << '\n' << "Here is the list of territories the player needs to defend: " << '\n' << endl;
	for (int i = 0; i < DefList.size(); ++i) {
		cout << DefList.at(i)->getName() << endl;
	}
	return DefList;
}

vector<Territory*> Player::toAttack() {
	cout << '\n' << "Here is the list of territories the player needs to attack: " << '\n' << endl;
	for (int i = 0; i < AtkList.size(); ++i) {
		cout << AtkList.at(i)->getName() << endl;
	}
	return AtkList;
}

vector<Territory*> Player::showTerritories() {
	cout << '\n' << "This is the list of territories that the player owns: " << '\n' << endl;
	for (int i = 0; i < territoriesNum.size(); ++i) {
		cout << territoriesNum.at(i)->getName() << endl;
	}
	return territoriesNum;
}

void Player::attack(Territory* a) {
	AtkList.push_back(a);
}

void Player::defend(Territory* d) {
	DefList.push_back(d);
}

void Player::add(Territory* t) {
	territoriesNum.push_back(t);
}

vector<Territory*> Player::getTerritoriesNum() {
	return territoriesNum;
}
Hand* Player::getPlayerCards() {
	return playerCards;
}
OrdersList* Player::getPlayerOrders() {
	cout << endl;
	cout << "Showing player's orders list" << endl;
	cout << endl;
	cout << *playerOrders << endl;
	return playerOrders;
}

void Player::issueOrder(Order* order) {
	playerOrders->add(order);
}

Player::~Player() {
	
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

ostream& operator<<(ostream& output, Player& p) {
	output << "Ready Player -- ;)";

	return output;
}