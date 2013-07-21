#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include <vector>
#include "tile.h"
#include "wall.h"
#include "door.h"
#include "ground.h"
#include "passage.h"
#include "room.h"
#include "textdisplay.h"
#include "coordinates.h"

class Grid {
public:
	Tile** theGrid;
	int xsize;
	int ysize;
	TextDisplay* td;
	Room rooms[5];
	std::vector<Coordinates*> ground;
	Grid(TextDisplay* td, int x, int y);
	~Grid();
	void clearGrid();
	void initializeFloor();
	friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif