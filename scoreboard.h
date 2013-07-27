#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "grid.h"
#include "coordinates.h"


class Scoreboard {
public:
	static Scoreboard * instance;
	static Scoreboard* getInstance();
	Scoreboard();
	int score;
	void addScore(int points);
	static void cleanup();
};

#endif