#include "combatMediator.h"
#include "grid.h"
#include "character.h"
#include <iostream>

using namespace std;

CombatMediator::CombatMediator(Grid* g) : grid(g) {}

void CombatMediator::combat(int ai, int aj, int di, int dj) {
	Character* attacker = dynamic_cast<Character*>(grid->theGrid[ai][aj].thing);
	Character* attacker2 = dynamic_cast<Character*>(grid->theGrid[di][dj].thing);
	attacker->attack(di, dj);
	if(attacker2->hp <= 0) {
		delete attacker2;
		Thing* gold = grid->itemFactory->makeItem("NG");
		grid->theGrid[di][dj].setThing(gold);
		grid->theGrid[di][dj].notifyDisplay(*(grid->td));
	}
	else {
		srand(time(NULL));
		int hit = rand() % + 2;
		if(hit) attacker2->attack(ai, aj);
	}
}