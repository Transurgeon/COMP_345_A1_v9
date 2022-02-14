#include "../Header Files/Drivers.h"
#include "../Header Files/Map.h"

void mapMain() {
	
	MapLoader::loadMaps();
	MapLoader::showAllMaps();
}