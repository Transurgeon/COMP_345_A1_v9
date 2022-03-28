#include "../Header Files/Cards.h"

using namespace std;

void cardsMain() {
    srand(time(NULL));
    Deck deckA(10);
    Hand playerA(15);

    cout << "DECK: " << deckA << endl;

    // Draw cards from deck
    for (int i = 0; i < 15; i++) {
        deckA.draw(playerA);
    }

    cout << "HAND: " << playerA << endl;

    // Play cards from hand
    for (int i = 0; i < playerA.getHandSize(); i++) {
        Card* chosen = playerA.getCardAtIndex(3);
        chosen->play(3, playerA, deckA);
    }

    // Draw cards from deck (again)
    for (int i = 0; i < 3; i++) {
        deckA.draw(playerA);
    }

    // Some testing
    cout << endl;
    Card* c1 = new Card();
    cout << *c1 << endl;
    Card* c2;
    c2 = c1;
    cout << *c2 << endl;

    cout << endl;
    cout << deckA << endl;
    Deck deckB;
    deckB = deckA;
    cout << deckB << endl;

    cout << endl;
    cout << playerA << endl;
    Hand playerB;
    playerB = playerA;
    cout << playerB;

}
