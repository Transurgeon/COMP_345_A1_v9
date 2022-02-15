#pragma once
#ifndef COMP345_P_CARDS_H
#define COMP345_P_CARDS_H
#pragma once
#include <iostream>
using namespace std;

enum CardType { bomb = 1, reinforcement = 2, blockade = 3, airlift = 4, diplomacy = 5 };

class Card;
class Deck;
class Hand;

class Card {
public:
    // Constructor that initializes the card as the specified card type
    Card(CardType ct);
    // Constructor that initializes the card to a random card type
    Card();
    // Copy Constructor
    Card(const Card& c);
    void play(int index, Hand& player, Deck& deck);
    friend ostream& operator<<(ostream& output, Card& C);
    Card& operator=(const Card& c);
private:
    CardType cardType;
};

class Deck {
public:
    // Constructor that initializes the deck with a specified deck size
    Deck(int deckSize);
    // Constructor that initializes the deck with the set size of 52
    Deck();
    // Copy Constructor
    Deck(const Deck& d);
    // Destructor
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
    // Constructor that initializes the hand with a specified hand size
    Hand(int handSize);
    // Constructor that initializes the hand with the set size of 12
    Hand();
    // Copy Constructor
    Hand(const Hand& h);
    // Destructor
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

#endif //COMP345_P_CARDS_H