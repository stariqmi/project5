#ifndef _DWARF_H__
#define _DWARF_H__
#include "character.h"
#include <string>

class Dwarf: public Character {
public:
	Dwarf();
	int pickGold(int gold);
	int getHealth();
	void setHealth(int h);
};

#endif