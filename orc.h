#ifndef _ORC_H__
#define _ORC_H__
#include "character.h"
#include <string>

class Orc: public Character {
public:
	Orc(std::string type, int hp, int atk, int def);
	~Orc();
	void attack(int x_coordinate, int y_coordinate);
	void pickGold(std::string direction); 
	void usePotion(std::string direction);
	void move(std::string direction);
	int getHealth();
	void setHealth(int h);
};

#endif