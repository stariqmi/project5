#include "room.h"
#include <iostream>

Room::Room(int size): totalContents(0) {
	this->contents = new Tile[size];
}
void Room::addContent(Tile& content) {
	this->contents[this->totalContents] = content;
	this->totalContents++;
}