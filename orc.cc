#include <iostream>
#include "orc.h"
#include <string>
using namespace std;

Orc::Orc(): Character(orc, 180, 30, 25, 0) {}
void Orc::pickGold(string direction){
switch(direction)	{
	case "N": gold = (grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
			  break;
	case "S": gold = (grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
			  break;
	case "E": gold = (grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
			  break;		 		 
	case "W": gold = (grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
			  break;
	case "NE": gold = (grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
			  break;			  
	case "NW": gold = (grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
			  break;
	case "SE": gold = (grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold) / 2 ; 
			  delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
			  break;
	case "SW": gold = (grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold)/2; 
			  delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);
			  break;		  		  		  
	}
}
void Orc::move(string direction){
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

int Orc::getHealth() {
	return hp;
}

void Orc::setHealth(int h){
	hp = h; 
}