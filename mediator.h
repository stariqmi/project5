#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include "character.h"
#include "coordinates.h"
#include <string>


class Grid;

class Mediator {
protected:
	 Character * player;
	 Grid * grid;

public:
	Mediator(Character * player,Grid * grid);
	void Attack();
	void Attack(Coordinates *c1, Coordinates *c2);

};

#endif