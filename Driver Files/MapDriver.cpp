#include "../Header Files/Drivers.h"
#include "../Header Files/Map.h"


void mapMain() {

	Map* m = MapLoader::addMap("brasil.map");
	m->printMap();
}

