#include "../Header Files/Player.h"
#include "../Header Files/PlayerStrategies.h"

bool checkNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}
/// <summary>
/// Human
/// </summary>
void HumanPlayerStrategy::issueOrder(Map* m, Player* p) {

    cout << "Friendly territories to deploy or advance to:\n";
    for (Territory* t : p->getDefendList()) {
        cout << *t << endl;
    }
    cout << "\n\n\nEnemy territories to advance to:\n";
    for (Territory* t : p->getAttackList()) {
        cout << *t << endl;
    }

    //input variables : target is for advance
    string territory;
    string target;
    string troop;

    //do while loop for deploying phase
    do {
        cout << "Remaining troops: " << p->getArmyNum() << "\n" << endl;
        cout << "Which territory do you wish to deploy to? Please refer to your defendList above^^^" << endl;
        cin >> territory;
        cout << "how many troops do you want to place on " << territory << "?\n";
        cin >> troop;
        //copied from startup Phase
        while (!checkNumber(troop) || stoi(troop) < 0 || stoi(troop) > p->getArmyNum()) {
            cout << "incorrect input! please make sure to write a whole number between 0 and " << p->getArmyNum() << endl;
            cin >> troop;
        }
        
        //initiating deploy : need to figure out territory as parameter (cannot accept string)
        //auto* d = new Deploy(p, territory, troop);
        //adding to OrderList of player
        //p.orderList.push_back(d)
        
        //removing troops from the player
        p->subtractArmyNum(stoi(troop));
    } while (p->getArmyNum() != 0);

    string input;
    bool done = false;

    //do while loop for other orders
    do {

        cout << "Issue Orders Stage 2: Other Orders \n" << endl;
        cout << "Here is the list of orders\n1.Advance\n2.Bomb\n3.Blockade\n4.Airlift\n5.Negotiate\n";
        cin >> input;
        //creating advance order given user input
        if (input == "Advance") {
            cout << "Preparation for advance order :\n";
            cout << "Which territory do you wish to deploy from? Please refer to your defendList above^^^" << endl;
            cin >> territory;
            cout << "Which territory do you wish to deploy to? Please refer to your attackList/defendList above^^^" << endl;
            cin >> target;
            cout << "how many troops do you wish to advance from " << territory << " to "<< target << "?\n";
            cin >> troop;

            //initiating deploy : need to figure out territory and target as parameter (cannot accept string)
            //auto* a = new Advance(p, territory, target, troop);
            //adding to OrderList of player
            //p.orderList.push_back(d)
        }

        //asking if user wants to issue more orders, will break out of while if not
        cout << "Do you still want to issue more orders? \n" << endl;
        cin >> input;
        if (input != "yes") {
            done = true;
        }
    } while (!done);

}

void HumanPlayerStrategy::toAttack(Map* m, Player* p) {

    vector<Territory*> attackList = p->getAttackList();

    for (int i = 0; i < attackList.size(); i++) {
        attackList.pop_back();
    }

    bool repeat;
    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == p->getName()) {
            for (int j = 0; j < m->getBorders()[i]->getEdges().size(); j++) {
                if (m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]->getPlayerName() != p->getName()) {
                    repeat = false;
                    for (int k = 0; k < attackList.size(); k++) {
                        if (attackList[k]->getCountryNum() == m->getBorders()[i]->getEdges()[j]) {
                            repeat = true;
                        }
                    }
                    if (!repeat) {
                        attackList.push_back(m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]);
                    }
                }
            }
        }
    }
}

void HumanPlayerStrategy::toDefend(Map* m, Player* p) {
    vector<Territory*> defendList = p->getDefendList();

    for (int i = 0; i < defendList.size(); i++) {
        defendList.pop_back();
    }

    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == p->getName()) {
            defendList.push_back(m->getTerritories()[i]);
        }
    }
}

/// <summary>
/// Aggressive
/// </summary>
void AggressivePlayerStrategy::issueOrder(Map* m, Player* p) {

}

void AggressivePlayerStrategy::toAttack(Map* m, Player* p) {
	
}

void AggressivePlayerStrategy::toDefend(Map* m, Player* p) {
	
}

/// <summary>
/// Benevolent
/// </summary>
void BenevolentPlayerStrategy::issueOrder(Map* m, Player* p) {
    p->getDefendList()[0];
}

void BenevolentPlayerStrategy::toAttack(Map* m, Player* p) {
    //Left empty on purpose
}

void BenevolentPlayerStrategy::toDefend(Map* m, Player* p) {
    for (int i = 0; i < p->getDefendList().size(); i++) {
        p->getDefendList().pop_back();
    }
    vector<Territory*> territories = m->getTerritories();
    Territory* weakest = nullptr;
    for (Territory* t : territories) {
        if (t->getPlayerName() == p->getName()) {
            if (weakest == nullptr || weakest->getArmy() > t->getArmy() ) {
                weakest = t;
            }
        }
    }
    p->getDefendList().push_back(weakest);
}

/// <summary>
/// Neutral
/// </summary>
void NeutralPlayerStrategy::issueOrder(Map* m, Player* p) {
    //Left empty on purpose
}

void NeutralPlayerStrategy::toAttack(Map* m, Player* p) {
    //Left empty on purpose
}

void NeutralPlayerStrategy::toDefend(Map* m, Player* p) {
    //Left empty on purpose
}

/// <summary>
/// Cheater
/// </summary>
void CheaterPlayerStrategy::issueOrder(Map* m, Player* p) {

}

void CheaterPlayerStrategy::toAttack(Map* m, Player* p) {
	
}

void CheaterPlayerStrategy::toDefend(Map* m, Player* p) {
    //left empty on purpose
}