#include "../Header Files/Player.h"
#include "../Header Files/PlayerStrategies.h"


/// <summary>
/// HumanPlayer
/// </summary>
void HumanPlayerStrategy::issueOrder(Map* m) {

}

vector<Territory*> HumanPlayerStrategy::toAttack(Map* m) {
	return vector<Territory*>();
}

vector<Territory*> HumanPlayerStrategy::toDefend(Map* m) {
	return vector<Territory*>();
}

/// <summary>
/// Aggressive
/// </summary>
void AggressivePlayerStrategy::issueOrder(Map* m) {

}

vector<Territory*> AggressivePlayerStrategy::toAttack(Map* m) {
	return vector<Territory*>();
}

vector<Territory*> AggressivePlayerStrategy::toDefend(Map* m) {
	return vector<Territory*>();
}

/// <summary>
/// Benevolent
/// </summary>
void BenevolentPlayerStrategy::issueOrder(Map* m) {

}

vector<Territory*> BenevolentPlayerStrategy::toAttack(Map* m) {
	return vector<Territory*>();
}

vector<Territory*> BenevolentPlayerStrategy::toDefend(Map* m) {
	return vector<Territory*>();
}

/// <summary>
/// Neutral
/// </summary>
void NeutralPlayerStrategy::issueOrder(Map* m) {

}

vector<Territory*> NeutralPlayerStrategy::toAttack(Map* m) {
	return vector<Territory*>();
}

vector<Territory*> NeutralPlayerStrategy::toDefend(Map* m) {
	return vector<Territory*>();
}

/// <summary>
/// Cheater
/// </summary>
void CheaterPlayerStrategy::issueOrder(Map* m) {

}

vector<Territory*> CheaterPlayerStrategy::toAttack(Map* m) {
	return vector<Territory*>();
}

vector<Territory*> CheaterPlayerStrategy::toDefend(Map* m) {
	return vector<Territory*>();
}