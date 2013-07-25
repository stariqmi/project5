#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
#include <math.h>
using namespace std;


Character::Character(): gold(0) {
	type = "character";
	standingOn = "ground";
}

void Character::move(string direction){
	Coordinates* coords = grid->evalDirection(direction, x, y);
	string originalType = grid->theGrid[coords->x][coords->y].thing->type;
	delete grid->theGrid[coords->x][coords->y].thing;
	grid->theGrid[coords->x][coords->y].setThing(grid->theGrid[x][y].thing);
	Character* player = dynamic_cast<Character*>(grid->theGrid[x][y].thing);
	if(player->standingOn == "ground") {
		grid->theGrid[x][y].setThing(new Ground);
	}
	else if(player->standingOn == "door") {
		grid->theGrid[x][y].setThing(new Door);
	}
	else if(player->standingOn == "passage") {
		grid->theGrid[x][y].setThing(new Passage);
	}
	player->standingOn = originalType;
	grid->theGrid[coords->x][coords->y].isOccupied = true;
	grid->theGrid[x][y].isOccupied = false;
	grid->theGrid[x][y].notifyDisplay(*(grid->td));
	grid->theGrid[coords->x][coords->y].notifyDisplay(*(grid->td));
	if(direction == "nw") { y--; x--; }
	if(direction == "sw") { y--; x++; }

	else if(direction == "ne") { y++; x--; }

	else if(direction == "se") { y++; x++; }

	else if(direction == "no") { x--; }

	else if(direction == "so") { x++; }

	else if(direction == "ea") { y++; }

	else if(direction == "we") { y--; }
	//cout << dynamic_cast<Character*>(grid->theGrid[x][y].thing)->raceID << endl;
	if(originalType == "stairway") {
		grid->level++;
		if(grid->level == 2) {
			cout << "Congratulations! You have won, now piss off!" << endl;
		}
		else {
			grid->initializeFloor(dynamic_cast<Character*>(grid->theGrid[x][y].thing)->raceID);
		}
	}
	else {
		cout << *grid;
	}
}

int Character::getAtk() {
	return atk;
}
int Character::getDef() {
	return def;
}

void Character::attack(Coordinates* c) {}

void Character::attack(int i, int j) {
	cout << "Attacker - " << type << endl;
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	cout << "Defender - " << defender->type << endl;
	cout << "Def-hp (pre): " << defender->hp << endl;
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	cout << "Def-hp (post): " << defender->hp << endl;
}

void Character::usePotion(int i, int j) {}

Character::~Character() {}

