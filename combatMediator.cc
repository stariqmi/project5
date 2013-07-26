#include "combatMediator.h"
#include "grid.h"
#include "character.h"
#include <iostream>

using namespace std;

CombatMediator::CombatMediator(Grid* g) : grid(g) {}

bool CombatMediator::combat(int ai, int aj, int di, int dj) {
	cout << grid->theGrid[di][dj].thing->type << endl;
	if(	grid->theGrid[di][dj].thing == NULL ||
		grid->theGrid[di][dj].thing->type == "ground" || 
		grid->theGrid[di][dj].thing->type == "vertical_wall" ||
		grid->theGrid[di][dj].thing->type == "horizontal_wall" ||
		grid->theGrid[di][dj].thing->type == "door" ||
		grid->theGrid[di][dj].thing->type == "passage" ||
		grid->theGrid[di][dj].thing->type == "potion" ||
		grid->theGrid[di][dj].thing->type == "gold"
	) {
		cout << "ERROR: Cannot attack here" << endl;
		return false; 
	}

	else {
		Character* attacker = dynamic_cast<Character*>(grid->theGrid[ai][aj].thing);
		if(grid->theGrid[di][dj].thing->type == "merchant") {
			Merchant* merchant = dynamic_cast<Merchant*>(grid->theGrid[di][dj].thing);
			merchant->isHostile = true;
		}
		Character* attacker2 = dynamic_cast<Character*>(grid->theGrid[di][dj].thing);
		attacker->attack(di, dj);
		if(attacker2->hp <= 0) {
			Thing* gold;
			if(attacker2->type == "merchant") {
				gold = grid->itemFactory->makeItem("MH");
			}
			else if(attacker2->type == "dragon") {
				gold = new Ground;
			}
			else {
				gold = grid->itemFactory->makeItem("NG");
			}
			delete attacker2;
			grid->theGrid[di][dj].setThing(gold);
			grid->theGrid[di][dj].notifyDisplay(*(grid->td));
		}
		else {
			srand(time(NULL));
			int hit = rand() % + 2;
			if(hit) attacker2->attack(ai, aj);
		}
		return true;
	}
}