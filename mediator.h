#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include "character.h"
#include <string>

class Mediator {
protected:
	const Character & player;
	const Character & enemy;
public:
	Mediator(const Character & player, const Character & enemy);
	void Attack();
	void Attack(std::string direction);

};

#endif