#ifndef _DRAGON_H__
#define _DRAGON_H__
#include "character.h"
#include <string>

class Dragon: public Character {
	protected:	
		bool isAttacked;
	public:
		Dragon();
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
