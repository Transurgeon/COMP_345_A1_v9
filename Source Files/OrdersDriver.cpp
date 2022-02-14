#include "../Header Files/Orders.h"
#include "../Header Files/Drivers.h"
#include <iostream>

void ordersMain() {

    Deploy* deployOrder = new Deploy;
    Advance* advanceOrder = new Advance;
    Bomb* bombOrder = new Bomb;
    Blockade* blockadeOrder = new Blockade;
    AirLift* airliftOrder = new AirLift;
    Negotiate* negotiateOrder = new Negotiate;

    cout << "\nDeploy is a valid Order: " << deployOrder->validate() << endl;
    deployOrder->execute();

    cout << "\nAdvance is a valid Order: " << advanceOrder->validate() << endl;
    advanceOrder->execute();

    cout << "\nBomb is a valid Order: " << bombOrder->validate() << endl;
    bombOrder->execute();

    cout << "\nBlockade is a valid Order: " << blockadeOrder->validate() << endl;
    blockadeOrder->execute();

    cout << "\nAirlift is a valid Order: " << airliftOrder->validate() << endl;
    airliftOrder->execute();

    cout << "\nNegotiate is a valid Order: " << negotiateOrder->validate() << endl;
    negotiateOrder->execute();

    OrdersList list1;

    list1.add(deployOrder);
    list1.add(advanceOrder);
    list1.add(bombOrder);
    list1.add(blockadeOrder);
    list1.add(airliftOrder);
    list1.add(negotiateOrder);

    cout << "\nContents of list: \n"
        << list1 << endl;

    list1.remove(1);

    cout << "Contents of list after deletion: \n"
        << list1 << endl;

    list1.move(1, 4);

    cout << "Contents of list after move: \n"
        << list1 << endl;
}

