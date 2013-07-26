#ifndef _VAMPIRE_H__
#define _VAMPIRE_H__
#include "character.h"
#include <string>

class Vampire: public Character {
	protected:	
		bool isAttacked;
	public:
		Vampire();
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
		void attack(int i, int j);
};

#endif
