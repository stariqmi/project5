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

int main(int argc, char* argv[]) {
	Helper* helper = new Helper;
	TextDisplay* td = new TextDisplay(xsize, ysize);
	Grid* grid = new Grid(td, xsize, ysize);
	if(argc > 1) grid->layout = argv[1];
	CombatMediator* cm = new CombatMediator(grid);
	grid->combatMediator = cm;
	string s;
	int player_health = 0;
	int player_gold = 0;
	char type;
	bool finish = false;
	bool died = false;
	bool nextLevel = false;
	bool keepPlaying = true;
	while(keepPlaying) {
		if(!nextLevel && !(died || finish)) {
			cout << "Select race (default Human): ";
			cin >> type;
		}
		grid->initializeFloor(type);
		if(nextLevel && !(died || finish) ) {
			cout << "new level!" << endl;
			grid->player->hp = player_health;
			grid->player->gold = player_gold;
		}
		if(died || finish) {
			 cout << "Current Score " << grid->player->scoreboard->score << endl;
			 cout << "High Score " << grid->player->scoreboard->highscore << endl;
			 died = false;
			 finish = false;

		}
		cout << *grid;
		nextLevel = false;
		while (cin >> s) {
			bool success = false;
			string action;
			string error;
			if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "nw" || s == "ne" || s == "sw" || s == "se") {
				int initialGold = grid->player->gold;
				string moveCheck = grid->player->move(s);
				if(moveCheck == "next") {
					player_gold = grid->player->gold;
					player_health = grid->player->hp;
					if(grid->theGrid != NULL) { 
						grid->clearGrid();
					}	
					nextLevel = true;
				}
				else if(moveCheck == "finish") {
					finish = true;
					break;
				}
				// if conditon for moveCheck == finish;
				else {
					//cout << *grid;
					string result = helper->evaluateMove(grid, grid->player, s, initialGold, moveCheck);
					if(result == "invalid") {
						error = "ERROR: Invalid move - Cannot walk over wall, potion, enemy or empty space.";
					}
					else if(result == "outside") {
						error = "ERROR: Invalid move - You can't move outside playable region.";
					}
					else if(result == "dragon") {
						error = "ERROR: Invalid move - You need to kill the dragon before you can take the Dragon Horde.";
					}
					else {
						action = "Action: " + result + ".";
						success = true;
					}
				}
			}

			else if (s == "r") {
				player_gold = 0;
				player_health = 0;
				grid->level = 1;
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
					//cout << *grid;
					action = "Action: PC used " + potionType + ".";
					success = true;
				}
				else {
					//cout << *grid;
					error = "ERROR: Invalid direction - No potion exists at such location.";
				}
				delete c;
			}

			else if (s == "a") {
				string dir;
				cin >> dir;
				Coordinates* c1 = helper->evalDirection(dir, grid->player->x, grid->player->y);
				string checkAttack = cm->combat(grid->player->x, grid->player->y, c1->x, c1->y);
				delete c1;
				//cout << *grid;
				if(checkAttack == "invalid") {
					error = "ERROR: Invalid move (Cannot attack here)";
				}
				else {
					success = true;
					//cout << *grid;
					action = "Action: " + checkAttack;
				}
			}

			else if (s == "q")  {delete grid; keepPlaying = false; break;}		
			else {
				error =  "ERROR: Not a valid command";
			}
			if(success) {
				grid->enemyAI(action);
				player_gold = grid->player->gold;
				player_health = grid->player->hp;
			}
			else {
				cout << error << endl;
			}
			if(nextLevel) { 
				break; 
			}
			if(grid->player->hp <= 0){
				died = true;
				grid->clearGrid();
				grid->level = 1;
				break;
			}
		}
		if(cin.fail()) keepPlaying = false;
	}
	delete helper;
}