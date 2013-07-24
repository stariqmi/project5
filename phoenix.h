#ifndef _PHOENIX_H__
#define _PHOENIX_H__
#include "character.h"
#include <string>

class Phoenix: public Character {
	protected:	
		bool isAttacked;
	public:
		Phoenix();
		void attack (int x, int y);
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
