#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "textdisplay.h"
#include "tile.h"
#include "coordinates.h"
#include "mediator.h"

using namespace std;

const int xsize = 80;
const int ysize = 25;

Coordinates* evalDirection(string direction, int i, int j) {
	Coordinates* c;
	if(direction == "no") {
		c = new Coordinates(i - 1, j);
	}
	else if(direction == "so") {
		c = new Coordinates(i + 1, j);
	}
	else if(direction == "we") {
		c = new Coordinates(i, j - 1);
	}
	else if(direction == "ea") {
		c = new Coordinates(i, j + 1);
	}
	else if(direction == "sw") {
		c = new Coordinates(i + 1, j - 1);
	}
	else if(direction == "se") {
		c = new Coordinates(i + 1, j + 1);
	}
	else if(direction == "nw") {
		c = new Coordinates(i - 1, j - 1);
	}
	else if(direction == "ne") {
		c = new Coordinates(i - 1, j + 1);
	}
	return c;
}

void intitiate_atk(Mediator mediator, string direction) {
	mediator.Attack(direction);
}

int main() {

	TextDisplay* td = new TextDisplay(xsize, ysize);
	Grid* grid = new Grid(td, xsize, ysize);
	//Character* player;
	//Character* enemy;
	string s;
	srand(time(NULL));
	int random = rand()% 7;
	string enemymoves[8] = {"no", "so", "ea" , "we", "ne", "nw", "se", "sw"};
	char type;
	cin >> type;
	grid->initializeFloor(type);
	while (cin >> s){	
		if(s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
			grid->player->move(s);
			//enemy->move(enemymoves[random]);
		}
		if (s == "r") { 
			grid->clearGrid(); 
			grid->initializeFloor(type);
			}
		if ( s == "u") {
			string dir;
			cin >> dir;
			Coordinates* c = evalDirection(dir, grid->player->x, grid->player->y);
			grid->player->usePotion(c->x, c->y);
			delete c;
			cout << *grid;
		} 
		if (s == "a") {
			string dir;
			cin >> dir;
			Coordinates* c = evalDirection(dir, grid->player->x, grid->player->y);
			Character* enemy;
			enemy = dynamic_cast<Character*>(grid->theGrid[c->x][c->y].thing);
			intitiate_atk(Mediator(grid->player,grid->theGrid[c->x][c->y].thing), dir);
			//delete enemy;
			delete c;
			cout << *grid;
		}
		if (s == "q")  {delete grid; break;}		
	}
}