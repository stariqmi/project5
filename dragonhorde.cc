#include "dragonhorde.h"
#include <iostream>

using namespace std;

DragonHorde::DragonHorde() : Treasure(6, "dragonhorde") {}

int DragonHorde::giveGold() { 
	if(protector->type == "ground" || protector->type == "gold") {
		return gold;
	}
	else {
		cout << "Kill the damn dragon you coward!" << endl;
		return 0;
	}
}