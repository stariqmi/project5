#ifndef _WEREWOLF_H__
#define _WEREWOLF_H__
#include "character.h"
#include <string>

class Werewolf: public Character {
	protected:	
		bool isAttacked;
	public:
		Werewolf();
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
