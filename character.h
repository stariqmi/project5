#ifndef _CHARACTER_H__
#define _CHARACTER_H__
#include "livingthing.h"
#include <string>

class Character: public LivingThing {
protected:	
	int gold;
	public:
	Grid* grid;
	int x_coordinate;
	int y_coordinate;
	Character(std::string type, int hp, int atk, int def, int gold); // Sets defense, attack, gold and health
	void pickGold(std::string direction); // it picks and set gold
	void usePotion(std::string direction);
	~Character();
};

#endif
