#include <iostream>
#include "elf.h"
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

void Elf::attack(int x, int y) {}
