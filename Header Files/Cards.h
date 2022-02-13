#pragma once
#ifndef COMP_345_Cards_h
#define COMP_345_Cards_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card {
private:
	vector<string> Card_types{ "bomb", "reinforcement", "blockade", "airlift", "displomacy" };
	string* type;
public: 
	Card();
	Card(const Card& copy);
	Card& operator =(const Card& copy);
	
	void play();
	string* getCardType();

	~Card();
	friend ostream& operator<<(ostream& output, Card& c);
};

class Deck
{
private:
	vector<Card> *deck;

public:
	Deck();
	Deck(const Deck& copy);
	Deck& operator =(const Deck& copy);

	void draw();
	vector<Card> *getDeck();

	~Deck();
	friend ostream& operator<<(ostream& output, Deck& d);
};

class Hand
{
private:
	vector<Card>* hand;

public:
	Hand();
	Hand(Card* c);
	Hand(const Hand& copy);
	Hand& operator =(const Hand& copy);
	vector<Card>* getHand();

	~Hand();
	friend ostream& operator<<(ostream& output, Hand& h);
};

#endif

