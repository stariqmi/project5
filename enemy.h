#ifndef _ENEMY_H__
#define _ENEMY_H__

#include "livingthing.h"
#include <string>

class Grid;

class Enemy: public LivingThing {
	protected:	
		int gold;
	public:
		Grid* grid;
		std::string standingOn;
		int x;
		int y;
		Enemy(); // Sets defense, attack, gold and health
		void move(std::string direction);
		~Enemy();
};

#endif