#ifndef __ROOM_H__
#define __ROOM_H__

#include "tile.h"

class Room {

public:
	int totalContents;
	Tile* contents;
	Room();
	void addContent(Tile content);
};

#endif