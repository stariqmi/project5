#ifndef __NORMALGOLD_H__
#define __NORMALGOLD_H__

#include "treasure.h"

class NormalGold : public Treasure {
	public:
		int giveGold();
		NormalGold();
};

#endif