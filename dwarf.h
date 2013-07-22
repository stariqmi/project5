#ifndef _DWARF_H__
#define _DWARF_H__
#include "character.h"
#include <string>

class Dwarf: public Character {
public:
	Dwarf();
	void attack(x_coordinate, y_coordinate);
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	void move(std::string direction);
	int getHealth();
	void setHealth(int h);
	void move(std::string direction);
};

#endif