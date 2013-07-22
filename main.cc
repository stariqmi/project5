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
	while (cin >> s){
		//if (cin.fail()) {break;}
		if (s == "start") { 
			grid->initializeFloor();
			player = grid->generateCharacter(type);
			cout<< *grid;
		}
		if(s == "n" || s == "s" || s == "e" || s == "w") {
			player->move(s);
			cout << *grid;
		}
		if (s == "reset") { 
			grid->clearGrid(); 
			grid->initializeFloor(); 
			grid->generateCharacter(type);
			cout << *grid;}
		if (s == "quit")  {delete grid; break;}		
	}
}