#include "../Header Files/Drivers.h"
#include "../Header Files/Map.h"

void mapMain() {
	/*Map* test = new Map();
	//Borders* test2 = new Borders();
	test->addTerritory(new Territory(3,4,"w"));
	cout << *test;
	//cout << *test2;
	
	delete test;
	test = nullptr;
	//delete test2;
	//test2 = nullptr;
	*/

	MapLoader::readMapFile();
}