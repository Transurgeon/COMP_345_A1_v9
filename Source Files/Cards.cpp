#include "../Header Files/Cards.h"


/// <summary>
/// Card
/// </summary>

//Constructors, Destructors and Operators
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

Card::Card(const Card& copy) {
    cardType = copy.cardType;
}

Card& Card::operator=(const Card& copy)
{
    cardType = copy.cardType;
    return *this;
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

//play method
void Card::play(int pos, Hand& p, Deck& d) {
    //initialising card to be played
    Card played;
    cout << endl;

    cout << "Outputting hand content: " << p << endl;
    //calling remove card which deletes a card from the hand
    played = p.removeCard(pos);
    cout << endl;
    //cout information about the card
    cout << "The card that was played is of type: " << played << endl;
    cout << endl;
    //cout information about the hand after card is played
    cout << "Outputting hand content after card was played: " << p << endl;
    //returning card back to the deck
    d.returnToDeck(played);
}

/// <summary>
/// Deck
/// </summary>

//Constructors, Destructors and Operators
Deck::Deck() {
    top = 0;
    bot = 19;
    deckSize = 20;
    deckCards = new Card[deckSize];
}

Deck::Deck(int s) {
    top = 0;
    bot = s - 1;
    deckSize = s;
    deckCards = new Card[deckSize];
}

Deck::Deck(const Deck& copy)
{
    this->top = copy.top;
    this->bot = copy.bot;
    this->deckSize = copy.deckSize;
    this->deckCards = new Card[deckSize];
    for (int i = 0; i < copy.deckSize; i++) {
        this->deckCards[i] = copy.deckCards[i];
    }
}

Deck& Deck::operator=(const Deck& copy)
{
    this->top = copy.top;
    this->bot = copy.bot;
    this->deckSize = copy.deckSize;
    this->deckCards = new Card[deckSize];
    for (int i = copy.top; i < copy.top + copy.deckSize; i++) {
        this->deckCards[i] = copy.deckCards[i];
    }
    return *this;
}

Deck::~Deck() {
    delete[] deckCards;
    deckCards = nullptr;
}

void Deck::returnToDeck(Card& nC) {
    if (top == -1)
        top = 0;

    bot++;
    deckCards[bot] = nC;
    deckSize++;
    cout << endl << "Returning a " << deckCards[bot] << " card back to the Deck" << endl;
    cout << "The deck contains: " << *this << endl << endl;
}

ostream& operator<<(ostream& output, Deck& D) {
    int limit = D.top + D.deckSize;
    for (int i = D.top; i < limit; i++) {
        output << D.deckCards[i];
        if (i < limit - 1)
            output << endl;
    }
    return output;
}

//draw method
void Deck::draw(Hand& p) {
    //if hand has more cards than its max size
    if (p.getHandSize() >= p.getMaxSize()) {
        cout << "Player hand is full!!! Cannot Draw Anymore cards" << endl;
        return;
    }
    //if deck doesn't have anymore cards it outputs this below
    else if (deckSize <= 0) {
        cout << "Deck contains no more deckCards!!! Cannot Draw Anymore cards" << endl;
        return;
    }
    //initialise card to be drawn and set it equal to reference of the top card
    Card* topCard;
    topCard = &deckCards[top];
    if (top >= bot) {    
        top --;
        bot --;
    }
    else {
        top++;
    }
    //outputting information about the card that has been drawn
    cout << "Drawing a " << *topCard << " card from the top of the Deck" << endl;
    //adding card to the hand
    p.addCard(topCard);
    //reducing the deck size 
    deckSize--;

    cout << "The deck contains: " << endl << *this << endl << endl;
}

/// <summary>
/// Hand
/// </summary>

//Constructors, Destructors and Operators
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

Hand::Hand(const Hand& copy)
{
    for (int i = 0; i < copy.handSize; i++) {
        this->handCards[i] = copy.handCards[i];
    }
    this->maxSize = copy.maxSize;
    this->handSize = copy.handSize;
    this->handCards = new Card[maxSize];
}

Hand& Hand::operator=(const Hand& copy)
{
    for (int i = 0; i < copy.handSize; i++) {
        this->handCards[i] = copy.handCards[i];
    }
    this->maxSize = copy.maxSize;
    this->handSize = copy.handSize;
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

    cout << "This card has been removed from the hand: " << removed << endl;
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