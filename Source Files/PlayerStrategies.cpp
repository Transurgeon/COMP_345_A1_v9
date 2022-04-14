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
    for (Territory* t : p->defendList) {
        cout << *t << endl;
    }
    cout << "\n\n\nEnemy territories to advance to:\n";
    for (Territory* t : p->attackList) {
        cout << *t << endl;
    }
     int armies = p->getArmyNum();
    //input variables : target is for advance
    string territory;
    string target;
    string troop;

    //do while loop for deploying phase

    cout << "You must deploy all reserve troops before advancing \n";
    string input;
    cout << "Are you done issuing orders? " << endl;
    cin >> input;
    while (input != "yes"){
        if (armies > 0) {
            cout << "Remaining troops: " << armies << "\n" << endl;
            cout << "Which territory do you wish to deploy to? Please refer to your defendList above^^^" << endl;
            cin >> territory;
            while (!checkNumber(territory) || stoi(territory) <= 0 || stoi(territory) > m->getTerritories().size()) {
                cout << "incorrect input! please make sure to write a whole number between 1 and " << m->getTerritories().size() << endl;
                cin >> territory;
            }

            cout << "how many troops do you want to place on " << m->getTerritories()[stoi(territory) - 1]->getName() << "?\n";
            cin >> troop;
            //copied from startup Phase
            while (!checkNumber(troop) || stoi(troop) < 0 || stoi(troop) > armies) {
                cout << "incorrect input! please make sure to write a whole number between 0 and " << armies << endl;
                cin >> troop;
            }

            //initiating deploy
            
            p->addOrder(new Deploy(p, m->getTerritories()[stoi(territory) - 1], stoi(troop)));
            armies -= stoi(troop);
        }
        else {
            //creating advance order given user input
            cout << "Preparation for advance order :\n";
            cout << "Which territory do you wish to deploy from? Please refer to your defendList above^^^" << endl;
            cin >> territory;
            while (!checkNumber(territory) || stoi(territory) <= 0 || stoi(territory) > m->getTerritories().size()) {
                cout << "incorrect input! please make sure to write a whole number between 1 and " << m->getTerritories().size() << endl;
                cin >> territory;
            }

            cout << "Which territory do you wish to deploy to? Please refer to your attackList/defendList above^^^" << endl;
            cin >> target;
            while (!checkNumber(target) || stoi(target) <= 0 || stoi(target) > m->getTerritories().size()) {
                cout << "incorrect input! please make sure to write a whole number between 1 and " << m->getTerritories().size() << endl;
                cin >> target;
            }

            cout << "how many troops do you wish to advance from " << territory << " to " << target << "?\n";
            cin >> troop;
            while (!checkNumber(troop) || stoi(troop) < 0 || stoi(troop) > p->getArmyNum()) {
                cout << "incorrect input! please make sure to write a whole number between 0 and " << p->getArmyNum() << endl;
                cin >> troop;
            }
            //initiating deploy
            p->addOrder(new Advance(p, m->getTerritories()[stoi(territory) - 1], m->getTerritories()[stoi(target) - 1], stoi(troop)));
               
        }
        //asking if user wants to issue more orders, will break out of while if not

        cout << "Are you done issuing orders ? \n" << endl;
        cin >> input;
    }
}

void HumanPlayerStrategy::toAttack(Map* m, Player* p) {


    for (int i = 0; i < p->attackList.size(); i++) {
        p->attackList.pop_back();
    }

    bool repeat;
    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == p->getName()) {
            for (int j = 0; j < m->getBorders()[i]->getEdges().size(); j++) {
                if (m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]->getPlayerName() != p->getName()) {
                    repeat = false;
                    for (int k = 0; k < p->attackList.size(); k++) {
                        if (p->attackList[k]->getCountryNum() == m->getBorders()[i]->getEdges()[j]) {
                            repeat = true;
                        }
                    }
                    if (!repeat) {
                        p->attackList.push_back(m->getTerritories()[m->getBorders()[i]->getEdges()[j] - 1]);
                    }
                }
            }
        }
    }
}

void HumanPlayerStrategy::toDefend(Map* m, Player* p) {

    for (int i = 0; i < p->defendList.size(); i++) {
        p->defendList.pop_back();
    }

    for (int i = 0; i < m->getTerritories().size(); i++) {
        if (m->getTerritories()[i]->getPlayerName() == p->getName()) {
            p->defendList.push_back(m->getTerritories()[i]);
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
    
    //initiating deploy 
        auto* d = new Deploy(p, p->defendList[0], p->getArmyNum());
       
        p->addOrder(d);
}

void BenevolentPlayerStrategy::toAttack(Map* m, Player* p) {
    //Left empty on purpose
}

void BenevolentPlayerStrategy::toDefend(Map* m, Player* p) {
    for (int i = 0; i < p->defendList.size(); i++) {
        p->defendList.pop_back();
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
    p->defendList.push_back(weakest);
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

