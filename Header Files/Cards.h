#pragma once
#ifndef COMP_345_Cards_h
#define COMP_345_Cards_h
#pragma once
#include <iostream>
using namespace std;

enum Card_Types {bomb,reinforcement, blockade, airlift, diplomacy};

class Card;
class Deck;
class Hand;

class Card {
private:
    Card_Types cardType;
public:
    //Constructors, Destructors and Operators
    Card();
    Card(Card_Types c);
    Card(const Card& c);
    Card& operator=(const Card& c);
    ~Card();
    friend ostream& operator<<(ostream& output, Card& c);

    //Play method
    void play(int pos, Hand& p, Deck& d);

};

class Deck {
private:
    int deckSize;
    int top;
    int bot;
    Card* deckCards;
public:
    //Constructors, Destructors and Operators
    Deck();
    Deck(int s);
    Deck(const Deck& d);
    Deck& operator=(const Deck& d);
    ~Deck();
    friend ostream& operator<<(ostream& output, Deck& D);

    //Draw methods
    void draw(Hand& p);
    void returnToDeck(Card& nC);
};

class Hand {
private:
    int handSize;
    int maxSize;
    Card* handCards;
public:
    //Constructors, Destructors and Operators
    Hand();
    Hand(int s);
    Hand(const Hand& h);
    Hand& operator=(const Hand& h);
    ~Hand();
    friend ostream& operator<<(ostream& output, Hand& H);

    //Getters
    int getHandSize();
    int getMaxSize();

    //Add, search and remove methods
    void addCard(Card* nC);
    Card* searchCard(int pos);
    Card removeCard(int pos);


    
};

#endif 