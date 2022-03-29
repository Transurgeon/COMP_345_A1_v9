#pragma once
#ifndef COMP_345_Orders_h
#define COMP_345_Orders_h

#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/LoggingObserver.h"
#include "../Header Files/Cards.h"
#include "../Header Files/Player.h"
#include "../Header Files/Map.h"
using namespace std;


class Player;
class Territory;
class Map;
class Card;
class Deck;
class Hand;

struct Order {
private:
    int id;
    bool valid;
    vector<string> orders = { "deploy","advance","bomb","blockade","airlift","negotiate" };
    bool attackable = true;

public:
    //constructor & destructor
    Order();
    Order(Player* player);
    ~Order();
    Order(const Order& copiedO);
    Order& operator = (const Order& O);
    friend ostream& operator <<(ostream& out, const Order& o);
    friend istream& operator >> (istream& in, Order& o);

    virtual bool validate() = 0;
    virtual void execute() = 0;

    void setID(int i);

    string getOrderType();
    Map* map;
    Player* player;
    bool getAttackable() { return attackable; };
    void setAttackable(bool isAttackable) { attackable = isAttackable; };
    const Player* getOrderIssuer();
    void setOrderIssuer(Player* issuer);
};


struct Deploy : public Order, public ILoggable, public Subject {
private:
    Territory* targetTerritory;
    unsigned int armies;
    string deployExecute;
public:
    Deploy();
    Deploy(Player* player, Territory* targetTerritory, unsigned int armies);
    ~Deploy();
    Deploy(const Deploy& copiedDe);
    Deploy& operator = (const Deploy& Do);
    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;
};
struct Bomb : public Order, public ILoggable, public Subject {
private:
    Territory* targetTerritory;
    string bombExecute;
public:
    Bomb();
    Bomb(Player* player, Territory* targetTerritory);
    ~Bomb();
    Bomb(const Bomb& copiedBo);
    Bomb& operator = (const Bomb& Bo);

    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;

};

struct Advance : public Order, public ILoggable, public Subject {
private:
    Territory* fromTerritory;
    Territory* toTerritory;
    Player* targetPlayer;
    unsigned int armies;
    string advanceExecute;
    Card* card = new Card();
public:
    Advance();
    Advance(Player* player, Player* targetPlayer, Territory* fromTerritory, Territory* toTerritory, unsigned int armies);
    ~Advance();
    Advance(const Advance& copiedAd);
    Advance& operator = (const Advance& Ao);

    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;
};

struct Blockade : public Order, public ILoggable, public Subject {
private:
    Territory* targetTerritory;
    string blockadeExecute; 
public:
    Blockade();
    Blockade(Player* player, Territory* targetTerritory);
    ~Blockade();
    Blockade(const Blockade& copiedBl);
    Blockade& operator = (const Blockade& Blo);

    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;
};

struct Airlift : public Order, public ILoggable, public Subject {
private:
    Territory* fromTerritory;
    Territory* toTerritory;
    unsigned int armies;
    string airliftExecute;
public:
    Airlift();
    Airlift(Player* player, Territory* fromTerritory, Territory* toTerritory, unsigned int armies);
    ~Airlift();
    Airlift(const Airlift& copoedAir);
    Airlift& operator = (const Airlift& Airo);

    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;
};

struct Negotiate : public Order, public ILoggable, public Subject {
private:
    Player* targetPlayer;
    string negotiateExecute;
public:
    Negotiate();
    Negotiate(Player* player, Player* targetPlayer);
    ~Negotiate();
    Negotiate(const Negotiate& copiedNe);
    Negotiate& operator = (const Negotiate& Neo);

    virtual bool validate()override;
    virtual void execute()override;

    //stringTolog from observer
    string stringToLog() override;
};

class Orderslist :public ILoggable, public Subject {
private:
    vector<Order*> orderlist;
    string orderForObs;
public:
    Orderslist();
    Orderslist(const Orderslist& copiedOl);
    ~Orderslist();
    Orderslist& operator = (const Orderslist& Ol);
    friend ostream& operator <<(ostream& out, const Orderslist& ol);
    friend istream& operator >> (istream& in, Orderslist& ol);
    //getter setter of the orderlist
    void setOrderList(Order* order);
    vector<Order*>* getOrderList();

    //methods to modify the list
    void remove(Order* order);
    void move(int origin, int targetPosition);
    void printOrderlist();
    //method from ILoggable and Subject for Observer
    string stringToLog() override;
};

#endif
