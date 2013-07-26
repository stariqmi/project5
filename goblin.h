#ifndef _GOBLIN_H__
#define _GOBLIN_H__
#include "character.h"
#include <string>

class Goblin: public Character {
	protected:	
		bool isAttacked;
	public:
		Goblin();
		int attack(int i, int j);
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
