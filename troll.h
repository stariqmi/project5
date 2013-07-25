#ifndef _TROLL_H__
#define _TROLL_H__
#include "character.h"
#include <string>

class Troll: public Character {
	protected:	
		bool isAttacked;
	public:
		Troll();
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
