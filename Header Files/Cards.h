#pragma once
#ifndef COMP_345_Cards_h
#define COMP_345_Cards_h
#pragma once
#include <iostream>
using namespace std;

enum CardType { bomb = 1, reinforcement = 2, blockade = 3, airlift = 4, diplomacy = 5 };

class Card;
class Deck;
class Hand;

class Card {
public:
    Card(CardType ct);
    Card();
    Card(const Card& c);
    void play(int index, Hand& player, Deck& deck);
    friend ostream& operator<<(ostream& output, Card& C);
    Card& operator=(const Card& c);
private:
    CardType cardType;
};

class Deck {
public:
    Deck(int deckSize);
    Deck();
    Deck(const Deck& d);
    ~Deck();
    void draw(Hand& player);
    void returnToDeck(Card& newCard);
    friend ostream& operator<<(ostream& output, const Deck& D);
    Deck& operator=(const Deck& d);
private:
    int size;
    int front;
    int back;
    Card* cards;
};

class Hand {
public:
    Hand(int handSize);
    Hand();
    Hand(const Hand& h);
    ~Hand();
    void addCard(Card* newCard);
    int getHandSize() { return size; }
    int getHandLimit() { return limit; }
    Card removeCardAtIndex(int index);
    Card* getCardAtIndex(int index) { return &cards[index]; }
    friend ostream& operator<<(ostream& output, const Hand& H);
    Hand& operator=(const Hand& h);
private:
    int size;
    int limit;
    Card* cards;
};

#endif 