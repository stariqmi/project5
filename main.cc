#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "grid.h"
#include "textdisplay.h"
#include "tile.h"
#include "coordinates.h"
#include "combatMediator.h"
#include "helper.h"

using namespace std;

const int xsize = 80;
const int ysize = 25;

int main() {
	Helper* helper = new Helper;
	TextDisplay* td = new TextDisplay(xsize, ysize);
	Grid* grid = new Grid(td, xsize, ysize);
	CombatMediator* cm = new CombatMediator(grid);
	grid->combatMediator = cm;
	string s;
	char type;
	cin >> type;
	grid->initializeFloor(type);
	while (cin >> s){	
		
		if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
			int initialGold = grid->player->gold;
			string moveCheck = grid->player->move(s);
			cout << *grid;
			cout << "Action: " << helper->evaluateMove(grid, grid->player, s, initialGold, moveCheck) << endl;
		}

		if (s == "r") { 
			grid->clearGrid(); 
			grid->initializeFloor(type);
		}

		if (s == "u") {
			string dir;
			cin >> dir;
			Coordinates* c = helper->evalDirection(dir, grid->player->x, grid->player->y);
			bool check = helper->checkForPotion(grid, c->x, c->y);
			if(check) {
				grid->player->usePotion(c->x, c->y);
				cout << *grid;
			}
			else {
				cout << "ERROR: No potion exists at such location" << endl;
			}
			delete c;
		}

		if (s == "a") {
			string dir;
			cin >> dir;
			Coordinates* c1 = helper->evalDirection(dir, grid->player->x, grid->player->y);
			bool checkAttack = cm->combat(grid->player->x, grid->player->y, c1->x, c1->y);
			delete c1;
			cout << *grid;
		}

		if (s == "q")  {delete grid; break;}		
	}
	delete helper;
}