#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include "nonlivingthing.h"

class Item : public NonLivingThing {
	public:
		Item();
		~Item();
};

#endif