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
		bool success = false;
		if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
			int initialGold = grid->player->gold;
			string moveCheck = grid->player->move(s);
			cout << *grid;
			string result = helper->evaluateMove(grid, grid->player, s, initialGold, moveCheck);
			if(result == "invalid") {
				cout << "Action: Invalid move." << endl;
			}
			else {
				cout << "Action: " << result << "." << endl;
				success = true;
			}
		}

		else if (s == "r") { 
			grid->clearGrid(); 
			grid->initializeFloor(type);
		}

		else if (s == "u") {
			string dir;
			cin >> dir;
			Coordinates* c = helper->evalDirection(dir, grid->player->x, grid->player->y);
			bool check = helper->checkForPotion(grid, c->x, c->y);
			if(check) {
				Potion* potion = dynamic_cast<Potion*>(grid->theGrid[c->x][c->y].thing);
				string potionType = potion->potionType;
				grid->player->usePotion(c->x, c->y);
				cout << *grid;
				cout << "Action: PC used " << potionType << "." << endl;
				success = true;
			}
			else {
				cout << *grid;
				cout << "Action: Invalid direction (No potion exists at such location)" << endl;
			}
			delete c;
		}

		else if (s == "a") {
			string dir;
			cin >> dir;
			Coordinates* c1 = helper->evalDirection(dir, grid->player->x, grid->player->y);
			bool checkAttack = cm->combat(grid->player->x, grid->player->y, c1->x, c1->y);
			delete c1;
			cout << *grid;
			success = true;
		}

		else if (s == "q")  {delete grid; break;}		
		else {
			cout << "ERROR: Not a valid command" <<  endl;
		}
		if(success) grid->enemyAI();
	}
	delete helper;
}