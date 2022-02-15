#include "../Header Files/Cards.h"

Card::Card(CardType ct) {
    cardType = ct;
}

Card::Card() {
    int val = rand() % 5 + 1;

    switch (val) {
    case 1: cardType = CardType::bomb; break;
    case 2: cardType = CardType::reinforcement; break;
    case 3: cardType = CardType::blockade; break;
    case 4: cardType = CardType::airlift; break;
    case 5: cardType = CardType::diplomacy; break;
    }
}

Card::Card(const Card& c) {
    cardType = c.cardType;
}

void Card::play(int index, Hand& player, Deck& deck) {
    // Take played card
    Card usedCard;
    cout << "HAND: " << player << endl;
    usedCard = player.removeCardAtIndex(index);    // Remove from hand and shift
    cout << "Played a card of type: " << usedCard << endl;
    cout << "HAND: " << player << endl;

    // Return card to deck
    deck.returnToDeck(usedCard);
}

ostream& operator<<(ostream& output, Card& C) {
    switch (C.cardType)
    {
    case bomb: output << "Bomb"; break;
    case reinforcement: output << "Reinforcement"; break;
    case blockade: output << "Blockade"; break;
    case airlift: output << "AirLift"; break;
    case diplomacy: output << "Diplomacy"; break;
    default: output << "[Unknown cardType]"; break;
    }
    return output;
}

Card& Card::operator=(const Card& c)
{
    cardType = c.cardType;
    return *this;
}

///////

Deck::Deck(int s) {
    size = s;
    cards = new Card[size];
    front = 0;
    back = s - 1;
}

Deck::Deck() {
    size = 52;
    cards = new Card[size];
    front = 0;
    back = 51;
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

Deck::~Deck() {
    delete[] cards;
    cards = nullptr;
}

void Deck::draw(Hand& player) {
    // Player is no longer able to draw a new card
    if (size <= 0) {
        cout << "Unable to pick up any more cards. Deck is empty." << endl;
        return;
    }

    // Player's hand is full and they cannot pick up another card
    if (player.getHandSize() >= player.getHandLimit()) {
        cout << "Unable to pick up any more cards. Player's hand is full." << endl;
        return;
    }

    // Take top card
    Card* topCard;
    topCard = &cards[front];
    if (front >= back) {      //only one element in queue
        front = -1;
        back = -1;
    }
    else {
        front++;
    }
    cout << "Drawing a card => " << *topCard << " from Deck" << endl;

    // Give hand the card
    player.addCard(topCard);
    size--;

    cout << "DECK: " << *this << endl << endl;
}

void Deck::returnToDeck(Card& newCard) {
    // Was the deck just empty?
    if (front == -1)
        front = 0;

    back++;
    cards[back] = newCard;
    size++;
    cout << endl << "Adding a card => " << cards[back] << " back to Deck" << endl;
    cout << "DECK: " << *this << endl << endl;
}

ostream& operator<<(ostream& output, const Deck& D) {
    int limit = D.front + D.size;
    for (int i = D.front; i < limit; i++) {
        output << D.cards[i];
        if (i < limit - 1)
            output << " --- ";
    }
    return output;
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

///////

Hand::Hand(int s) {
    limit = s;
    size = 0;
    cards = new Card[limit];
}

Hand::Hand() {
    limit = 12;
    size = 0;
    cards = new Card[limit];
}

Hand::Hand(const Hand& h)
{
    this->limit = h.limit;
    this->size = h.size;
    this->cards = new Card[limit];

    for (int i = 0; i < h.size; i++) {
        this->cards[i] = h.cards[i];
    }
}

Hand::~Hand() {
    delete[] cards;
    cards = nullptr;
}

void Hand::addCard(Card* newCard) {
    cards[size] = *newCard;
    size++;
}

Card Hand::removeCardAtIndex(int index) {
    Card removed = cards[index];

    for (int i = index; i < size - 1; i++) {
        cards[i] = cards[i + 1];
    }

    cout << "Removed -> " << removed << endl;
    size--;
    return removed;
}

ostream& operator<<(ostream& output, const Hand& H) {
    for (int i = 0; i < H.size; i++) {
        output << H.cards[i];
        if (i < H.size - 1)
            output << " --- ";
    }
    return output;
}
Hand& Hand::operator=(const Hand& h)
{
    this->limit = h.limit;
    this->size = h.size;
    this->cards = new Card[limit];

    for (int i = 0; i < h.size; i++) {
        this->cards[i] = h.cards[i];
    }
    return *this;
}