#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include "character.h"
#include <string>

class Mediator {
protected:
	 Character * player;
	 Thing * enemy;
public:
	Mediator(Character * player,Thing * enemy);
	void Attack();
	void Attack(std::string direction);

};

#endif