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

	bool validated = Order::validate();

	if (validated == true)
		cout << "The order is valid, executing now!";
	else 
		cout << "The order is not valid, pls double check your order!";
}

bool Order::validate() {
	if (Order::getType() )
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

OrdersList::OrdersList(vector<Order*> o) {
	this->OrderList = o;
}

OrdersList::OrdersList(const OrdersList& copy) {
	OrderList = copy.OrderList;
}

OrdersList& OrdersList::operator =(const OrdersList& copy) {
	OrderList = copy.OrderList;
	return *this;
}

vector<Order*> OrdersList::getOrderList() {
	return OrderList;
}

void OrdersList::add(Order* order) {
	OrderList.push_back(order);
}

void OrdersList::move(int currentPos, int newPos) {
	Order* temp = OrderList[currentPos];
	OrderList.erase(OrderList.begin() + (currentPos));
	OrderList.insert(OrderList.begin() + newPos, temp);
}

void OrdersList::remove(int pos) {

	int i = 0;
	for (Order* order : OrderList)
	{
		if (i == pos)
		{
			delete order;
			order = nullptr;
		}
		i++;
	}
	OrderList.erase(OrderList.begin() + pos);
}

OrdersList::~OrdersList() {
	for (Order* order : OrderList)
	{
		delete order;
		order = nullptr;
	}
}

ostream& operator<<(ostream& output, const OrdersList& ol) {
	/*output << " This territory is called" << t.getName() << " the country number is:" << t.getCountryNum() << endl;
	output << " This territory is part of the continent number: " << t.getContinent() << " it is owned by" << t.getName() << endl;
	return output;*/
	output << "hi";
	return output;
}

Deploy::Deploy() {
	}

Deploy::Deploy(const Deploy& deploy) {

	}

Deploy& Deploy::operator=(const Deploy& deploy) {
	
	}

ostream& operator<<(std::ostream& output, const Deploy& deploy) {
	output << "The Order is Deploy" << endl;
	return output;
	}

bool Deploy::validate() {

	}

void Deploy::execute() {

	}

Deploy::~Deploy() {

}

	Advance::Advance() {
	}

	Advance::Advance(const Advance& Advance) {

	}

	Advance& Advance::operator=(const Advance& Advance) {

	}

	ostream& operator<<(std::ostream& output, const Advance& Advance) {
		output << "The Order is Advance" << endl;
		return output;
	}

	bool Advance::validate() {

	}

	void Advance::execute() {

	}

	Advance::~Advance() {

	}

	Bomb::Bomb() {
	}

	Bomb::Bomb(const Bomb& Bomb) {

	}

	Bomb& Bomb::operator=(const Bomb& Bomb) {

	}

	ostream& operator<<(std::ostream& output, const Bomb& Bomb) {
		output << "The Order is Bomb" << endl;
		return output;
	}

	bool Bomb::validate() {

	}

	void Bomb::execute() {

	}

	Bomb::~Bomb() {

	}

	Blockade::Blockade() {
	}

	Blockade::Blockade(const Blockade& Blockade) {

	}

	Blockade& Blockade::operator=(const Blockade& Blockade) {

	}

	ostream& operator<<(std::ostream& output, const Blockade& Blockade) {
		output << "The Order is Blockade" << endl;
		return output;
	}

	bool Blockade::validate() {

	}

	void Blockade::execute() {

	}

	Blockade::~Blockade() {

	}

	AirLift::AirLift() {
	}

	AirLift::AirLift(const AirLift& AirLift) {

	}

	AirLift& AirLift::operator=(const AirLift& AirLift) {

	}

	ostream& operator<<(std::ostream& output, const AirLift& AirLift) {
		output << "The Order is AirLift" << endl;
		return output;
	}

	bool AirLift::validate() {

	}

	void AirLift::execute() {

	}

	AirLift::~AirLift() {

	}

	Negotiate::Negotiate() {
	}

	Negotiate::Negotiate(const Negotiate& Negotiate) {

	}

	Negotiate& Negotiate::operator=(const Negotiate& Negotiate) {

	}

	ostream& operator<<(std::ostream& output, const Negotiate& Negotiate) {
		output << "The Order is Negotiate" << endl;
		return output;
	}

	bool Negotiate::validate() {

	}

	void Negotiate::execute() {

	}

	Negotiate::~Negotiate() {

	}
