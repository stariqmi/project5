#include <iostream>
#include "vampire.h"
#include "grid.h"
#include <string>
#include <math.h>

using namespace std;

Vampire::Vampire() {
	hp = 50;
	atk = 25;
	def = 25;
	isAttacked = false;
	type = "vampire";
	raceID = 'V';
}

int Vampire::getHealth() {
	return hp;
}

void Vampire::setHealth(int h){
	hp = h; 
}

int Vampire::attack(int i, int j) {
	cout << "Attacker - " << type << endl;
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	cout << "Defender - " << defender->type << endl;
	cout << "Def-hp (pre): " << defender->hp << endl;
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	cout << "Def-hp (post): " << defender->hp << endl;
	defender->hp -= 10;
	hp += 10;
	return damage;
}