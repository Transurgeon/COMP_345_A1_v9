#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#include "../Header Files/Cards.h"
void cardsMain() {
    srand(time(NULL));
    Deck deckA(5);
    Hand playerA(5);

    cout << "DECK: " << endl << deckA << endl;

    // Draw cards from deck
    for (int i = 0; i < 6; i++) {
        deckA.draw(playerA);
    }

    cout << "HAND: " << playerA << endl;

    // Play cards from hand
    for (int i = 0; i < playerA.getHandSize(); i++) {
        Card* chosen = playerA.searchCard(3);
        chosen->play(3, playerA, deckA);
    }

    // Draw cards from deck (again)
    for (int i = 0; i < 3; i++) {
        deckA.draw(playerA);
    }

    Card* c1 = new Card();
    cout << *c1 << endl;
    Card* c2;
    c2 = c1;
    cout << *c2 << endl;

    cout << endl;
    cout << playerA << endl;
}
