#include "../Header Files/Player.h"
#include <vector>
#include <stack>

Player::Player() {

}

Player::Player(vector<Territory*> t, Hand* h, OrdersList* o) {
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

vector<Territory*> Player::toDefend() { //Might return a list of territory pointers
	vector<Territory*> territories = getTerritoriesNum();

	//for (int i = 0; i < territories->size(); i++)
	//{
	//	bool defended = false;
	//	for (Territory* t : territories){
	//		if(defended = true)
	//			
	//	}
	//	territories->insert()//insert a territory

	//};
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
	return territories;
}

void Player::toAttack() {
	vector<Territory*> territories = getTerritoriesNum();

	/*for (int i = 0; i < territories->size(); i++)
	{
		bool attacked = false;
		for (Territory* t : territories) {

			if (attacked = true)
				territories->insert(territories.edges);

			territories.removeDuplicates();
			cout << territories;

		}
	};*/
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
vector<Territory*> Player::getTerritoriesNum() {
	return territoriesNum;
}
Hand* Player::getPlayerCards() {
	return playerCards;
}
OrdersList* Player::getPlayerOrders() {
	return playerOrders;
}

void Player::issueOrder(Order* order) {
	playerOrders->add(order);
}

Player::~Player() {
	//delete territoriesNum;
	delete playerCards;
	delete playerOrders;
	//territoriesNum = NULL;
	playerCards = NULL;
	playerOrders = NULL;
}

ostream& operator<<(ostream& output, Player& p) {
	output << "Ready Player -- ;)";
	return output;
}