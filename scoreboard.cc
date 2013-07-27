#include "scoreboard.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Scoreboard *Scoreboard::instance = 0;

Scoreboard *Scoreboard::getInstance(){
	if (!instance) {
		instance = new Scoreboard;
		atexit(cleanup);
	}
	return instance;
}

Scoreboard::Scoreboard(): score(0) {}

void Scoreboard::addScore(int points) {
	score += points;
	if(score > highscore) {
		highscore = score;
	}
}

void Scoreboard::cleanup() {delete instance;}