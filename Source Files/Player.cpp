#include "../Header Files/Player.h"

Player::Player() {

}

Player::Player(vector<Territory>* t, Hand* h, OrdersList* o) {
	territoriesNum = t;
	playerCards = h;
	playerOrders = o;
}

Player::Player(const Player& copy) {
	territoriesNum = copy.territoriesNum;
	playerCards = new Hand(*copy.playerCards);
	playerOrders = new OrdersList(*copy.playerOrders);
}

Player& Player::operator =(const Player& copy) {
	territoriesNum = copy.territoriesNum;
	playerCards = new Hand(*copy.playerCards);
	playerOrders = new OrdersList(*copy.playerOrders);
	return *this;
}

void Player::assignTerritories() {

}

void Player::toDefend() {
	vector<Territory>* territories = getTerritoriesNum();

	for (int i = 0; i < territories->size(); i++)
	{
		bool defended = false;


	};
	/*
	* 
	array[] = needDefend;
	for (0->territories) {
	bool defended = false;
	for each(territory){
		if ()
	}
	

	needDefend.add(territory)
	}
	*/
}

void Player::toAttack() {
	vector<Territory>* territories = getTerritoriesNum();

	for (int i = 0; i < territories->size(); i++)
	{
		bool defended = false;
		

	};
	/*
	*
	array[] = toAttack;
	for (0->territories) {
	bool attack = false;
	toAttack.add(territory.edges)
	toAttack.removeDuplicates();

	cout<< toAttack();
	}

	*/
}
vector<Territory>* Player::getTerritoriesNum() {
	return territoriesNum;
}
Hand* Player::getPlayerCards() {
	return playerCards;
}
OrdersList* Player::getPlayerOrders() {
	return playerOrders;
}

Order Player::issueOrder() {
	return NULL;
}

Player::~Player() {
	delete territoriesNum;
	delete playerCards;
	delete playerOrders;
	territoriesNum = NULL;
	playerCards = NULL;
	playerOrders = NULL;
}

ostream& operator<<(ostream& output, const Player& p) {
	/*output << " This territory is called" << t.getName() << " the country number is:" << t.getCountryNum() << endl;
	output << " This territory is part of the continent number: " << t.getContinent() << " it is owned by" << t.getName() << endl;*/
	output << "hi";
	return output;
}