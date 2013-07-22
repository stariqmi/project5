#include <iostream>
#include "dwarf.h"
#include <string>
using namespace std;

Dwarf::Dwarf() {
	hp = 100;
	atk = 20;
	def = 30;
}

// void Dwarf::pickGold(string direction){
// switch(direction)	{
// 	case "N": gold = 2 * (grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
// 			  break;
// 	case "S": gold = 2 * (grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
// 			  break;
// 	case "E": gold = 2 * (grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold); 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
// 			  break;		 		 
// 	case "W": gold = 2 * (grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold); 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
// 			  break;
// 	case "NE": gold = 2 * (grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
// 			  break;			  
// 	case "NW": gold = 2 * (grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
// 			  break;
// 	case "SE": gold = 2 * (grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
// 			  break;
// 	case "SW": gold = 2 * (grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold); 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);
// 			  break;		  		  		  
// 	}
}

int Dwarf::getHealth() {
	return hp;
}

void Dwarf::setHealth(int h){
	hp = h; 
}

void Dwarf::attack(int x, int y) {}

Dwarf::~Dwarf() {}
