#include <iostream>
#include "orc.h"
#include <string>
using namespace std;

Orc::Orc() {
	this->hp = 180;
	this->atk = 30;
	this->def = 25;
	raceID = 'o';
}


int Orc::getHealth() {
	return hp;
}

void Orc::setHealth(int h){
	hp = h; 
}


void Orc::attack(int x, int y) {}
