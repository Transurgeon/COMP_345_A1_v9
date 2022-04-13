#include "../Header Files/Player.h"
#include "../Header Files/PlayerStrategies.h"


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

    /*for (int i = 0; i < playerList.size(); i++) {
        cout << "Issue Orders Stage 1: Deploying \n" << endl;
    }

    string input = "";
    for (int i = 0; i < playerList.size(); i++) {
        cout << "Issue Orders Stage 2: Other Orders \n" << endl;
        cout << "Here is the list of orders\n1.Advance\n2.Bomb\n3.Blockade\n4.Airlift\n5.Negotiate\n";
        cin >> input;
    if (input == "Advance") {
        cout << "Preparation for advance order :\n";
        }

    }

    string buffer;
    vector<Territory*> list;
    for (int i = 0; i < playerList.size(); i++) {
        cout << playerList[i]->getName() << " has " <<playerList[i]->getArmyNum() << " troops in reserve.\n";
        cout << "Territories to attack:\n";

        list = playerList[i]->toAttack(currentMap);
        for (int j = 0; j < list.size(); j++) {
            cout << *list[j] << endl;
        }


        cout << "\n\nTerritories to defend: \n";

        list = playerList[i]->toDefend(currentMap);
        for (int j = 0; j < list.size(); j++) {
            cout << *list[j] << endl;
        }


        cin >> buffer;

    }*/

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