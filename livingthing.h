#ifndef __LTHING_H__
#define __LTHING_H__
#include <string>
#include "thing.h"

class LivingThing: public Thing {
int hp;
int atk;
int def;
public:
	LivingThing(std::string type);
	virtual void move() = 0;
	virtual void attack (int i, int j) = 0;
	virtual int getHealth() = 0;
	virtual void setHealth(int h) = 0;
	virtual ~LivingThing();
};

#endif