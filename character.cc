#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

Character::Character(): gold(0), isMoved(false) {
	type = "character";
	standingOn = "ground";
}

string Character::move(string direction){
	bool move = false;
	string result = "";
	Coordinates* coords = grid->evalDirection(direction, x, y);
	if(grid->theGrid[coords->x][coords->y].thing == NULL) {
		return "empty";
	}
	string originalType = grid->theGrid[coords->x][coords->y].thing->type;
	Character* player = dynamic_cast<Character*>(grid->theGrid[x][y].thing);
	
	if(originalType == "gold") {
		int originalGold = player->gold;
		//cout << player->gold << endl;
		Treasure* treasure = dynamic_cast<Treasure*>(grid->theGrid[coords->x][coords->y].thing);
		if(treasure->treasureType == "dragonhorde") {
			DragonHorde* dragonhorde = dynamic_cast<DragonHorde*>(treasure);
			if(dragonhorde->giveGold() != 0) { 
				player->gold += player->pickGold(dragonhorde->giveGold()); 
			}
		}
		else {
			player->gold += player->pickGold(treasure->giveGold()); 	
		}
		//cout << player->gold << endl;
		if(originalGold != player->gold) {
			result = "gold";
			move = true;
		}
	}

	else if(originalType == "stairway") {
		grid->level++;
		if(grid->level == 3) {
			result =  "finish";
			move = true;
		}
		else {
			result = "next";
			move = true;
			grid->initializeFloor(dynamic_cast<Character*>(grid->theGrid[x][y].thing)->raceID);
		}
	}

	else if(originalType != "ground" && originalType != "passage" && originalType != "door") {
		result = "invalid";
	}

	else {
		result = "move";
		move = true;
	}

	if(move) {
		delete grid->theGrid[coords->x][coords->y].thing;
		grid->theGrid[coords->x][coords->y].setThing(grid->theGrid[x][y].thing);
		if(player->standingOn == "door") {
			grid->theGrid[x][y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			grid->theGrid[x][y].setThing(new Passage);
		}
		else {
			grid->theGrid[x][y].setThing(new Ground);
		}

		player->standingOn = originalType;
		grid->theGrid[coords->x][coords->y].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[coords->x][coords->y].notifyDisplay(*(grid->td));
		if(direction == "nw") { y--; x--; }
		else if(direction == "sw") { y--; x++; }
		else if(direction == "ne") { y++; x--; }
		else if(direction == "se") { y++; x++; }
		else if(direction == "no") { x--; }
		else if(direction == "so") { x++; }
		else if(direction == "ea") { y++; }
		else if(direction == "we") { y--; }
		//cout << dynamic_cast<Character*>(grid->theGrid[x][y].thing)->raceID << endl;
	}
	delete coords;
	return result;
	
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

int Character::pickGold(int gold) {return 0;}

Character::~Character() {}

