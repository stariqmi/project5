#ifndef __DRAGONHORDE_H__
#define __DRAGONHORDE_H__

#include "treasure.h"
#include "dragon.h"
#include "tile.h"

class DragonHorde : public Treasure {
	public:
		int giveGold();
		DragonHorde();
		Tile* protector;
};

#endif