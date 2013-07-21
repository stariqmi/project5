#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include "tile.h"
#include "wall.h"
#include "door.h"
#include "ground.h"
#include "passage.h"
#include "room.h"
#include "textdisplay.h"

class Grid {
public:
	Tile** theGrid;
	int xsize;
	int ysize;
	TextDisplay* td;
	Room** rooms;
	 Grid(TextDisplay* td, int x, int y);
	~Grid();
	void clearGrid();
	void init();
	friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif