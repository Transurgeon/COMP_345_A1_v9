#pragma once
#ifndef COMP_345_Cards_h
#define COMP_345_Cards_h
#pragma once
#include <iostream>
using namespace std;

class Deck;
class Hand;
enum CardType { bomb = 1, reinforcement = 2, blockade = 3, airlift = 4, diplomacy = 5 };

/// <summary>
/// Card Class 
/// </summary>
class Card {
private:
    CardType cardType;
public:
    //Constructors, Destructors, and default string 'CardType' constructor
    Card(CardType ct);
    Card();
    Card(const Card& c);

    void play(int index, Hand& player, Deck& deck);
    friend ostream& operator<<(ostream& output, Card& C);
    Card& operator=(const Card& c);
    //"kind of inline" functions
    CardType getCardType() { return cardType; }
};

class Deck {
private:
    int size;
    Card* cards;
public:
    //Constructors, Destructors, and default deck constructor
    Deck();
    ~Deck();
    Deck(int deckSize);
    Deck(const Deck& d);
    
    void draw(Hand& player);
    void returnToDeck(Card& newCard);
    friend ostream& operator<<(ostream& output, const Deck& D);
    Deck& operator=(const Deck& d);
};

class Hand {
private:
    int size;
    int limit;
    Card* cards;
public:
    //Constructors, Destructors, and default hand constructor 
    Hand();
    ~Hand();
    Hand(int handSize);
    Hand(const Hand& h);

    void addCard(Card* newCard);
    Card removeCardAtIndex(int index);
    friend ostream& operator<<(ostream& output, const Hand& H);
    Hand& operator=(const Hand& h);
    bool getCardByType(CardType ct);
    //"kind of inline" functions
    int getHandSize() { return size; }
    int getHandLimit() { return limit; }
    
    Card* getCardAtIndex(int index) { return &cards[index]; }
};

#endif 