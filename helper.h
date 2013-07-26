#ifndef __HELPER_H__
#define __HELPER_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "grid.h"
#include "coordinates.h"

class Helper {
	public:
		Helper();
		Coordinates* evalDirection(std::string direction, int i, int j);
		bool checkForPotion(Grid* grid, int x, int y);
		std::string evaluateMove(Grid* grid, Character* player, std::string dir, int gold, std::string move);
};

#endif