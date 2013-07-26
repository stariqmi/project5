#ifndef _CHARACTER_H__
#define _CHARACTER_H__
#include "coordinates.h"
#include "livingthing.h"
#include "potion.h"
#include <string>

class Grid;


class Character: public LivingThing {
	public:
		int gold;
		Grid* grid;
		std::string standingOn;
		char raceID;
		int x;
		int y;
		Character(); // Sets defense, attack, gold and health
		virtual int pickGold(int gold); // it picks and set gold
		void usePotion(int i, int j);
		std::string move(std::string direction);
		int getAtk();
		int getDef();
		void attack(Coordinates* c);
		virtual void attack(int i, int j);
		~Character();
};

#endif
