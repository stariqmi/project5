#ifndef __ROOM_H__
#define __ROOM_H__

#include <vector>

#include "coordinates.h"

class Room {

public:
	Room();
	~Room();
	int roomNumber;
	bool isOccupied;
	std::vector<Coordinates*> tiles;
};

#endif