#include <iostream>
#include "orc.h"
#include <string>
using namespace std;

Orc::Orc() {
	this->hp = 180;
	this->atk = 30;
	this->def = 25;
	raceID = 'o';
}
// void Orc::pickGold(string direction){
// switch(direction)	{
// 	case "N": gold = (grid->theGrid[x_coordinate][y_coordinate + 1].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate][y_coordinate + 1].setThing(new Ground);
// 			  break;
// 	case "S": gold = (grid->theGrid[x_coordinate][y_coordinate - 1].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate][y_coordinate - 1].setThing(new Ground);
// 			  break;
// 	case "E": gold = (grid->theGrid[x_coordinate + 1][y_coordinate].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate].setThing(new Ground);
// 			  break;		 		 
// 	case "W": gold = (grid->theGrid[x_coordinate - 1][y_coordinate].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate].setThing(new Ground);
// 			  break;
// 	case "NE": gold = (grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate + 1].setThing(new Ground);
// 			  break;			  
// 	case "NW": gold = (grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate + 1].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate + 1].setThing(new Ground);
// 			  break;
// 	case "SE": gold = (grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing.gold) / 2 ; 
// 			  delete grid->theGrid[x_coordinate + 1][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate + 1][y_coordinate - 1].setThing(new Ground);
// 			  break;
// 	case "SW": gold = (grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing.gold)/2; 
// 			  delete grid->theGrid[x_coordinate - 1][y_coordinate - 1].thing;
// 			  grid->theGrid[x_coordinate - 1][y_coordinate - 1].setThing(new Ground);
// 			  break;		  		  		  
// 	}
// }


int Orc::getHealth() {
	return hp;
}

void Orc::setHealth(int h){
	hp = h; 
}

void Orc::attack(int x, int y) {}
