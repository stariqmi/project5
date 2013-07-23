#ifndef _HUMAN_H__
#define _HUMAN_H__
#include "character.h"
#include <string>

class Human: public Character {
public:
	Human();
	void attack(int x, int y);
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	int getHealth();
	int getAtk();
	int getDef();
	void setHealth(int h);
};

#endif