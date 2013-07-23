#ifndef _DWARF_H__
#define _DWARF_H__
#include "character.h"
#include <string>

class Dwarf: public Character {
public:
	Dwarf();
	void attack(int x_coordinate,int y_coordinate);
	void pickGold(std::string direction); 
	void usePotion(int i, int j);
	int getHealth();
	void setHealth(int h);
};

#endif