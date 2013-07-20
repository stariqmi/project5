#include "room.h"

Room::Room(): totalContents(0) {}
void Room::addContent(Tile content) {
	this->contents[this->totalContents] = content;
	this->totalContents++;
}