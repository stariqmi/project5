#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
using namespace std;
Character::Character(): gold(0) {
	type = "character";
	standingOn = "ground";
}

void Character::move(string direction){
	if(direction == "nw") {
		string originalType = grid->theGrid[x - 1][y - 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y - 1].notifyDisplay(*(grid->td));
		y--;
		x--;
	}

	if(direction == "sw") {
		string originalType = grid->theGrid[x + 1][y - 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y - 1].notifyDisplay(*(grid->td));
		y--;
		x++;
	}

	else if(direction == "ne") {
		string originalType = grid->theGrid[x - 1][y + 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y + 1].notifyDisplay(*(grid->td));
		y++;
		x--;
	}

	else if(direction == "se") {
		string originalType = grid->theGrid[x + 1][y + 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y + 1].notifyDisplay(*(grid->td));
		y++;
		x++;
	}

	else if(direction == "no") {
		string originalType = this->grid->theGrid[this->x - 1][this->y].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x - 1][y].notifyDisplay(*(grid->td));
		x--;
	}

	else if(direction == "so") {
		string originalType = this->grid->theGrid[this->x + 1][this->y].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x + 1][y].notifyDisplay(*(grid->td));
		x++;
	}

	else if(direction == "ea") {
		string originalType = this->grid->theGrid[this->x][this->y + 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x][y + 1].notifyDisplay(*(grid->td));
		y++;
	}

	else if(direction == "we") {
		string originalType = this->grid->theGrid[this->x][this->y - 1].thing->type; 
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
		grid->theGrid[x][y].notifyDisplay(*(grid->td));
		grid->theGrid[x][y - 1].notifyDisplay(*(grid->td));
		y--;
	}
}

// void Character::pickGold(string direction) {
// 	if(direction == "N") { 
// 		gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold; 
// 		delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
// 		grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
// 	}
// 	else if(direction == "S") {
// 		gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold; 
// 		delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
// 		grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
// 	}
// 	else if(direction == "E") {
// 		gold = gold + grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold; 
// 		delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
// 		grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
// 	}
// 	else if(direction == "W") {
// 		gold = gold + grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold; 
// 	  	delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
// 	  	grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
// 	}
// 	else if(direction == "NE") {
// 	 	gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold; 
// 		delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
// 		grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
// 	}
// 	else if(direction == "NW") {
// 		gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold; 
// 		delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
// 		grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
// 	}
// 	else if(direction == "SE") {
// 		gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold; 
// 		delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
// 		grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
// 	}
// 	else if(direction == "SW") {
// 		gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold; 
// 		delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
// 		grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);	  		  		  
// 	}
//}
Character::~Character() {}

