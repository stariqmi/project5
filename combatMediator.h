#ifndef __COMBAT_MEDIATOR_H__
#define __COMBAT_MEDIATOR_H__

class Grid;

class CombatMediator {
public:
	Grid* grid;
	CombatMediator(Grid* g);
	void combat(int ai, int aj, int di, int dj);
};

#endif