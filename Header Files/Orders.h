#pragma once
#ifndef COMP_345_Orders_h
#define COMP_345_Orders_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
	void execute();
	
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

class Deploy : public Order {
private:
	string type = "Deploy";

public:
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
	void execute();

};

class Advance : public Order {
private:
	string type = "Advance";

public:
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

class Bomb : public Order {
private:
	string type = "Bomb";

public:
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

class Blockade : public Order {
private:
	string type = "Blockade";

public:
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

class AirLift : public Order {
private:
	string type = "AirLift";

public:
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

class Negotiate : public Order {
private:
	string type = "Negotiate";

public:
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
