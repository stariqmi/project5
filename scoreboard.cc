#include "scoreboard.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Scoreboard *scoreboard::instance = 0;

Scoreboard *scoreboard::getInstance(){
	if (!instance) {
		instance = new Scoreboard;
		atexit(cleanup);
	}
	return instance;
}

Scoreboard::Scoreboard(): score(0) {}

Scoreboard::addScore(int points) {score += points;}

void Scoreboard::cleanup() {delete instance;}