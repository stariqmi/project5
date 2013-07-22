#include <iostream>
#include "character.h"
#include "grid.h"
#include <string>
using namespace std;
Character::Character(): gold(0) {
	this->type = "character";
}

void Character::move(string direction){
	Thing* original;
	Thing* next;
	if(direction == "n") {
		next = this->grid->theGrid[this->x - 1][this->y].thing;
		original = this->grid->theGrid[this->x][this->y].thing;
		this->grid->theGrid[this->x][this->y].thing = next;
		this->grid->theGrid[this->x - 1][this->y].thing = original;
		this->grid->theGrid[this->x][this->y].notifyDisplay(*(this->grid->td));
		this->grid->theGrid[this->x - 1][this->y].notifyDisplay(*(this->grid->td));
		this->x--;
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

