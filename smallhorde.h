#ifndef __SMALLHORDE_H__
#define __SMALLHORDE_H__

#include "treasure.h"

class SmallHorde : public Treasure {
	public:
		int giveGold();
		SmallHorde();
};

#endif