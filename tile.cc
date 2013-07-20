#include <iostream>
#include "tile.h"
#include <string>
using namespace std;

Tile::Tile() {}

void Tile::setCoords(int r, int c) {
	this->r = r;
	this->c = c;
}

void Tile::notifyDisplay(TextDisplay &td) {
	char c;
	if(this->thing == NULL) {
		c = ' ';
	}
	else {
		string type = this->thing->type;
		if(type == "vertical_wall") {
			c = '|';
		}
		else if(type == "horizontal_wall") {
			c = '-';
		}
		else {
			c = 'x';
		}
	}
	td.notify(this->r, this->c, c);
}

void Tile::setThing(Thing* thing) {
	this->thing = thing;
}