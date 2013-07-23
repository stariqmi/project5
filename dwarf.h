#ifndef _DWARF_H__
#define _DWARF_H__
#include "character.h"
#include <string>

class Dwarf: public Character {
public:
	Dwarf();
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	int getHealth();
	void setHealth(int h);
};

#endif