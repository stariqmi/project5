#ifndef __POTION_H__
#define __POTION_H__

#include "item.h"

class Potion : public Item {
	public:
		std::string effect;
		std::string effectOn;
		int magnitude;
		std::string potionType;
		std::string getEffect();
		Potion(std::string effect, std::string effectOn, int magnitude);
		~Potion();
};

#endif