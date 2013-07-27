#include "combatMediator.h"
#include "grid.h"
#include "character.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

CombatMediator::CombatMediator(Grid* g) : grid(g) {}

string CombatMediator::combat(int ai, int aj, int di, int dj) {
	string result = "";
	// PC tries to attack a non-enemy
	if(	grid->theGrid[di][dj].thing == NULL ||
		grid->theGrid[di][dj].thing->type == "ground" || 
		grid->theGrid[di][dj].thing->type == "vertical_wall" ||
		grid->theGrid[di][dj].thing->type == "horizontal_wall" ||
		grid->theGrid[di][dj].thing->type == "door" ||
		grid->theGrid[di][dj].thing->type == "passage" ||
		grid->theGrid[di][dj].thing->type == "potion" ||
		grid->theGrid[di][dj].thing->type == "gold"
	) {
		result = "invalid"; 
	}

	// Valid attack
	else {
		string result1 = "";
		string result2 = "";
		Character* attacker = dynamic_cast<Character*>(grid->theGrid[ai][aj].thing);
		
		// Attacked a merchant, all merchants are hostile now
		if(grid->theGrid[di][dj].thing->type == "merchant") {
			Merchant* merchant = dynamic_cast<Merchant*>(grid->theGrid[di][dj].thing);
			merchant->isHostile = true;
		}
		Character* attacker2 = dynamic_cast<Character*>(grid->theGrid[di][dj].thing);
		int damage1 = attacker->attack(di, dj); // Attack enemy
		ostringstream os;
		int hp;
		hp = attacker2->hp;
		if(attacker2->hp < 0) {hp = 0;}
		os << "PC deals " << damage1 << " damage to " << attacker2->raceID << " (" << hp << " HP)."; 
		result1 = os.str();

		// Enemy killed, drops gold
		if(attacker2->hp <= 0) {
			Thing* gold;

			// Merchant drops merchant horde
			if(attacker2->type == "merchant") {
				gold = grid->itemFactory->makeItem("MH");
			}

			// Dragon slain
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

		// Enemy alive, prepares for attack
		else {
			int damage2;
			srand(time(NULL));
			int hit = rand() % + 2;

			// If enemy doesnt miss
			if(hit) {
				damage2 = attacker2->attack(ai, aj);
				ostringstream os;
				os << attacker2->raceID << " deals " << damage2 << " damage to PC.";
				result2 = os.str();
			}
		}
		result = result1 + " " + result2;
	}
	return result;
}