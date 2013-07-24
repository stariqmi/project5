#include <iostream>
#include "goblin.h"
#include "grid.h"
#include <string>
using namespace std;

Goblin::Goblin() {
	hp = 70;
	atk = 5;
	def = 10;
	isAttacked = false;
	type = "goblin";
}

int Goblin::getHealth() {
	return hp;
}

void Goblin::setHealth(int h){
	hp = h; 
}

