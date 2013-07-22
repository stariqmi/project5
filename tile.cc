#include <iostream>
#include "tile.h"
#include <string>
using namespace std;

Tile::Tile() {}

void Tile::setCoords(int r, int c) {
	this->r = r;
	this->c = c;
}

Tile::~Tile() {
	//if(this->livingThing) {delete this->livingThing;}
	delete this->thing;
}

void Tile::notifyDisplay(TextDisplay &td) {
	char c;
	if(this->thing == NULL) {
		//cout << "null" <<endl;
		c = ' ';
	}
	else {
		string type;
		type = this->thing->type;	
		//cout << "dead" << endl;
		if(type == "vertical_wall") {
		c = '|';
		}
		else if(type == "horizontal_wall") {
			c = '-';
		}
		else if(type == "ground") {
			c = '.';
		}
		else if(type == "door") {
			c = '+';
		}
		else if(type == "passage") {
			c = '#';
		}
		else if(type == "character") {
			c = '@';
		}
		else {
			c = 'x';
		}	
	}
	td.notify(this->r, this->c, c);
}

void Tile::setThing(Thing* thing) {
	//if(!(this->thing == NULL)) delete this->thing;
	this->thing = thing;
}