#ifndef __ROOM_H__
#define __ROOM_H__

#include <vector>
#include "tile.h"

class Room {

public:
	int totalContents;
	Tile* contents;
	Room(int size);
	void addContent(Tile& content);
};

#endif