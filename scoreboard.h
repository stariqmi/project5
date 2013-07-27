#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>

class Scoreboard {
public:
	static Scoreboard * instance;
	static Scoreboard* getInstance();
	Scoreboard();
	int score;
	int highscore;
	void addScore(int points);
	static void cleanup();
};

#endif