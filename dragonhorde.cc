#include "dragonhorde.h"
#include <iostream>

using namespace std;

DragonHorde::DragonHorde() : Treasure(6, "dragonhorde") {}

int DragonHorde::giveGold() {
	//cout << "in dh give gold" << endl; 
	if(protector->thing->type == "ground" || protector->thing->type == "gold" || protector->thing->type == "character") {
		return gold;
	}
	else {
		return 0;
	}
}