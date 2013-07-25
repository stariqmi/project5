#include <iostream>
#include "phoenix.h"
#include "grid.h"
#include <string>
using namespace std;

Phoenix::Phoenix() {
	hp = 50;
	atk = 35;
	def = 20;
	isAttacked = false;
	type = "phoenix";
}

int Phoenix::getHealth() {
	return hp;
}

void Phoenix::setHealth(int h){
	hp = h; 
}

