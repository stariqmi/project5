#ifndef _HUMAN_H__
#define _HUMAN_H__
#include "character.h"
#include <string>

class Human: public Character {
public:
	Human();
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	int getHealth();
	void setHealth(int h);
};

#endif