#include <iostream>
#include "vampire.h"
#include "grid.h"
#include <string>
using namespace std;

Vampire::Vampire() {
	hp = 50;
	atk = 25;
	def = 25;
	isAttacked = false;
	type = "vampire";
}

int Vampire::getHealth() {
	return hp;
}

void Vampire::setHealth(int h){
	hp = h; 
}
