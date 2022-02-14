#include "../Header Files/Orders.h"

/// <summary>
/// Order
/// </summary>
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

/// <summary>
/// OrdersList
/// </summary>
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

ostream& operator<<(ostream& output, OrdersList& ol) {
	
	return output;
}
	/// <summary>
	/// Deploy
	/// </summary>
	Deploy::Deploy() {

	}

	Deploy::Deploy(const Deploy& deploy) {

	}

	Deploy& Deploy::operator=(const Deploy& deploy) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const Deploy& deploy) {
	output << "The Order is Deploy" << endl;
	return output;
	}

	bool Deploy::validate() {
		return true;
	}

	void Deploy::execute() {
		if (validate())
		{
			cout << "Executing Deploy Order" << endl;
		}

		else
		{
			cout << "Invalid Deploy Order" << endl;
		}
	}
	
	Deploy::~Deploy() {

	}
	/// <summary>
	/// Advance
	/// </summary>
	Advance::Advance() {
	}

	Advance::Advance(const Advance& Advance) {

	}

	Advance& Advance::operator=(const Advance& Advance) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const Advance& Advance) {
		output << "The Order is Advance" << endl;
		return output;
	}

	bool Advance::validate() {
		return true;
	}

	void Advance::execute() {
		if (validate())
		{
			cout << "Executing Advance Order" << endl;
		}

		else
		{
			cout << "Invalid Advance Order" << endl;
		}
	}

	Advance::~Advance() {

	}
/// <summary>
/// Bomb
/// </summary>
	Bomb::Bomb() {
	}

	Bomb::Bomb(const Bomb& Bomb) {

	}

	Bomb& Bomb::operator=(const Bomb& Bomb) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const Bomb& Bomb) {
		output << "The Order is Bomb" << endl;
		return output;
	}

	bool Bomb::validate() {
		return true;
	}

	void Bomb::execute() {
		if (validate())
		{
			cout << "Executing Bomb Order" << endl;
		}

		else
		{
			cout << "Invalid Bomb Order" << endl;
		}
	}

	Bomb::~Bomb() {

	}
/// <summary>
/// Blockade
/// </summary>
	Blockade::Blockade() {
	}

	Blockade::Blockade(const Blockade& Blockade) {

	}

	Blockade& Blockade::operator=(const Blockade& Blockade) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const Blockade& Blockade) {
		output << "The Order is Blockade" << endl;
		return output;
	}

	bool Blockade::validate() {
		return true;
	}

	void Blockade::execute() {
		if (validate())
		{
			cout << "Executing Blockade Order" << endl;
		}

		else
		{
			cout << "Invalid Blockade Order" << endl;
		}
	}

	Blockade::~Blockade() {

	}
/// <summary>
/// AirLift
/// </summary>
	AirLift::AirLift() {
	}

	AirLift::AirLift(const AirLift& AirLift) {

	}

	AirLift& AirLift::operator=(const AirLift& AirLift) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const AirLift& AirLift) {
		output << "The Order is AirLift" << endl;
		return output;
	}

	bool AirLift::validate() {
		return true;
	}

	void AirLift::execute() {
		if (validate())
		{
			cout << "Executing AirLift Order" << endl;
		}

		else
		{
			cout << "Invalid AirLift Order" << endl;
		}
	}

	AirLift::~AirLift() {

	}
/// <summary>
/// Negotiate
/// </summary>
	Negotiate::Negotiate() {
	}

	Negotiate::Negotiate(const Negotiate& Negotiate) {

	}

	Negotiate& Negotiate::operator=(const Negotiate& Negotiate) {
		return *this;
	}

	ostream& operator<<(std::ostream& output, const Negotiate& Negotiate) {
		output << "The Order is Negotiate" << endl;
		return output;
	}

	bool Negotiate::validate() {
		return true;
	}

	void Negotiate::execute() {
		if (validate())
		{
			cout << "Executing Negotiate Order" << endl;
		}

		else
		{
			cout << "Invalid Negotiate Order" << endl;
		}
	}

	Negotiate::~Negotiate() {

	}
