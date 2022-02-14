#include "../Header Files/Cards.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void cardsMain() {
    //initialising hand
    Card* card1 = new Card(0);
    vector<Card*> vcards1;
    vcards1.push_back(card1);
    Hand* handp = new Hand(vcards1);

    //initialising deck
    Card* card2 = new Card(1);
    vector<Card*> vdeck1;
    vdeck1.push_back(card2);
    Deck* deckp = new Deck(vdeck1);

    // Displaying deck and hand
    cout << "Creating deck and hand" << endl;
    handp->print();
    deckp->print();

    // Playing first card and displaying deck and hand
    // SHOWING PLAY METHOD
    (*card1).play();
    cout << "After playing card 1 at position 0" << endl;
    handp->print();
    deckp->print();

    // Drawing first card and displaying deck and hand
    // SHOWING DRAW METHOD
    deckp->draw(handp);
    cout << "After drawing 1 card from deck to player's hand" << endl;
    handp->print();
    deckp->print();

    delete deckp;
    delete handp;
}

