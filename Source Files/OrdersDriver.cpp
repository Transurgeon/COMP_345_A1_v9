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

    cout << endl;

    deployOrder->execute();

    advanceOrder->validate();
    advanceOrder->execute();

    bombOrder->validate();
    bombOrder->execute();

    blockadeOrder->validate();
    blockadeOrder->execute();

    airliftOrder->validate();
    airliftOrder->execute();

    negotiateOrder->validate();
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

    cout << "\nContents of list after deletion: \n"
        << list1 << endl;

    list1.move(1, 4);

    cout << "\nContents of list after move: \n"
        << list1 << endl;
}

