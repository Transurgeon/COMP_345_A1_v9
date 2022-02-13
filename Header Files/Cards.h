#pragma once
#ifndef COMP_345_Cards_h
#define COMP_345_Cards_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Declared empty because we use them before properly declaring
class Deck;
class Hand;
class Player;
class GameStarter;

class Card {
private:
	string cardType;

public: 
    Card();
    Card(string cardType);
    Card(int intCardType);
    Card(const Card& initCard);
    Card& operator=(const Card& card);
    friend std::ostream& operator<<(std::ostream& stream, const Card& card);
    string getCardTypeString();
    void setCardType(string cardType);
    //void play(Deck* deck, Player* player, Map* map, GameStarter* gameStarter);
};

class Deck
{
private:
    vector<Card*> cardsInDeck;

public:
    Deck();
    Deck(vector<Card*> cardsInDeck);
    Deck(const Deck& initDeck);
    Deck& operator=(const Deck& deck);
    friend std::ostream& operator<<(std::ostream& stream, const Deck& deck);
    ~Deck();
    vector<Card*> getDeckCards();
    void setDeckCards(vector<Card*> cardsInDeck);
    void addCardToDeck(Card* card);
    void removeCardFromDeck(int index);
    void draw(Hand* hand);
    int nbCards();
    void print();
};

class Hand
{
private:
    vector<Card*> cardsInHand;

public:
    Hand();
    Hand(vector<Card*> cardsInHand);
    Hand(const Hand& initHand);
    Hand& operator=(const Hand& hand);
    friend std::ostream& operator<<(std::ostream& stream, const Hand& hand);
    ~Hand();
    vector<Card*> getHandCards();
    void setHandCards(vector<Card*> cardsInHand);
    void addCardToHand(Card* card);
    void removeCardFromHand(int index);
    int getCardIndex(Card* card);
    int nbCards();
    void print();
};

#endif

