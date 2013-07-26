#ifndef __COMBAT_MEDIATOR_H__
#define __COMBAT_MEDIATOR_H__

#include <string>

class Grid;

class CombatMediator {
public:
	Grid* grid;
	CombatMediator(Grid* g);
	std::string combat(int ai, int aj, int di, int dj);
};

#endif