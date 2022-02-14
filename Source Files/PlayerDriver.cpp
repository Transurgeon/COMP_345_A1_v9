#include "../Header Files/Player.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void playerMain() {
    Player* player = new Player();

    Territory* territory1 = new Territory(1, 1, "gabby");
    Territory* territory2 = new Territory( 2, 2, "legend");
    Territory* territory3 = new Territory( 3, 3, "hans");
    Territory* territory4 = new Territory( 4, 4, "zimmer");
    Territory* territory5 = new Territory( 5, 5,"hit-fan");
    Territory* territory6 = new Territory( 6, 6, "william");

    player->toAttack();

    player->toDefend();

    Territory* territory7 = new Territory( 7, 7, "kendrick");
    Territory* territory8 = new Territory(8, 8, "lamar");
    Territory* territory9 = new Territory(9, 9, "cole");

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

    Player* player2 = player;
    player2->toAttack();

    Player* player3;
    player3 = player;
    player3->toDefend();

    cout << "player 1 says yallah" << *player << endl;


}
