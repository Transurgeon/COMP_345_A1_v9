#include "../Header Files/Cards.h"

using namespace std;

void cardsMain() {
    //initiating deck and hand constructors and giving them both a maxSize of 5
    Deck d1(5);
    Hand p1(8);
    
    //testing copy constructors;
    Card* card1 = new Card();
    cout << "Testing copy constructors by creating two card objects: " << endl;
    cout << *card1 << endl;
    Card* card2;
    card2 = card1;
    cout << *card2 << endl;
    cout << endl;
    //showing contents of deck
    cout << "The deck contains: " << endl << d1 << endl;
    //drawing 6 cards from the deck to the hand
    for (int i = 0; i < 6; i++) {
        cout << endl;
        d1.draw(p1);
    }
    cout << endl;
    //showing contents of hand
    cout << "The hand contains: " << p1 << endl;

    cout << endl;
    //testing play method for card
    Card* toPlay = p1.searchCard(3);
    toPlay->play(3, p1, d1);
    //drawing more cards
        d1.draw(p1);
        d1.draw(p1);
        d1.draw(p1);

    cout << endl;
    //showing final hand output
    cout << "The hand contains: " << p1 << endl;
}
