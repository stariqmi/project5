#include <iostream>
#include "human.h"
#include <string>
using namespace std;

Human::Human() {
	hp = 140;
	atk = 20;
	def = 20;
}

int Human::getHealth() {
	return hp;
}

void Human::setHealth(int h){
	hp = h; 
}

void Human::attack(int x, int y) {}

Human::~Human() {}
/*
void Human::pickGold(string direction){
switch(direction)	{
	case "N": gold = gold + grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
			  break;
	case "S": gold = gold + grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
			  break;
	case "E": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
			  break;		 		 
	case "W": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
			  break;
	case "NE": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
			  break;			  
	case "NW": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
			  break;
	case "SE": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
			  break;
	case "SW": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);
			  break;		  		  		  
	}
}
*/
