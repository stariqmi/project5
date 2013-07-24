#include "mediator.h"
#include <string>
using namespace std;

Mediator::Mediator(Character * pl, Thing * en): player(pl),enemy(en) {}

void Mediator::Attack() {
}

void Mediator::Attack(string direction){
if (direction == "no") {
	player->attack(direction);
	Character* e = dynamic_cast<Character*>(enemy);
	
	e->attack("so"); 
}
}