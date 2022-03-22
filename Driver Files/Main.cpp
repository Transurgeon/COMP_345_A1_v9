#include "../Header Files/Drivers.h"

int main() {
	
	switch (1) {
	case 1:
		mapMain();
		break;
	case 2:
		playerMain();
		break;
	case 3:
		ordersMain();
		break;
	case 4:
		cardsMain();
		break;
	case 5:
		gameEngineMain();
		break;
	case 6:
		commandProcessingMain();
	}
	return 0;
}