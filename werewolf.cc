#include <iostream>
#include "werewolf.h"
#include "grid.h"
#include <string>
using namespace std;

Werewolf::Werewolf() {
	hp = 120;
	atk = 30;
	def = 5;
	isAttacked = false;
	type = "werewolf";
	raceID = 'W';
}

int Werewolf::getHealth() {
	return hp;
}

void Werewolf::setHealth(int h){
	hp = h; 
}

