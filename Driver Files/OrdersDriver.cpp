#include "../Header Files/Orders.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void ordersMain() {
    Player* player1 = new Player();
    player1->setPlayerId(1);
    player1->setPlayerName("player1");
    Player* player2 = new Player();
    player2->setPlayerId(2);
    player2->setPlayerName("player2");
    const int SIZE = 4;


    Card* bombCard = new Card(bomb);
    Card* airliftCard = new Card(airlift);
    Card* blockadeCard = new Card(blockade);
    Card* diplomacyCard = new Card(diplomacy);

    player1->getHand()->addCard(bombCard);
    player1->getHand()->addCard(airliftCard);
    player2->getHand()->addCard(airliftCard);
    player1->getHand()->addCard(blockadeCard);
    player1->getHand()->addCard(diplomacyCard);


    Territory* territory1 = new Territory(1, 1, 0, "big");
    Territory* territory2 = new Territory(2, 2, 3, "small");
    Territory* territory3 = new Territory(3, 3, 5, "medium");
    Territory* territory4 = new Territory(4, 4, 8, "large");

    player1->addTerritory(territory1);
    player1->addTerritory(territory2);
    player2->addTerritory(territory3);
    player2->addTerritory(territory4);

    cout << "creating deploy order---------" << endl;
    Deploy* deploy1 = new Deploy(player1, territory1, 3);

    cout << "validate deploy---------" << endl;
    deploy1->validate();
    cout << "execute deploy---------" << endl;
    deploy1->execute();

    cout << "creating advance order---------" << endl;
    Advance* advance1 = new Advance(player1, player2, territory1, territory2, 1);
   
    //
    cout << "validate advance---------" << endl;
    advance1->validate();
    cout << "execute advance---------" << endl;
    advance1->execute();

    cout << "creating bomb order---------" << endl;
    Bomb* bomb1 = new Bomb(player1, territory3);

    cout << "validate bomb---------" << endl;
    bomb1->validate();
    cout << "execute bomb---------" << endl;
    bomb1->execute();

    cout << "creating blockade order---------" << endl;
    Blockade* blockade1 = new Blockade(player1, territory2);

    cout << "validate blockade---------" << endl;
    blockade1->validate();
    cout << "execute blockade---------" << endl;
    blockade1->execute();


    cout << "creating airlift order---------" << endl;
    Airlift* airlift1 = new Airlift(player1, territory1, territory2, 1);
    //Airlift *airlift1 = new Airlift(player2, territory3, territory4, 3);

    cout << "validate airlift---------" << endl;
    airlift1->validate();
    cout << "execute airlift---------" << endl;
    airlift1->execute();


    player1->issueOrders(deploy1);
    player1->issueOrders(advance1);
    player1->issueOrders(bomb1);
    player1->issueOrders(blockade1);
    player2->issueOrders(airlift1);

    Orderslist ol;

    ol.setOrderList(bomb1);
    ol.setOrderList(blockade1);
    ol.setOrderList(airlift1);
    //        ol.setOrderList(advance1);
    ol.setOrderList(deploy1);


    cout << "creating airlift order---------" << endl;
    Negotiate* negotiate1 = new Negotiate(player1, player2);


    player1->issueOrders(negotiate1);

    cout << "validate negotiate---------" << endl;
    negotiate1->validate();
    cout << "execute negotiate--------" << endl;
    negotiate1->execute();


    player1->issueOrders(bomb1);
    bomb1->validate();
    bomb1->execute();

}

