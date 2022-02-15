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
    Card();
    Card(Card_Types c);
    Card(const Card& c);
    Card& operator=(const Card& c);
    void play(int pos, Hand& p, Deck& d);

    ~Card();
    friend ostream& operator<<(ostream& output, Card& c);
};

class Deck {
private:
    int deckSize;
    int top;
    int bot;
    Card* deckCards;
public:
    Deck();
    Deck(int s);
    Deck(const Deck& d);
    Deck& operator=(const Deck& d);

    void draw(Hand& p);
    void returnToDeck(Card& nC);

    ~Deck();
    friend ostream& operator<<(ostream& output, Deck& D);
};

class Hand {
private:
    int handSize;
    int maxSize;
    Card* handCards;
public:
    Hand();
    Hand(int s);
    Hand(const Hand& h);
    Hand& operator=(const Hand& h);

    void addCard(Card* nC);
    int getHandSize();
    int getMaxSize();
    Card* searchCard(int pos);
    Card removeCard(int pos);

    ~Hand();
    friend ostream& operator<<(ostream& output, Hand& H);
    
};

#endif 