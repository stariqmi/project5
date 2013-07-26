#ifndef _HUMAN_H__
#define _HUMAN_H__
#include "character.h"
#include <string>

class Human: public Character {
public:
	Human();
	int pickGold(int gold); 
	void usePotion(int i, int j);
	int getHealth();
	void setHealth(int h);
};

#endif