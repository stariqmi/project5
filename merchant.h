#ifndef _MERCHANT_H__
#define _MERCHANT_H__
#include "character.h"
#include <string>

class Merchant: public Character {
	protected:
		
		bool isAttacked;
	public:
		static bool isHostile;
		Merchant();
		void attack (int x, int y);
		void setAttack(); 
		int getHealth();
		void setHealth(int h);
};

#endif
