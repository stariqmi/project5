#include <iostream>
#include "human.h"
#include <string>
using namespace std;

Human::Human() {
	hp = 140;
	atk = 20;
	def = 20;
	raceID = 'h';
}

int Human::getHealth() {
	return hp;
}

void Human::setHealth(int h){
	hp = h; 
}

