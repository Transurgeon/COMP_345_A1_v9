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

string Order::getType() {
	return *type;
}

void Order::execute() {

	bool validated = Order::validate();

	if (validated == true)
		cout << "The order is valid, executing now!";
	else 
		cout << "The order is not valid, pls double check your order!";
}

bool Order::validate() {
	return true;
}

Order::~Order() {
	delete type;
	type = NULL;
}

ostream& operator<<(ostream& output, Order& o) {
	
	return output << "The Order is of Type: " << o.getType();
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
	for (int i = 0; i < ol.OrderList.size(); i++)
	{
		output << "Order Number " << i << " is of type : "  << endl;
	}
	return output;
}
	/// <summary>
	/// Deploy
	/// </summary>
	Deploy::Deploy() {

		cout << "Deploy has been added" << endl;
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
			cout << "Order is Valid: Executing Deploy Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid Deploy Order" << endl;
		}
	}

	string* Deploy::getType() {
		return &type;
	}
	
	Deploy::~Deploy() {

	}
	/// <summary>
	/// Advance
	/// </summary>
	Advance::Advance() {

		cout << "Advance has been added" << endl;
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
			cout << "Order is Valid: Executing Advance Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid Advance Order" << endl;
		}
	}

	string* Advance::getType() {
		return &type;
	}

	Advance::~Advance() {

	}
/// <summary>
/// Bomb
/// </summary>
	Bomb::Bomb() {

		cout << "Bomb has been added" << endl;
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
			cout << "Order is Valid: Executing Bomb Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid Bomb Order" << endl;
		}
	}

	string* Bomb::getType() {
		return &type;
	}

	Bomb::~Bomb() {

	}
/// <summary>
/// Blockade
/// </summary>
	Blockade::Blockade() {

		cout << "Blockade has been added" << endl;
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
			cout << "Order is Valid: Executing Blockade Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid Blockade Order" << endl;
		}
	}

	string* Blockade::getType() {
		return &type;
	}

	Blockade::~Blockade() {

	}
/// <summary>
/// AirLift
/// </summary>
	AirLift::AirLift() {

		cout << "AirLift has been added" << endl;
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
			cout << "Order is Valid: Executing AirLift Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid AirLift Order" << endl;
		}
	}

	string* AirLift::getType() {
		return &type;
	}

	AirLift::~AirLift() {

	}
/// <summary>
/// Negotiate
/// </summary>
	Negotiate::Negotiate() {

		cout << "Negotiate has been added" << endl;
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
			cout << "Order is Valid: Executing Negotiate Order" << endl;
		}

		else
		{
			cout << "Order is Invalid: Invalid Negotiate Order" << endl;
		}
	}

	string* Negotiate::getType() {
		return &type;
	}

	Negotiate::~Negotiate() {

	}
