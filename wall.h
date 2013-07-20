#ifndef __WALL_H__
#define __WALL_H__

#include <stdio>
#include <string>
#include "thing.h"

class Wall : public Thing {

public:
	std::string type;
	Wall(std::string type);
	~Wall();
};

#endif