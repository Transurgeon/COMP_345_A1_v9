#include "../Header Files/Drivers.h"
#include "../Header Files/Map.h"


void mapMain() {

	Map* m = MapLoader::addMap("brasil.map");
	if(m->isAdjacentTerritory(m->getTerritories()[0], m->getTerritories()[1]))
		cout << "bazinga";
}

