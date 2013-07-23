#include <iostream>
#include "dwarf.h"
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

void Dwarf::usePotion(int i, int j) {}

void Dwarf::attack(int x, int y) {}
