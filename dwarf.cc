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


// Dwarf doubles gold pickup
int Dwarf::pickGold(int gold) {
	return 2*gold;
}
