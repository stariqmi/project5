#ifndef _ELF_H__
#define _ELF_H__
#include "character.h"
#include <string>

class Elf: public Character {
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