#include <iostream>
#include "troll.h"
#include "grid.h"
#include <string>
using namespace std;

Troll::Troll() {
	hp = 120;
	atk = 25;
	def = 15;
	isAttacked = false;
	type = "troll";
}

int Troll::getHealth() {
	return hp;
}

void Troll::setHealth(int h){
	hp = h; 
}


