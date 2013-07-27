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
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	if(defender->gold > 0) {
		defender->gold -= 1;
		gold += 1;
	}
	return damage;
}

