#ifndef __LTHING_H__
#define __LTHING_H__
#include <string>
#include "thing.h"
#include "coordinates.h"
class LivingThing: public Thing {
public:
	int hp;
	int atk;
	int def;
	LivingThing();
	virtual std::string move(std::string direction) = 0;
	virtual int getHealth() = 0;
	virtual void setHealth(int h) = 0;
	~LivingThing();
};

#endif