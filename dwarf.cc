#include <iostream>
#include "dwarf.h"
#include "grid.h"
#include <string>
using namespace std;

Dwarf::Dwarf() {
	hp = 100;
	atk = 20;
	def = 30;
	raceID = 'd';
}

int Dwarf::getHealth() {
	return hp;
}

void Dwarf::setHealth(int h){
	hp = h; 
}

void Dwarf::usePotion(int i, int j) {
	Potion* potion = dynamic_cast<Potion*>(grid->theGrid[i][j].thing);
	cout << "Potion Effect: " << potion->effect << endl;
	cout << "Effect on: " << potion->effectOn << endl;
	cout << "Magnitude: " << potion->magnitude << endl;
	cout << endl;
	cout << "Your health (pre) : " << hp << endl;
	cout << "Your attack (pre) :" << atk << endl;
	cout << "Your defence (pre) :" << def << endl;
	if(potion->effect == "boost") {
		if(potion->effectOn == "health") { if(hp != 100) hp += potion->magnitude; }
		else if(potion->effectOn == "attack") atk += potion->magnitude; 
		else def += potion->magnitude;
	}
	else if(potion->effect == "wound") {
		if(potion->effectOn == "health") { if(hp != 0) hp -= potion->magnitude; }
		else if(potion->effectOn == "attack") { if(atk != 0) atk -= potion->magnitude; } 
		else { if(atk != 0) def -= potion->magnitude; }	
	}
	cout << endl;
	cout << "Your health (post) : " << hp << endl;
	cout << "Your attack (post) :" << atk << endl;
	cout << "Your defence (post) :" << def << endl;
	delete grid->theGrid[i][j].thing;
	grid->theGrid[i][j].setThing(new Ground);
	grid->theGrid[i][j].notifyDisplay(*(grid->td));
}

int Dwarf::pickGold(int gold) {
	return 2*gold;
}
