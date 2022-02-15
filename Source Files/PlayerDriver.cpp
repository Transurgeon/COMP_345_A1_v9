#include "../Header Files/Player.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void playerMain() {
    Player* player = new Player();

    cout << "player says yallah hi: " << *player << endl;

    Territory* t1 = new Territory(1, 1, "gabby");
    Territory* t2 = new Territory( 2, 2, "legend");
    Territory* t3 = new Territory( 3, 3, "hans");
    Territory* t4 = new Territory( 4, 4, "zimmer");
    Territory* t5 = new Territory( 5, 5,"hit-fan");
    Territory* t6 = new Territory( 6, 6, "william");
    Territory* t7 = new Territory( 7, 7, "kendrick");
    Territory* t8 = new Territory(8, 8, "lamar");
    Territory* t9 = new Territory(9, 9, "cole");
    
    player->attack(t1);
    player->attack(t2);
    player->attack(t3);
    player->toAttack();

    player->defend(t4);
    player->defend(t5);
    player->defend(t6);
    player->toDefend();

    player->add(t7);
    player->add(t8);
    player->add(t9);
    player->showTerritories();

    cout << endl;
    Deploy* deployOrder = new Deploy;
    Advance* advanceOrder = new Advance;
    Bomb* bombOrder = new Bomb;
    Blockade* blockadeOrder = new Blockade;
    AirLift* airliftOrder = new AirLift;
    Negotiate* negotiateOrder = new Negotiate;

    player->issueOrder(deployOrder);
    player->issueOrder(advanceOrder);
    player->issueOrder(bombOrder);
    player->issueOrder(blockadeOrder);
    player->issueOrder(airliftOrder);
    player->issueOrder(negotiateOrder);

    player->getPlayerOrders();

}
