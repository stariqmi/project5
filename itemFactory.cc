#include "itemFactory.h"
#include <string>

using namespace std;

ItemFactory::ItemFactory() {}
ItemFactory::~ItemFactory() {}

Item* ItemFactory::makeItem(string type) {
	Item* item;
	if(type == "BA") {
		item = new BoostAttack;
	}
	else if(type == "WA") {
		item = new WoundAttack;
	}
	else if(type == "BD") {
		item = new BoostDefence;
	}
	else if(type == "WD") {
		item = new WoundDefence;
	}
	else if(type == "RH") {
		item = new BoostHealth;
	}
	else if(type == "PH") {
		item = new PoisonHealth;
	}
	else if(type == "MH") {
		item = new MerchantHorde;
	}
	else if(type == "DH") {
		item = new DragonHorde;
	}
	else if(type == "SH") {
		item = new SmallHorde;
	}
	else if(type == "NG") {
		item = new NormalGold;
	}
	return item;
}