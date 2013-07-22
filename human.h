#ifndef _HUMAN_H__
#define _HUMAN_H__
#include "character.h"
#include <string>

class Human: public Character {
public:
	Human();
	void attack(x_coordinate, y_coordinate);
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	void move(std::string direction);
	int getHealth();
	void setHealth(int h);
	void move(std::string direction);
};

#endif