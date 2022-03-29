#include "../Header Files/Orders.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void ordersMain() {
    Player* p1 = new Player();Player* p2 = new Player();
    p1->setPlayerId(1); p2->setPlayerId(2);
    p1->setPlayerName("William"); p2->setPlayerName("Gabriel");
    const int SIZE = 4;

    Card* BOMB = new Card(bomb); Card* DIPLO = new Card(diplomacy);
    Card* BLOCK = new Card(blockade); Card* AIRLIFT = new Card(airlift);

    p1->getHand()->addCard(BOMB); p1->getHand()->addCard(DIPLO);
    p1->getHand()->addCard(AIRLIFT); p1->getHand()->addCard(BLOCK);
    p2->getHand()->addCard(AIRLIFT);

    Territory* t1 = new Territory(1, 1, 0, "Kendrick"); Territory* t2 = new Territory(2, 2, 3, "MortalMan");
    Territory* t3 = new Territory(3, 3, 5, "Tank-Shebab"); Territory* t4 = new Territory(4, 4, 8, "Gabbie");

    p1->addTerritory(t1); p1->addTerritory(t2);
    p2->addTerritory(t3); p2->addTerritory(t4);
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Deploy Order " << endl;
    Deploy* DEPLOY_1 = new Deploy(p1, t1, 3);

    cout << "Showing Validation of the Deploy Order " << endl; DEPLOY_1->validate();
    cout << "Executing Deploy Order" << endl; DEPLOY_1->execute();

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Bomb Order " << endl;
    Bomb* BOMB_1 = new Bomb(p1, t3);

    cout << "Showing Validation of the Bomb Order" << endl; BOMB_1->validate();
    cout << "Executing Bomb Order" << endl; BOMB_1->execute();

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Blockade Order " << endl;
    Blockade* BLOCK_1 = new Blockade(p1, t2);

    cout << "Showing Validation of the Blockade Order" << endl; BLOCK_1->validate();
    cout << "Executing Blockade Order" << endl; BLOCK_1->execute();

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Airlift Order " << endl;
    Airlift* AIR_1 = new Airlift(p1, t1, t2, 1);

    cout << "Showing Validation of the Airlift Order" << endl; AIR_1->validate();
    cout << "Executing Airlift Order" << endl; AIR_1->execute();

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Advance Order " << endl;
    Advance* ADV_1 = new Advance(p1, p2, t1, t2, 1);

    cout << "Showing Validation of the Advance Order" << endl;
    AIR_1->validate();
    cout << "Executing Advance Order" << endl;
    AIR_1->execute();
    Orderslist ordersList;

    p1->issueOrders(DEPLOY_1); p1->issueOrders(ADV_1);
    p1->issueOrders(BOMB_1); p1->issueOrders(BLOCK_1);
    p2->issueOrders(AIR_1);

    cout << "////////////////////////////////////////////////////////" << endl;

    ordersList.setOrderList(BOMB_1); ordersList.setOrderList(BLOCK_1);
    ordersList.setOrderList(AIR_1); ordersList.setOrderList(DEPLOY_1);

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Initialising the Negotiate Order" << endl;
    Negotiate* NEGOTIATE_1 = new Negotiate(p1, p2);

    p1->issueOrders(NEGOTIATE_1);

    cout << "Showing Validation of the Negotiate Order" << endl; NEGOTIATE_1->validate();
    cout << "Executing Negotiate Order" << endl; NEGOTIATE_1->execute();
}

