#include <iostream>
#include "goblin.h"
#include "grid.h"
#include <string>
#include <math.h>

using namespace std;

Goblin::Goblin() {
	gold = 0;
	hp = 70;
	atk = 5;
	def = 10;
	isAttacked = false;
	type = "goblin";
	raceID = 'N';
}

int Goblin::getHealth() {
	return hp;
}

void Goblin::setHealth(int h){
	hp = h; 
}

// Goblin attacks and steals gold.
int Goblin::attack(int i, int j) {
	//cout << "Attacker - " << type << endl;
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	//cout << "Defender - " << defender->type << endl;
	//cout << "Def-hp (pre): " << defender->hp << endl;
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	//cout << "Def-hp (post): " << defender->hp << endl;
	if(defender->gold > 0) {
		defender->gold -= 1;
		gold += 1;
	}
	return damage;
}

