#ifndef _ORC_H__
#define _ORC_H__
#include "character.h"
#include <string>

class Orc : public Character {
public:
	Orc();
	int pickGold(int gold); 
	void usePotion(int i, int j);
	int getHealth();
	void setHealth(int h);
};

#endif