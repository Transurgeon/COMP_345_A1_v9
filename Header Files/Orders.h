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
	vector<Order>* OrderList;

public:
	OrdersList();
	OrdersList(Order* o);
	OrdersList(const OrdersList& copy);
	OrdersList& operator =(const OrdersList& copy);
	vector<Order>* getOrderList();
	void move();
	void remove();

	~OrdersList();
	friend ostream& operator<<(ostream& output, OrdersList& ol);
};
#endif
