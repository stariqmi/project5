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
	if(this->livingThing) {delete this->livingThing;}
	if(this->nonLivingThing) {delete this->nonLivingThing;}
}

void Tile::notifyDisplay(TextDisplay &td) {
	char c;
	if(this->nonLivingThing == NULL) {
		cout << "null" <<endl;
		c = ' ';
	}
	else {
		string type;
		if(this->livingThing != NULL) {
			cout << "living" << endl;
			this->livingThing->type;
			cout << "living" << endl;
			type = '@';
		}
		else {
			cout << "dead" << endl;
			type = this->nonLivingThing->type;	
			cout << "dead" << endl;
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

	}
	td.notify(this->r, this->c, c);
}

void Tile::setThing(NonLivingThing* thing) {
	//if(!(this->thing == NULL)) delete this->thing;
	this->nonLivingThing = thing;
}