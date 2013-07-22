#include <iostream>
#include <string>

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
	string s;
	char type;
	cin >> type;
	grid->initializeFloor();
	player = grid->generateCharacter(type);
	cout<< *grid;
	while (cin >> s){	
		if(s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
			player->move(s);
			cout << *grid;
		}
		if (s == "reset") { 
			grid->clearGrid(); 
			grid->initializeFloor(); 
			player = grid->generateCharacter(type);
			cout << *grid;}
		if (s == "quit")  {delete grid; break;}		
	}
}