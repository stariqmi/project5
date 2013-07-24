#ifndef __MERCHANTHORDE_H__
#define __MERCHANTHORDE_H__

#include "treasure.h"

class MerchantHorde : public Treasure {
	public:
		int giveGold();
		MerchantHorde();
};

#endif