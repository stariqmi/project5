#ifndef _ELF_H__
#define _ELF_H__
#include "character.h"
#include <string>

class Elf: public Character {
public:
	Elf();
	int pickGold(int gold); 
	void usePotion(int i, int j);
	int getHealth();
	void setHealth(int h);
};

#endif