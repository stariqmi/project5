#ifndef _ORC_H__
#define _ORC_H__
#include "character.h"
#include <string>

class Orc : public Character {
public:
	Orc();
	void pickGold(std::string direction); 
	void usePotion(int i, int j);
	int getHealth();
	void setHealth(int h);
};

#endif