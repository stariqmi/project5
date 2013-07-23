#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "textdisplay.h"
#include "tile.h"

using namespace std;

const int xsize = 80;
const int ysize = 25;

int main() {

	TextDisplay* td = new TextDisplay(xsize, ysize);
	Grid* grid = new Grid(td, xsize, ysize);
	Character* player;
	Character* enemy;
	string s;
	srand(time(NULL));
	int random = rand()% 7;
	string enemymoves[8] = {"no", "so", "ea" , "we", "ne", "nw", "se", "sw"};
	char type;
	cin >> type;
	grid->initializeFloor();
	player = grid->generateCharacter(type);
	grid->generateStairway();
	grid->generateEnemies();
	cout<< *grid;
	while (cin >> s){	
		if(s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
			player->move(s);
			//enemy->move(enemymoves[random]);
			cout << *grid;
		}
		if (s == "r") { 
			grid->clearGrid(); 
			grid->initializeFloor(); 
			player = grid->generateCharacter(type);
			grid->generateStairway();
			grid->generateEnemies();
			cout << *grid;}
		if (s == "q")  {delete grid; break;}		
	}
}