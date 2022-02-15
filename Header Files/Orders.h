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
	Order();
	Order(const Order& copy);
	Order& operator =(const Order& copy);
	string getType();
	void set_orderNum(int o);
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

class Deploy : public Order {
private:
	string type = "Deploy";

public:
	Deploy();
	Deploy(const Deploy& deploy);
	Deploy& operator=(const Deploy& deploy);
	friend std::ostream& operator<<(std::ostream& out, const Deploy& deploy);
	bool validate();
	void execute();
	string* getType();
	~Deploy();
};

class Advance : public Order {
private:
	string type = "Advance";

public:
	Advance();
	Advance(const Advance& advance);
	Advance& operator=(const Advance& advance);
	friend std::ostream& operator<<(std::ostream& out, const Advance& advance);
	bool validate();
	void execute();
	string* getType();
	~Advance();
};

class Bomb : public Order {
private:
	string type = "Bomb";

public:
	Bomb();
	Bomb(const Bomb& Bomb);
	Bomb& operator=(const Bomb& Bomb);
	friend std::ostream& operator<<(std::ostream& out, const Bomb& Bomb);
	bool validate();
	void execute();
	string* getType();
	~Bomb();
};

class Blockade : public Order {
private:
	string type = "Blockade";

public:
	Blockade();
	Blockade(const Blockade& Blockade);
	Blockade& operator=(const Blockade& Blockade);
	friend std::ostream& operator<<(std::ostream& out, const Blockade& Blockade);
	bool validate();
	void execute();
	string* getType();
	~Blockade();
};

class AirLift : public Order {
private:
	string type = "AirLift";

public:
	AirLift();
	AirLift(const AirLift& AirLift);
	AirLift& operator=(const AirLift& AirLift);
	friend std::ostream& operator<<(std::ostream& out, const AirLift& AirLift);
	bool validate();
	void execute();
	string* getType();
	~AirLift();
};

class Negotiate : public Order {
private:
	string type = "Negotiate";

public:
	Negotiate();
	Negotiate(const Negotiate& Negotiate);
	Negotiate& operator=(const Negotiate& Negotiate);
	friend std::ostream& operator<<(std::ostream& out, const Negotiate& Negotiate);
	bool validate();
	void execute();
	string* getType();
	~Negotiate();
};
#endif
