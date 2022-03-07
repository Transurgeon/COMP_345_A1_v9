#pragma once
#ifndef COMP_345_Orders_h
#define COMP_345_Orders_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player;

class Order {
private:
	vector<string> Order_types{ "DEPLOY", "ADVANCE", "BOMB", "BLOCKADE", "AIRLIFT", "NEGOTIATE" };
	int orderNum;

public:
	//Constructors, Destructors and Operators
	Order(); 
	Order(const Order& copy); 
	Order& operator =(const Order& copy); 
	~Order(); 
	friend ostream& operator<<(ostream& output, Order& o);

	//Getters and Setters
	string getType();
	void set_orderNum(int o);

	//Validates the order
	bool validate();

	//Executes the order
	virtual void execute() = 0;
	
};

class OrdersList {
private:
	vector<Order*> OrderList;

public:
	//Constructors, Destructors and Operators
	OrdersList(); 
	OrdersList(vector<Order*> o);
	OrdersList(const OrdersList& copy); 
	OrdersList& operator =(const OrdersList& copy); 
	vector<Order*> getOrderList(); //getter
	~OrdersList(); 
	friend ostream& operator<<(ostream& output, OrdersList& ol);
	
	//add, move and remove orders in the list
	void add(Order* order);
	void move(int currentPos, int newPos);
	void remove(int pos);
	
};

//place some armies on one of the current players territories
class Deploy : public Order {
private:
	string type = "Deploy";
	
public:
	//attributes for executing the deploy order
	Player* p1;
	int t1;
	int troopNum;

	Deploy(Player* p1, int t1, int troopNum);
	//Constructors, Destructors and Operators
	Deploy(); 
	Deploy(const Deploy& deploy);
	Deploy& operator=(const Deploy& deploy);
	friend std::ostream& operator<<(std::ostream& out, const Deploy& deploy);
	string* getType();
	~Deploy();

	//Validates the order
	bool validate();

	//Executes the order
	void execute() override;

};

//move some armies from one of the current players territories (source) to an adjacent territory (target).If the target territory 
//belongs to the current player, the armies are moved to the target territory. Else an attack happens between the two territories
class Advance : public Order {
private:
	string type = "Advance";
	
public:
	//attributes for executing the advance order
	Player* p1;
	int t1;
	int t2;
	int troopNum;

	Advance(Player* p1, int t1, int t2, int troopNum);
	//Constructors, Destructors and Operators
	Advance(); 
	Advance(const Advance& advance);
	Advance& operator=(const Advance& advance);
	friend std::ostream& operator<<(std::ostream& out, const Advance& advance);
	string* getType();
	~Advance();

	//Validates the order
	bool validate();

	//Executes the order
	void execute();

};

//destroy half of the armies located on an opponents territory that is adjacent to one of the current players territories
class Bomb : public Order {
private:
	string type = "Bomb";
	
public:
	//attributes for executing the bomb order
	Player* p1;
	int target;

	Bomb(Player* p1, int target);
	//Constructors, Destructors and Operators
	Bomb();
	Bomb(const Bomb& Bomb);
	Bomb& operator=(const Bomb& Bomb);
	friend std::ostream& operator<<(std::ostream& out, const Bomb& Bomb);
	string* getType();
	~Bomb();

	//Validates the order
	bool validate();

	//Executes the order
	void execute();

};

//triple the number of armies on one of the current players territories and make it a neutral territory
class Blockade : public Order {
private:
	string type = "Blockade";
	
public:
	//attributes for executing the blockade order
	Player* p1;
	int t1;

	Blockade(Player* p1, int t1);
	//Constructors, Destructors and Operators
	Blockade(); 
	Blockade(const Blockade& Blockade);
	Blockade& operator=(const Blockade& Blockade);
	friend std::ostream& operator<<(std::ostream& out, const Blockade& Blockade);
	string* getType();
	~Blockade();

	//Validates the order
	bool validate();

	//Executes the order
	void execute();

};

//advance some armies from one of the current players territories to any another territory
class AirLift : public Order {
private:
	string type = "AirLift";
	
public:
	//attributes for executing the airlift order
	Player* p1;
	int t1;
	int t2;
	int troopNum;

	AirLift(Player* p1, int t1, int t2, int troopNum);
	//Constructors, Destructors and Operators
	AirLift(); 
	AirLift(const AirLift& AirLift);
	AirLift& operator=(const AirLift& AirLift);
	friend std::ostream& operator<<(std::ostream& out, const AirLift& AirLift);
	string* getType();
	~AirLift();

	//Validates the order
	bool validate();

	//Executes the order
	void execute();

};

//prevent attacks between the current player and another player until the end of the turn
class Negotiate : public Order {
private:
	string type = "Negotiate";
	
public:
	//attributes for executing the negotiate order
	Player* p1;
	Player* p2;

	Negotiate(Player* p1, Player* p2);
	//Constructors, Destructors and Operators
	Negotiate(); 
	Negotiate(const Negotiate& Negotiate);
	Negotiate& operator=(const Negotiate& Negotiate);
	friend std::ostream& operator<<(std::ostream& out, const Negotiate& Negotiate);
	string* getType();
	~Negotiate();

	//Validates the order
	bool validate();

	//Executes the order
	void execute();
	
};
#endif
