#include "../Header Files/Orders.h"

Order::Order() {

}

Order::Order(string* t) {
	type = t;
}

Order::Order(const Order& copy) {
	type = new string(*copy.type);
}

Order& Order::operator =(const Order& copy) {
	type = new string(*copy.type);
		return *this;
}

string* Order::getType() {
	return type;
}

void Order::execute() {

}

bool Order::validate() {
	return true;
}

Order::~Order() {
	delete type;
	type = NULL;
}

ostream& operator<<(ostream& output, const Order& o) {
	/*output << " This territory is called" << t.getName() << " the country number is:" << t.getCountryNum() << endl;
	output << " This territory is part of the continent number: " << t.getContinent() << " it is owned by" << t.getName() << endl;
	return output;*/
	output << "hi";
	return output;
}

OrdersList::OrdersList() {

}

OrdersList::OrdersList(Order* o) {
	
}

OrdersList::OrdersList(const OrdersList& copy) {
	OrderList = copy.OrderList;
}

OrdersList& OrdersList::operator =(const OrdersList& copy) {
	OrderList = copy.OrderList;
	return *this;
}

vector<Order>* OrdersList::getOrderList() {
	return OrderList;
}

void OrdersList::move() {

}

void OrdersList::remove() {

}

OrdersList::~OrdersList() {
	delete OrderList;
	OrderList = NULL;
}

ostream& operator<<(ostream& output, const OrdersList& ol) {
	/*output << " This territory is called" << t.getName() << " the country number is:" << t.getCountryNum() << endl;
	output << " This territory is part of the continent number: " << t.getContinent() << " it is owned by" << t.getName() << endl;
	return output;*/
	output << "hi";
	return output;
}
