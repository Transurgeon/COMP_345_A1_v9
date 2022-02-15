#include "../Header Files/Drivers.h"
#include "../Header Files/Map.h"


void mapMain() {
	MapLoader::addMap();
	MapLoader::addMap();
	MapLoader::validateMaps();
	
	MapLoader::showAllMaps();
	MapLoader::deleteAllMaps();
	/*
	vector<Map*> test = {new Map(),new Map()};

	test.erase(test.begin());
	for (Map* i : test) {
		cout << *i << endl;
	}

	cout << test.size();
	*/
}

