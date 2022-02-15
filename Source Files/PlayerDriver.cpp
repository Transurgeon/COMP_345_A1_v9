#include "../Header Files/Player.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void playerMain() {
    //instantiating player
    Player* player = new Player();

    cout << "player says yallah hi: " << *player << endl;
    //instantiating territories
    Territory* t1 = new Territory(1, 1, "gabby");
    Territory* t2 = new Territory(2, 2, "legend");
    Territory* t3 = new Territory(3, 3, "hans");
    Territory* t4 = new Territory(4, 4, "zimmer");
    Territory* t5 = new Territory(5, 5, "hit-fan");
    Territory* t6 = new Territory(6, 6, "william");
    Territory* t7 = new Territory(7, 7, "kendrick");
    Territory* t8 = new Territory(8, 8, "lamar");
    Territory* t9 = new Territory(9, 9, "cole");
    //testing attack method along with adding territories to the attack vector
    player->attack(t1);
    player->attack(t2);
    player->attack(t3);
    player->toAttack();
    //testing defend method along with adding territories to the defend vector
    player->defend(t4);
    player->defend(t5);
    player->defend(t6);
    player->toDefend();
    //testing showTerritories method along with adding territories to the player
    player->add(t7);
    player->add(t8);
    player->add(t9);
    player->showTerritories();
    //iniating orders
    cout << endl;
    Deploy* deployOrder = new Deploy;
    Advance* advanceOrder = new Advance;
    Negotiate* negotiateOrder = new Negotiate;
    //showing issue order and that it has created an orderlist object
    player->issueOrder(deployOrder);
    player->issueOrder(advanceOrder);
    player->issueOrder(negotiateOrder);
    player->getPlayerOrders();

    Card* c1 = new Card();
    Card* c2 = new Card();
    Card* c3 = new Card();
    vector<Card*> v1;
    v1.push_back(c1);
    v1.push_back(c2);
    v1.push_back(c3);
    Hand* playerH = new Hand();

}
