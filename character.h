#ifndef _CHARACTER_H__
#define _CHARACTER_H__
#include "scoreboard.h"
#include "coordinates.h"
#include "livingthing.h"
#include "potion.h"
#include <string>

class Grid;
class Scoreboard;

class Character: public LivingThing {
	public:
		bool isMoved;	// for enemy AI
		int gold;
		Grid* grid;
		std::string standingOn; // for PC, standing on ground, door, passage or stairway
		char raceID;	// char to represent race
		int x;	// X-location in grid
		int y;	// y-location in grid
		Character(); 
		Scoreboard* scoreboard;
		virtual int pickGold(int gold);
		virtual void usePotion(int i, int j);
		std::string move(std::string direction);
		virtual int attack(int i, int j);
		~Character();
};

#endif
