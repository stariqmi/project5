#include <iostream>
#include "character.h"
#include <string>
#include "grid.h"
using namespace std;
Character::Character(std::string type, int hp, int atk, int def, int gold) type(type), hp(hp), atk(atk), def(def), gold(gold) {}
void Character::pickGold(string direction){
switch(direction)	{
	case "N": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
			  break;
	case "S": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
			  break;
	case "E": gold = gold + grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
			  break;		 		 
	case "W": gold = gold + grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
			  break;
	case "NE": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
			  break;			  
	case "NW": gold = gold + grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
			  break;
	case "SE": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
			  break;
	case "SW": gold = gold + grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);
			  break;		  		  		  
	}
}
Character::~Character() {}

