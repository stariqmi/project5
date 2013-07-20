#ifndef __GRID_H__
#define __GRID_H__

#include <stdio>
#include "tile.h"
#include "textdisplay.h"

class Grid {
public:
	Tile** theGrid;
	int xsize;
	int ysize;
	TextDisplay* td;
	 Grid(TextDisplay* td);
	~Grid();
	void clearGrid();
	void init();
	friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif