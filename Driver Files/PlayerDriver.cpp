#include "../Header Files/Player.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void playerMain() {

    //initialize the player
    Player* player = new Player();

    // TODO:: NEUTRAL PLAYER DOUBLE CHECK WITH TEACHER
    player->setPlayerId(1);
    player->setPlayerName("PeterParker");

    //initialize some new territories.
    Territory* territory1 = new Territory("big", 1, 1, 0);
    Territory* territory2 = new Territory("small", 2, 2, 0);
    Territory* territory3 = new Territory("medium", 3, 3, 0);


    //instantiate new list for player to defend
    Territory* territory4 = new Territory("large", 4, 4, 0);
    Territory* territory5 = new Territory("ice", 5, 5, 0);
    Territory* territory6 = new Territory("cap", 6, 6, 0);

    //add territories to the player defend list
    player->defendTerritory(territory4);
    player->defendTerritory(territory5);
    player->defendTerritory(territory5);
    player->defendTerritory(territory6);

    //player defend actions
    player->toDefend();
    player->displayTerritory(player->getDefendList());

    //verify player has hand by adding cards
    player->getHandLimit();


    //create new territory that should be used to add into the player class
    Territory* territory7 = new Territory("pikachu", 7, 7, 0);
    Territory* territory8 = new Territory("eevee", 8, 8, 0);
    Territory* territory9 = new Territory("jigglypuff", 9, 9, 0);


    //add territory belongs to the player
    player->addTerritory(territory7);
    player->addTerritory(territory8);
    player->addTerritory(territory9);
    player->displayTerritory(player->getTerritoryList());



    //create new orders
/*
        Deploy deploy1;
        Advance advance1;
        Bomb bomb1;
        Blockade blockade1;
        Airlift airlift1;
        Negotiate negotiate1;
*/

    Deploy* deploy1 = new Deploy(player, territory1, 3);
    //    Advance *advance1 = new Advance(player, territory1, territory2, 5);
    Bomb* bomb1 = new Bomb(player, territory3);
    Blockade* blockade1 = new Blockade(player, territory2);
    Airlift* airlift1 = new Airlift(player, territory3, territory4, 3);

    //issue new orders
    player->issueOrders(deploy1);
    //        player->issueOrders(advance1);
    player->issueOrders(bomb1);
    player->issueOrders(blockade1);
    player->issueOrders(airlift1);
    //  player->issueOrders(negotiate);
    Orderslist* ol = player->getOrderList();
    cout << "Ruochen working\n";
    ol->printOrderlist();
    cout << "Ruochen done testing\n";
    //use the player stream
    cout << "player 1 wanna talk: " << *player << endl;

    cout << "here is the new test" << endl;
    player->removeTerritory(territory7);
    player->displayTerritory(player->getTerritoryList());


    player->cancelDefend(territory4);
    player->cancelDefend(territory4);
    player->displayTerritory(player->getDefendList());


    //create a new player
    Player* player4 = new Player();
    player4->setPlayerId(4);
    player4->setPlayerName("IronMan");
    //create new territory that should be used to add into the player class
    Territory* territory10 = new Territory("new territory 10", 10, 7, 0);
    Territory* territory11 = new Territory("new territory 11", 11, 8, 0);
    Territory* territory12 = new Territory("new territory 12", 12, 9, 0);


    //add territory belongs to the player
    player4->addTerritory(territory10);
    player4->addTerritory(territory11);
    player4->addTerritory(territory12);
    player4->displayTerritory(player4->getTerritoryList());

    player->switchTerritories(territory8, player, player4);
    player->displayTerritory(player->getTerritoryList());
    player4->displayTerritory(player4->getTerritoryList());

    player4->getOrderList();
    cout << "-----------------------------" << endl;



    cout << player->getPlayerNumOfTerritoriesInContinent(9) << endl;



    player->displayTerritory(player->getTerritoryList());
    player->containsTerritory(territory1);
    player->containsTerritory(territory2);
    player->containsTerritory(territory9);

    territory1->setPlayer(1);
    cout << territory1->getPlayer() << endl;
    territory1->neutralState();
    cout << territory1->getPlayer() << endl;

    vector<Player*>* players = new vector<Player*>();
    players->push_back(player4);



}
