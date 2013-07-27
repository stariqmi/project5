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
		delete coords;
		return "empty";
	}
	string originalType = grid->theGrid[coords->x][coords->y].thing->type;
	Character* player = dynamic_cast<Character*>(grid->theGrid[x][y].thing);
	
	if(originalType == "gold") {
		int originalGold = player->gold;
		Treasure* treasure = dynamic_cast<Treasure*>(grid->theGrid[coords->x][coords->y].thing);
		if(treasure->treasureType == "dragonhorde") {
			DragonHorde* dragonhorde = dynamic_cast<DragonHorde*>(treasure);
			if(dragonhorde->giveGold() != 0) { 
				player->gold += player->pickGold(dragonhorde->giveGold()); 
			}
			else {
				result = "dragon";
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
		if(grid->level == 10) {
			result =  "finish";
			move = true;
		}
		else {
			//cout << "in next" << endl;
			result = "next";
			// cout << result << endl;
			// move = true;
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
			grid->theGrid[x][y].isOccupied = true;
		}
		else if(player->standingOn == "passage") {
			grid->theGrid[x][y].setThing(new Passage);
			grid->theGrid[x][y].isOccupied = true;
		}
		else {
			grid->theGrid[x][y].setThing(new Ground);
			grid->theGrid[x][y].isOccupied = false;
		}

		player->standingOn = originalType;
		grid->theGrid[coords->x][coords->y].isOccupied = true;
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

int Character::attack(int i, int j) {
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	return damage;
}

void Character::usePotion(int i, int j) {}

int Character::pickGold(int gold) {return 0;}

Character::~Character() {}

