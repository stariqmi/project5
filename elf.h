#ifndef _ELF_H__
#define _ELF_H__
#include "character.h"
#include <string>

class Elf: public Character {
public:
	Elf();
	void attack(int x_coordinate,int  y_coordinate);
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	int getHealth();
	void setHealth(int h);
};

#endif