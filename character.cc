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
	string going_to;
	if(direction == "nw") {
		string originalType = grid->theGrid[x - 1][y - 1].thing->type; 
		going_to = originalType;
		delete grid->theGrid[x - 1][y - 1].thing;
		grid->theGrid[x - 1][y - 1].setThing(grid->theGrid[x][y].thing);
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
		grid->theGrid[x - 1][y - 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y - 1].notifyDisplay(*(grid->td));
		y--;
		x--;
	}

	if(direction == "sw") {
		string originalType = grid->theGrid[x + 1][y - 1].thing->type; 
		going_to = originalType;
		delete grid->theGrid[x + 1][y - 1].thing;
		grid->theGrid[x + 1][y - 1].setThing(grid->theGrid[x][y].thing);
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
		grid->theGrid[x + 1][y - 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y - 1].notifyDisplay(*(grid->td));
		y--;
		x++;
	}

	else if(direction == "ne") {
		string originalType = grid->theGrid[x - 1][y + 1].thing->type; 
		going_to = originalType;
		delete grid->theGrid[x - 1][y + 1].thing;
		grid->theGrid[x - 1][y + 1].setThing(grid->theGrid[x][y].thing);
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
		grid->theGrid[x - 1][y + 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y + 1].notifyDisplay(*(grid->td));
		y++;
		x--;
	}

	else if(direction == "se") {
		string originalType = grid->theGrid[x + 1][y + 1].thing->type; 
		going_to = originalType;
		delete grid->theGrid[x + 1][y + 1].thing;
		grid->theGrid[x + 1][y + 1].setThing(grid->theGrid[x][y].thing);
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
		grid->theGrid[x + 1][y + 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y + 1].notifyDisplay(*(grid->td));
		y++;
		x++;
	}

	else if(direction == "no") {
		string originalType = this->grid->theGrid[this->x - 1][this->y].thing->type; 
		going_to = originalType;
		delete this->grid->theGrid[this->x - 1][this->y].thing;
		this->grid->theGrid[this->x - 1][this->y].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
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
		grid->theGrid[x - 1][y].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y].notifyDisplay(*(grid->td));
		x--;
	}

	else if(direction == "so") {
		string originalType = this->grid->theGrid[this->x + 1][this->y].thing->type; 
		going_to = originalType;
		delete this->grid->theGrid[this->x + 1][this->y].thing;
		this->grid->theGrid[this->x + 1][this->y].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
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
		grid->theGrid[x + 1][y].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y].notifyDisplay(*(grid->td));
		x++;
	}

	else if(direction == "ea") {
		string originalType = this->grid->theGrid[this->x][this->y + 1].thing->type; 
		going_to = originalType;
		delete this->grid->theGrid[this->x][this->y + 1].thing;
		this->grid->theGrid[this->x][this->y + 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);if(player->standingOn == "ground") {
			grid->theGrid[x][y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			grid->theGrid[x][y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			grid->theGrid[x][y].setThing(new Passage);
		}
		player->standingOn = originalType;
		grid->theGrid[x][y + 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x][y + 1].notifyDisplay(*(grid->td));
		y++;
	}

	else if(direction == "we") {
		string originalType = this->grid->theGrid[this->x][this->y - 1].thing->type; 
		going_to = originalType;
		delete this->grid->theGrid[this->x][this->y - 1].thing;
		this->grid->theGrid[this->x][this->y - 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
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
		grid->theGrid[x][y - 1].isOccupied = true;
		grid->theGrid[x][y].isOccupied = false;
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x][y - 1].notifyDisplay(*(grid->td));
		y--;
	}
	//cout << dynamic_cast<Character*>(grid->theGrid[x][y].thing)->raceID << endl;
	if(going_to == "stairway") {
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


void Character::attack(Coordinates *c){
	
		LivingThing* defender;
		cout << "check 1" << endl;
		cout << c->x << "," << c->y << endl;
		cout << grid->theGrid[c->x][c->y].thing->type << endl; 
		defender = dynamic_cast<LivingThing*>(grid->theGrid[c->x][c->y].thing);
		//cout << x <<","<< y << endl; 
	 	def = defender->getDef();
	 	// cout << "defense points :"<< def << endl;
	 	// cout << "atk points :" << atk << endl;
		int damage = 50; //((100/(100 + def)) * atk);
		cout << "damage :" << damage << endl; 
		int h = (getHealth() - damage);
		defender->setHealth(h);
		//cout << defender->getHealth() << endl;
	 }
	 // if(direction == "so") {
		// LivingThing* defender;
		// cout << x <<"," << y << endl;
		// // cout << "fdsf" << endl;
		//  defender = dynamic_cast<LivingThing*>(grid->theGrid[x + 1][y].thing);
	 // 	def = defender->getDef();
	 // 	// cout << "defense points :"<< def << endl;
	 // 	// cout << "atk points :" << atk << endl;
		// int damage = ceil((100/(100 + def)) * atk);
		// cout << "damage :" << damage << endl; 
		// int h = (getHealth() - damage);
		// defender->setHealth(h);
		// //cout << defender->getHealth() << endl;
	 // }


void Character::usePotion(int i, int j) {}

Character::~Character() {}

