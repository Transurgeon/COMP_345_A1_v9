#include "../Header Files/Cards.h"


/// <summary>
/// Card
/// </summary>

Card::Card() {

    switch (rand() % 5) 
    {
    case 0: cardType = Card_Types::bomb; 
        break;
    case 1: cardType = Card_Types::reinforcement; 
        break;
    case 2: cardType = Card_Types::blockade;
        break;
    case 3: cardType = Card_Types::airlift;
        break;
    case 4: cardType = Card_Types::diplomacy; 
        break;
    }
}

Card::Card(Card_Types c) {
    cardType = c;
}

Card::Card(const Card& c) {
    cardType = c.cardType;
}

Card& Card::operator=(const Card& c)
{
    cardType = c.cardType;
    return *this;
}

void Card::play(int pos, Hand& p, Deck& d) {
    Card played;
    cout << endl;

    cout << "Outputting hand content: " << p << endl;
    played = p.removeCard(pos);  
    cout << endl;

    cout << "The card that was played is of type: " << played << endl;
    cout << endl;

    cout << "Outputting hand content after card was played: " << p << endl;

    d.returnToDeck(played);
}

Card::~Card() {

}

ostream& operator<<(ostream& output, Card& c) {
    switch (c.cardType)
    {
    case bomb: output << "BOMB"; 
        break;
    case reinforcement: output << "REINFORCEMENT"; 
        break;
    case blockade: output << "BLOCKADE"; 
        break;
    case airlift: output << "AIRLIFT"; 
        break;
    case diplomacy: output << "DIPLOMACY"; 
        break;
    default: output << "No card type or card type is invalid";
        break;
    }
    return output;
}

/// <summary>
/// Deck
/// </summary>
/// 
Deck::Deck() {
    size = 52;
    cards = new Card[size];
    front = 0;
    back = 51;
}

Deck::Deck(int s) {
    size = s;
    cards = new Card[size];
    front = 0;
    back = s - 1;
}

Deck::Deck(const Deck& d)
{
    this->front = d.front;
    this->back = d.back;
    this->size = d.size;
    this->cards = new Card[size];

    for (int i = 0; i < d.size; i++) {
        this->cards[i] = d.cards[i];
    }
}

Deck& Deck::operator=(const Deck& d)
{
    this->front = d.front;
    this->back = d.back;
    this->size = d.size;
    this->cards = new Card[size];

    int limit = d.front + d.size;

    for (int i = d.front; i < limit; i++) {
        this->cards[i] = d.cards[i];
    }
    return *this;
}

Deck::~Deck() {
    delete[] cards;
    cards = nullptr;
}

void Deck::draw(Hand& p) {

    if (size <= 0) {
        cout << "Unable to pick up any more cards. Deck is empty." << endl;
        return;
    }

    if (p.getHandSize() >= p.getMaxSize()) {
        cout << "Unable to pick up any more cards. Player's hand is full." << endl;
        return;
    }

    Card* topCard;
    topCard = &cards[front];
    if (front >= back) {    
        front = -1;
        back = -1;
    }
    else {
        front++;
    }
    cout << "Drawing a card => " << *topCard << " from Deck" << endl;

    p.addCard(topCard);
    size--;

    cout << "DECK: " << endl << *this << endl << endl;
}

void Deck::returnToDeck(Card& nC) {
    if (front == -1)
        front = 0;

    back++;
    cards[back] = nC;
    size++;
    cout << endl << "Returning a " << cards[back] << " card back to Deck" << endl;
    cout << "DECK: " << *this << endl << endl;
}

ostream& operator<<(ostream& output, Deck& D) {
    int limit = D.front + D.size;
    for (int i = D.front; i < limit; i++) {
        output << D.cards[i];
        if (i < limit - 1)
            output << endl;
    }
    return output;
}

/// <summary>
/// Hand
/// </summary>

Hand::Hand() {
    maxSize = 6;
    handSize = 0;
    handCards = new Card[maxSize];
}

Hand::Hand(int s) {
    maxSize = s;
    handSize = 0;
    handCards = new Card[maxSize];
}

Hand::Hand(const Hand& h)
{
    for (int i = 0; i < h.handSize; i++) {
        this->handCards[i] = h.handCards[i];
    }
    this->maxSize = h.maxSize;
    this->handSize = h.handSize;
    this->handCards = new Card[maxSize];
}

Hand& Hand::operator=(const Hand& h)
{
    for (int i = 0; i < h.handSize; i++) {
        this->handCards[i] = h.handCards[i];
    }
    this->maxSize = h.maxSize;
    this->handSize = h.handSize;
    this->handCards = new Card[maxSize];
    return *this;
}

Hand::~Hand() {
    delete[] handCards;
    handCards = nullptr;
}

void Hand::addCard(Card* nC) {
    handCards[handSize] = *nC;
    handSize++;
}

int Hand::getHandSize() { 
    return handSize; 
}

int Hand::getMaxSize() { 
    return maxSize; 
}

Card* Hand::searchCard(int pos) {
    return &handCards[pos]; 
}

Card Hand::removeCard(int pos) {
    Card removed = handCards[pos];

    for (int i = pos; i < handSize - 1; i++) {
        handCards[i] = handCards[i + 1];
    }

    cout << "Removed -> " << removed << endl;
    handSize--;
    return removed;
}

ostream& operator<<(ostream& output, Hand& H) {
    for (int i = 0; i < H.handSize; i++) {
        output << H.handCards[i];
        if (i < H.handSize - 1)
            output << endl;
    }
    return output;
}