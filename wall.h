#ifndef __WALL_H__
#define __WALL_H__

#include <iostream>
#include <string>
#include "nonlivingthing.h"

class Wall : public NonLivingThing {

public:
	Wall(std::string type);
	~Wall();
};

#endif