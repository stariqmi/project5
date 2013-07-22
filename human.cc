#include <iostream>
#include "human.h"
#include <string>
using namespace std;

Human::Human(): Character(human, 140, 20, 20, 0) {}
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
void Human::move(string direction){
switch(direction)	{
	case "N": temp = grid->theGrid[x_coordinate][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate + 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
		      break;
	case "S": temp = grid->theGrid[x_coordinate][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate + 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
			  break;
	case "E": temp = grid->theGrid[x_coordinate + 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
			  break;		 		 
	case "W": temp = grid->theGrid[x_coordinate - 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
			  break;
	case "NE":temp = grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
		      break;			  
	case "NW":temp = grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
		      break;
	case "SE":temp = grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
		      break;
	case "SW":temp = grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing = grid->theGrid[x_coordinate][y_coordinate];
			  grid->theGrid[x_coordinate][y_coordinate] = temp;
		      break;		  		  		  
	}	
}

int Human::getHealth() {
	return hp;
}

void Human::setHealth(int h){
	hp = h; 
}