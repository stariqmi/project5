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


// Elf converts negative potions to positive potions
void Elf::usePotion(int i, int j) {
	Potion* potion = dynamic_cast<Potion*>(grid->theGrid[i][j].thing);
	if(potion->effectOn == "health") { if(hp != 140) hp += potion->magnitude; }
	else if(potion->effectOn == "attack") atk += potion->magnitude; 
	else def += potion->magnitude;
	delete grid->theGrid[i][j].thing;
	grid->theGrid[i][j].setThing(new Ground);
	grid->theGrid[i][j].notifyDisplay(*(grid->td));
}

int Elf::pickGold(int gold) {
	return gold;
}