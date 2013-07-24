#include <iostream>
#include "merchant.h"
#include "grid.h"
#include <string>
using namespace std;

Merchant::Merchant() {
	hp = 30;
	atk = 70;
	def = 5;
	isAttacked = false;
	type = "merchant";
}

int Merchant::getHealth() {
	return hp;
}

void Merchant::setHealth(int h){
	hp = h; 
}

bool Merchant::isHostile = true;

