#ifndef _ELF_H__
#define _ELF_H__
#include "character.h"
#include <string>

class Elf: public Character {
public:
	Elf();
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	int getHealth();
	void setHealth(int h);
};

#endif