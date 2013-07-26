#include <iostream>
#include "elf.h"
#include "grid.h"
#include <string>
using namespace std;

Elf::Elf()  {
	hp = 140;
	atk = 30;
	def = 10;
	raceID = 'e';
}
int Elf::getHealth() {
	return hp;
}

void Elf::setHealth(int h){
	hp = h; 
}

void Elf::usePotion(int i, int j) {
	Potion* potion = dynamic_cast<Potion*>(grid->theGrid[i][j].thing);
	cout << "Potion Effect: " << potion->effect << endl;
	cout << "Effect on: " << potion->effectOn << endl;
	cout << "Magnitude: " << potion->magnitude << endl;
	cout << endl;
	cout << "Your health (pre) : " << hp << endl;
	cout << "Your attack (pre) :" << atk << endl;
	cout << "Your defence (pre) :" << def << endl;
	if(potion->effectOn == "health") { if(hp != 140) hp += potion->magnitude; }
	else if(potion->effectOn == "attack") atk += potion->magnitude; 
	else def += potion->magnitude;
	cout << endl;
	cout << "Your health (post) : " << hp << endl;
	cout << "Your attack (post) :" << atk << endl;
	cout << "Your defence (post) :" << def << endl;
	delete grid->theGrid[i][j].thing;
	grid->theGrid[i][j].setThing(new Ground);
	grid->theGrid[i][j].notifyDisplay(*(grid->td));
}

int Elf::pickGold(int gold) {
	return gold;
}