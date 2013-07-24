#include "mediator.h"
#include <string>
using namespace std;

Mediator::Mediator(Character * pl, Character * en): player(pl),enemy(en) {}

void Mediator::Attack() {
}

void Mediator::Attack(string direction){
if (direction == "no") {
	player->attack(direction);
	enemy->attack("so"); 
}
}