#ifndef __LTHING_H__
#define __LTHING_H__
#include <string>
#include "thing.h"
#include "coordinates.h"
class LivingThing: public Thing {
protected:
	int hp;
	int atk;
	int def;
public:
	LivingThing();
	virtual void move(std::string direction) = 0;
	virtual void attack (Coordinates *c) = 0;
	virtual int getHealth() = 0;
	virtual int getAtk() = 0;
	virtual int getDef() = 0;
	virtual void usePotion(int i, int j) = 0;
	virtual void setHealth(int h) = 0;
	~LivingThing();
};

#endif