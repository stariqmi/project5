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
	bool keepPlaying = true;
	while(keepPlaying) {
		char type;
		cin >> type;
		grid->initializeFloor(type);
		while (cin >> s) {
			bool success = false;
			if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
				int initialGold = grid->player->gold;
				string moveCheck = grid->player->move(s);
				cout << *grid;
				string result = helper->evaluateMove(grid, grid->player, s, initialGold, moveCheck);
				if(result == "invalid") {
					cout << "ERROR: Invalid move - Cannot walk over wall, potion, enemy or empty space." << endl;
				}
				else if(result == "outside") {
					cout << "ERROR: Invalid move - You can't move outside playable region." << endl;
				}
				else if(result == "dragon") {
					cout << "ERROR: Invalid move - You need to kill the dragon before you can take the Dragon Horde." << endl;
				}
				else {
					cout << "Action: " << result << "." << endl;
					success = true;
				}
			}

			else if (s == "r") {
				if(grid->theGrid != NULL) { 
					grid->clearGrid(); 
				}
				break;
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
					cout << "ERROR: Invalid direction - No potion exists at such location." << endl;
				}
				delete c;
			}

			else if (s == "a") {
				string dir;
				cin >> dir;
				Coordinates* c1 = helper->evalDirection(dir, grid->player->x, grid->player->y);
				string checkAttack = cm->combat(grid->player->x, grid->player->y, c1->x, c1->y);
				delete c1;
				cout << *grid;
				if(checkAttack == "invalid") {
					cout << "ERROR: Invalid move (Cannot attack here)" << endl;
				}
				else {
					success = true;
					cout << "Action: " << checkAttack << endl;
				}
			}

			else if (s == "q")  {delete grid; keepPlaying = false; break;}		
			else {
				cout << "ERROR: Not a valid command" <<  endl;
			}
			if(success) grid->enemyAI();
		}
		if(cin.fail()) keepPlaying = false;
	}
	delete helper;
}