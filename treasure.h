#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"
#include <string>

class Treasure : public Item {
protected:
	int gold;
public:
	std::string treasureType;
	Treasure(int gold, std::string treasureType);
	~Treasure();
	virtual int giveGold();
};

#endif