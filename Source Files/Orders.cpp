#include "../Header Files/Orders.h"

/// <summary>
/// Order
/// </summary>

//Constructors, Destructors and Operators
Order::Order() {
	this->orderNum = 0;
}

Order::Order(const Order& copy) {
	this->Order_types = *new vector<string>();
	this->orderNum = *new int(copy.orderNum);
}

Order& Order::operator =(const Order& copy) {
	this->Order_types = *new vector<string>();
	this->orderNum = *new int(copy.orderNum);
	return *this;
}

//Getters and Setters
string Order::getType() {
	return Order_types.at(orderNum);
}

void Order::set_orderNum(int o) {
	orderNum = o;
}

Order::~Order() {
}

ostream& operator<<(ostream& output, Order& o) {

	return output << "The Order is of Type: " << o.getType();
}

//Executes the order
void Order::execute() {

	bool validated = Order::validate();

	if (validated == true)
		cout << "The order is valid, executing now!";
	else
		cout << "The order is not valid, pls double check your order!";
}

//Validates the order
bool Order::validate() {
	return true;
}

/// <summary>
/// OrdersList
/// </summary>

//Constructors, Destructors and Operators
OrdersList::OrdersList() {

}

OrdersList::OrdersList(vector<Order*> o) {
	this->OrderList = o;
}

OrdersList::OrdersList(const OrdersList& copy) {
	for (int i = 0; i < copy.OrderList.size(); i++)
	{

		if (copy.OrderList[i]->getType() == "DEPLOY")
		{
			this->OrderList.push_back(new Deploy());
		}
		else if (copy.OrderList[i]->getType() == "ADVANCE")
		{
			this->OrderList.push_back(new Advance());
		}
		else if (copy.OrderList[i]->getType() == "BOMB")
		{
			this->OrderList.push_back(new Bomb());
		}
		else if (copy.OrderList[i]->getType() == "BLOCKADE")
		{
			this->OrderList.push_back(new Blockade());
		}
		else if (copy.OrderList[i]->getType() == "AIRLIFT")
		{
			this->OrderList.push_back(new AirLift());
		}
		else if (copy.OrderList[i]->getType() == "NEGOTIATE")
		{
			this->OrderList.push_back(new Negotiate());
		}
	}
}

OrdersList& OrdersList::operator =(const OrdersList& copy) {
	OrderList = copy.OrderList;
	return *this;
}

vector<Order*> OrdersList::getOrderList() {
	return OrderList;
}

OrdersList::~OrdersList() {
	for (Order* order : OrderList)
	{
		delete order;
		order = nullptr;
	}
}

ostream& operator<<(ostream& output, OrdersList& ol) {

	for (int i = 0; i < ol.getOrderList().size(); i++)
	{
		output << "Order Number " << i + 1 << " is of type : " << ol.getOrderList().at(i)->getType() << endl;
	}

	return output;
}

//add, move and remove orders in the list
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

/// <summary>
/// Deploy
/// </summary>

//Constructors, Destructors and Operators
Deploy::Deploy() {
	set_orderNum(0);
	cout << "Deploy has been added" << endl;
}

Deploy::Deploy(const Deploy& deploy) {
	this->type = *new string(deploy.type);
}

Deploy& Deploy::operator=(const Deploy& deploy) {
	this->type = *new string(deploy.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Deploy& deploy) {
	output << "The Order is Deploy" << endl;
	return output;
}

string* Deploy::getType() {
	return &type;
}

Deploy::~Deploy() {

}

//Validates the order
bool Deploy::validate() {
	return true;
}

//Executes the order
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

/// <summary>
/// Advance
/// </summary>

//Constructors, Destructors and Operators
Advance::Advance() {
	set_orderNum(1);
	cout << "Advance has been added" << endl;
}

Advance::Advance(const Advance& Advance) {
	this->type = *new string(Advance.type);
}

Advance& Advance::operator=(const Advance& Advance) {
	this->type = *new string(Advance.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Advance& Advance) {
	output << "The Order is Advance" << endl;
	return output;
}

string* Advance::getType() {
	return &type;
}

Advance::~Advance() {

}

//Validates the order
bool Advance::validate() {
	return true;
}

//Executes the order
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

/// <summary>
/// Bomb
/// </summary>

//Constructors, Destructors and Operators
Bomb::Bomb() {
	set_orderNum(2);
	cout << "Bomb has been added" << endl;
}

Bomb::Bomb(const Bomb& Bomb) {
	this->type = *new string(Bomb.type);
}

Bomb& Bomb::operator=(const Bomb& Bomb) {
	this->type = *new string(Bomb.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Bomb& Bomb) {
	output << "The Order is Bomb" << endl;
	return output;
}

string* Bomb::getType() {
	return &type;
}

Bomb::~Bomb() {

}

//Validates the order
bool Bomb::validate() {
	return true;
}

//Executes the order
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

/// <summary>
/// Blockade
/// </summary>

//Constructors, Destructors and Operators
Blockade::Blockade() {
	set_orderNum(3);
	cout << "Blockade has been added" << endl;
}

Blockade::Blockade(const Blockade& Blockade) {
	this->type = *new string(Blockade.type);
}

Blockade& Blockade::operator=(const Blockade& Blockade) {
	this->type = *new string(Blockade.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Blockade& Blockade) {
	output << "The Order is Blockade" << endl;
	return output;
}

string* Blockade::getType() {
	return &type;
}

Blockade::~Blockade() {

}

//Validates the order
bool Blockade::validate() {
	return true;
}

//Executes the order
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


/// <summary>
/// AirLift
/// </summary>

//Constructors, Destructors and Operators
AirLift::AirLift() {
	set_orderNum(4);
	cout << "AirLift has been added" << endl;
}

AirLift::AirLift(const AirLift& AirLift) {
	this->type = *new string(AirLift.type);
}

AirLift& AirLift::operator=(const AirLift& AirLift) {
	this->type = *new string(AirLift.type);
	return *this;
}

ostream& operator<<(std::ostream& output, AirLift& AirLift) {
	output << "The Order is AirLift" << endl;
	return output;
}

string* AirLift::getType() {
	return &type;
}

AirLift::~AirLift() {

}

//Validates the order
bool AirLift::validate() {
	return true;
}

//Executes the order
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

/// <summary>
/// Negotiate
/// </summary>

//Constructors, Destructors and Operators
Negotiate::Negotiate() {
	set_orderNum(5);
	cout << "Negotiate has been added" << endl;
}

Negotiate::Negotiate(const Negotiate& Negotiate) {
	this->type = *new string(Negotiate.type);
}

Negotiate& Negotiate::operator=(const Negotiate& Negotiate) {
	this->type = *new string(Negotiate.type);
	return *this;
}

ostream& operator<<(std::ostream& output, Negotiate& Negotiate) {
	output << "The Order is Negotiate" << endl;
	return output;
}

string* Negotiate::getType() {
	return &type;
}

Negotiate::~Negotiate() {

}

//Validates the order
bool Negotiate::validate() {
	return true;
}

//Executes the order
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
