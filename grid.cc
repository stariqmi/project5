#include "grid.h"
#include <stdio>

Grid::Grid(TextDisplay* td, int x, int y): td(td), xsize(x), ysize(y) {}

void Grid::init() {
	this->theGrid = new Tile*[this->ysize];
	for(int i = 0; i < this->ysize; i++) {
		this->theGrid[i] = new Tile[this->xsize];
	} // for

	// set coordinates
	for(int i = 0; i < this->ysize; i++) {
		for(int j = 0; j < this->xsize; j++) {
			this->theGrid[i][j]->setCoords(i, j);
		}
	}

	
}