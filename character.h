#ifndef _CHARACTER_H__
#define _CHARACTER_H__

#include "livingthing.h"
#include <string>

class Grid;


class Character: public LivingThing {
	protected:	
		int gold;
	public:
		Grid* grid;
		std::string standingOn;
		char raceID;
		int x;
		int y;
		Character(); // Sets defense, attack, gold and health
		void pickGold(std::string direction); // it picks and set gold
		void usePotion(std::string direction);
		void move(std::string direction);
		int getAtk();
		int getDef();
		void attack(std::string direction);
		~Character();
};

#endif
