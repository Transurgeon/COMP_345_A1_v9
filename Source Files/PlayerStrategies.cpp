#include "../Header Files/Player.h"
#include "../Header Files/PlayerStrategies.h"


/// <summary>
/// Human
/// </summary>
void HumanPlayerStrategy::issueOrder(Map* m, Player* p) {


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

}

void BenevolentPlayerStrategy::toAttack(Map* m, Player* p) {
	
}

void BenevolentPlayerStrategy::toDefend(Map* m, Player* p) {
	
}

/// <summary>
/// Neutral
/// </summary>
void NeutralPlayerStrategy::issueOrder(Map* m, Player* p) {

}

void NeutralPlayerStrategy::toAttack(Map* m, Player* p) {
	
}

void NeutralPlayerStrategy::toDefend(Map* m, Player* p) {
	
}

/// <summary>
/// Cheater
/// </summary>
void CheaterPlayerStrategy::issueOrder(Map* m, Player* p) {

}

void CheaterPlayerStrategy::toAttack(Map* m, Player* p) {
	
}

void CheaterPlayerStrategy::toDefend(Map* m, Player* p) {
}