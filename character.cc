#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
using namespace std;
Character::Character(): gold(0) {
	this->type = "character";
	this->standingOn = "ground";
}

void Character::move(string direction){
	if(direction == "nw") {
		string originalType = this->grid->theGrid[this->x - 1][this->y - 1].thing->type; 
		delete this->grid->theGrid[this->x - 1][this->y - 1].thing;
		this->grid->theGrid[this->x - 1][this->y - 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x - 1][this->y - 1].notifyDisplay(*(this->grid->td));
		this->y--;
		this->x--;
	}

	if(direction == "sw") {
		string originalType = this->grid->theGrid[this->x + 1][this->y - 1].thing->type; 
		delete this->grid->theGrid[this->x + 1][this->y - 1].thing;
		this->grid->theGrid[this->x + 1][this->y - 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x + 1][this->y - 1].notifyDisplay(*(this->grid->td));
		this->y--;
		this->x++;
	}

	else if(direction == "ne") {
		string originalType = this->grid->theGrid[this->x - 1][this->y + 1].thing->type; 
		delete this->grid->theGrid[this->x - 1][this->y + 1].thing;
		this->grid->theGrid[this->x - 1][this->y + 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x - 1][this->y + 1].notifyDisplay(*(this->grid->td));
		this->y++;
		this->x--;
	}

	else if(direction == "se") {
		string originalType = this->grid->theGrid[this->x + 1][this->y + 1].thing->type; 
		delete this->grid->theGrid[this->x + 1][this->y + 1].thing;
		this->grid->theGrid[this->x + 1][this->y + 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x + 1][this->y + 1].notifyDisplay(*(this->grid->td));
		this->y++;
		this->x++;
	}

	else if(direction == "n") {
		string originalType = this->grid->theGrid[this->x - 1][this->y].thing->type; 
		delete this->grid->theGrid[this->x - 1][this->y].thing;
		this->grid->theGrid[this->x - 1][this->y].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x - 1][this->y].notifyDisplay(*(this->grid->td));
		this->x--;
	}

	else if(direction == "s") {
		string originalType = this->grid->theGrid[this->x + 1][this->y].thing->type; 
		delete this->grid->theGrid[this->x + 1][this->y].thing;
		this->grid->theGrid[this->x + 1][this->y].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x + 1][this->y].notifyDisplay(*(this->grid->td));
		this->x++;
	}

	else if(direction == "e") {
		string originalType = this->grid->theGrid[this->x][this->y + 1].thing->type; 
		delete this->grid->theGrid[this->x][this->y + 1].thing;
		this->grid->theGrid[this->x][this->y + 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x][this->y + 1].notifyDisplay(*(this->grid->td));
		this->y++;
	}

	else if(direction == "w") {
		string originalType = this->grid->theGrid[this->x][this->y - 1].thing->type; 
		delete this->grid->theGrid[this->x][this->y - 1].thing;
		this->grid->theGrid[this->x][this->y - 1].setThing(this->grid->theGrid[this->x][this->y].thing);
		Character* player = dynamic_cast<Character*>(this->grid->theGrid[this->x][this->y].thing);
		if(player->standingOn == "ground") {
			this->grid->theGrid[this->x][this->y].setThing(new Ground);
		}
		else if(player->standingOn == "door") {
			this->grid->theGrid[this->x][this->y].setThing(new Door);
		}
		else if(player->standingOn == "passage") {
			this->grid->theGrid[this->x][this->y].setThing(new Passage);
		}
		player->standingOn = originalType;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x][this->y - 1].notifyDisplay(*(this->grid->td));
		this->y--;
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

