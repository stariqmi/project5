#include <iostream>
#include "dragon.h"
#include "grid.h"
#include <string>
using namespace std;

Dragon::Dragon() {
	hp = 150;
	atk = 20;
	def = 20;
	isAttacked = false;
	type = "dragon";
}

int Dragon::getHealth() {
	return hp;
}

void Dragon::setHealth(int h){
	hp = h; 
}

