#include "mediator.h"
#include "livingthing.h"
#include <string>
#include "grid.h"
using namespace std;

Mediator::Mediator(Character * pl, Grid * gr): player(pl),grid(gr) {}

void Mediator::Attack() {
}

void Mediator::Attack(Coordinates *c1, Coordinates *c2){
player->attack(c1);
LivingThing* enemy;
enemy = dynamic_cast<LivingThing*>(grid->theGrid[c1->x][c1->y].thing);
enemy->attack(c2);
}