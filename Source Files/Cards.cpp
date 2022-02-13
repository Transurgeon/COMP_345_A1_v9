#include "../Header Files/Cards.h"

Card::Card() {

}

Card::Card(const Card& copy) {
	type = copy.type;
}

Card& Card::operator =(const Card& copy) {
	type = copy.type;
	return *this;
}

void Card::play() {

}

string* Card::getCardType()
{
	return type;
}

Card::~Card() {
	delete type;
	type = NULL;
}

ostream& operator<<(ostream& output, Card& c) {
	
	output << " This cards type is " << c.getCardType() << endl;
    return output;
	
}

Deck::Deck() {

}

Deck::Deck(const Deck& copy) {
	deck = copy.deck;
}

Deck& Deck::operator =(const Deck& copy) {
	deck = copy.deck;
	return *this;
}

void Deck::draw() {

}

vector<Card>* Deck::getDeck()
{
	return deck;
}

Deck::~Deck() {
	delete deck;
	deck = NULL;
}

ostream& operator<<(ostream& output, Deck& d) {
	
	output << " This deck consists of " << d.getDeck() << endl;
	return output;
	
}

Hand::Hand() {

}

Hand::Hand(Card* c) {
	
}

Hand::Hand(const Hand& copy) {
	hand = copy.hand;
}

Hand& Hand::operator =(const Hand& copy) {
	hand = copy.hand;
	return *this;
}

vector<Card>* Hand::getHand()
{
	return hand;
}

Hand::~Hand() {
	delete hand;
	hand = NULL;
}

ostream& operator<<(ostream& output, Hand& h) {
	
	output << " This hand consists of " << h.getHand() <<  endl;
	return output;
	
}