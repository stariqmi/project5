#ifndef __WALL_H__
#define __WALL_H__

#include <iostream>
#include <string>
#include "thing.h"

class Wall : public Thing {

public:
	Wall(std::string type);
	~Wall();
};

#endif