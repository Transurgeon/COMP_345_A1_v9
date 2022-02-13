#pragma once
#ifndef COMP_345_Orders_h
#define COMP_345_Orders_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Order {
private:
	vector<string> Order_types{ "deploy", "advance", "bomb", "blockade", "airlift", "negotiate" };
	string* type;
public:
	Order();
	Order(string*  t);
	Order(const Order& copy);
	Order& operator =(const Order& copy);
	string* getType();
	void execute();
	bool validate();

	~Order();
	friend ostream& operator<<(ostream& output, Order& o);
};

class OrdersList {
private:
	vector<Order*> OrderList;

public:
	OrdersList();
	OrdersList(vector<Order*> o);
	OrdersList(const OrdersList& copy);
	OrdersList& operator =(const OrdersList& copy);
	vector<Order*> getOrderList();
	void add(Order* order);
	void move(int currentPos, int newPos);
	void remove(int pos);

	~OrdersList();
	friend ostream& operator<<(ostream& output, OrdersList& ol);
};

class Deploy : Order {
public:
	Deploy();
	Deploy(const Deploy& deploy);
	Deploy& operator=(const Deploy& deploy);
	friend std::ostream& operator<<(std::ostream& out, const Deploy& deploy);
	bool validate();
	void execute();
	~Deploy();
};

class Advance : Order {
public:
	Advance();
	Advance(const Advance& advance);
	Advance& operator=(const Advance& advance);
	friend std::ostream& operator<<(std::ostream& out, const Advance& advance);
	bool validate();
	void execute();
	~Advance();
};

class Bomb : Order {
public:
	Bomb();
	Bomb(const Bomb& Bomb);
	Bomb& operator=(const Bomb& Bomb);
	friend std::ostream& operator<<(std::ostream& out, const Bomb& Bomb);
	bool validate();
	void execute();
	~Bomb();
};

class Blockade : Order {
public:
	Blockade();
	Blockade(const Blockade& Blockade);
	Blockade& operator=(const Blockade& Blockade);
	friend std::ostream& operator<<(std::ostream& out, const Blockade& Blockade);
	bool validate();
	void execute();
	~Blockade();
};

class AirLift : Order {
public:
	AirLift();
	AirLift(const AirLift& AirLift);
	AirLift& operator=(const AirLift& AirLift);
	friend std::ostream& operator<<(std::ostream& out, const AirLift& AirLift);
	bool validate();
	void execute();
	~AirLift();
};

class Negotiate : Order {
public:
	Negotiate();
	Negotiate(const Negotiate& Negotiate);
	Negotiate& operator=(const Negotiate& Negotiate);
	friend std::ostream& operator<<(std::ostream& out, const Negotiate& Negotiate);
	bool validate();
	void execute();
	~Negotiate();
};
#endif
