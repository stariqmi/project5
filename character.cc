#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
#include <sstream>
#include <math.h>
#include "scoreboard.h"
using namespace std;

Character::Character(): gold(0), isMoved(false) {
	type = "character";
	standingOn = "ground";
	scoreboard = Scoreboard::getInstance();
}

string Character::move(string direction){
	bool move = false;
	string result = "";
	Coordinates* coords = grid->evalDirection(direction, x, y);
	
	// Player tries to move to empty space
	if(grid->theGrid[coords->x][coords->y].thing == NULL) {
		delete coords;
		return "empty";
	}


	string originalType = grid->theGrid[coords->x][coords->y].thing->type;
	Character* player = dynamic_cast<Character*>(grid->theGrid[x][y].thing);
	
	// Player tries to collect gold;
	if(originalType == "gold") {
		int originalGold = player->gold;
		Treasure* treasure = dynamic_cast<Treasure*>(grid->theGrid[coords->x][coords->y].thing);
		
		// Player tries to collect dragon horde
		if(treasure->treasureType == "dragonhorde") {
			DragonHorde* dragonhorde = dynamic_cast<DragonHorde*>(treasure);
			if(dragonhorde->giveGold() != 0) { 
				player->gold += player->pickGold(dragonhorde->giveGold());
				player->scoreboard->addScore(player->gold); 
			}
			else {
				result = "dragon";
			}
		}

		// Any other type of treasure
		else {
			player->gold += player->pickGold(treasure->giveGold()); 	
			//cout << player->scoreboard->score << endl;
			player->scoreboard->addScore(player->gold);		
		}
		if(originalGold != player->gold) {
			result = "gold";
			move = true;
		}
	}

	// Player moves to stairway
	else if(originalType == "stairway") {
		grid->level++;
		if(grid->level == 10) {
			result =  "finish";
			move = true;
		}
		else {
			result = "next";
		}
	}

	// Player tries to move over enemy or potion or wall
	else if(originalType != "ground" && originalType != "passage" && originalType != "door") {
		result = "invalid";
	}

	// Ground
	else {
		result = "move";
		move = true;
	}

	// Move player to new position, change display
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
	}
	delete coords;
	return result;	
}


int Character::attack(int i, int j) {
	Character* defender = dynamic_cast<Character*>(grid->theGrid[i][j].thing);
	int damage = ceil((100/(double)(100 + defender->def)) * atk);
	defender->hp -= damage;
	return damage;
}

void Character::usePotion(int i, int j) {
	Potion* potion = dynamic_cast<Potion*>(grid->theGrid[i][j].thing);
	if(potion->effect == "boost") {
		if(potion->effectOn == "health") { if(hp != 140) hp += potion->magnitude; }
		else if(potion->effectOn == "attack") atk += potion->magnitude; 
		else def += potion->magnitude;
	}
	else if(potion->effect == "wound") {
		if(potion->effectOn == "health") { if(hp != 0) hp -= potion->magnitude; }
		else if(potion->effectOn == "attack") { if(atk != 0) atk -= potion->magnitude; } 
		else { if(atk != 0) def -= potion->magnitude; }	
	}
	delete grid->theGrid[i][j].thing;
	grid->theGrid[i][j].setThing(new Ground);
	grid->theGrid[i][j].notifyDisplay(*(grid->td));
}


int Character::pickGold(int gold) {return 0;}

Character::~Character() {}

