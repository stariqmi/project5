#include <iostream>
#include "tile.h"
#include <string>
using namespace std;

Tile::Tile(): thing(NULL), isOccupied(false) {}

void Tile::setCoords(int r, int c) {
	this->r = r;
	this->c = c;
}

Tile::~Tile() {
	if(this->thing != NULL) {
		delete this->thing;
	}
}

void Tile::notifyDisplay(TextDisplay &td) {
	char c;
	if(this->thing == NULL) {
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
		else if(type == "stairway") {
			c = '/';
		}
		else if(type == "werewolf") {
			c = 'W';
		}
		else if(type == "potion") {
			c = 'P';
		}
		else if(type == "vampire") {
			c = 'V';
		}
		else if(type == "troll") {
			c = 'T';
		}
		else if(type == "goblin") {
			c = 'N';
		}
		else if(type == "merchant") {
			c = 'M';
		}
		else if(type == "phoenix") {
			c = 'X';
		}
		else if(type == "dragon") {
			c = 'D';
		}
		else if(type == "gold") {
			c = 'G';
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