#include "grid.h"
#include <iostream>

using namespace std;


Grid::Grid(TextDisplay* td, int x, int y): td(td), xsize(x), ysize(y) {}

Grid::~Grid() {
	this->clearGrid();
	delete this->td;
}

void Grid::clearGrid() {
	for(int i = 0; i < this->ysize; i++) {
		delete[] this->theGrid[i];
	}
	this->td->clearDisplay();
	delete[] this->theGrid;
}

void Grid::init() {
	this->theGrid = new Tile*[this->ysize];
	for(int i = 0; i < this->ysize; i++) {
		this->theGrid[i] = new Tile[this->xsize];
	} // for

	//cout << "new grid" << endl;

	// set coordinates
	for(int i = 0; i < this->ysize; i++) {
		for(int j = 0; j < this->xsize; j++) {
			this->theGrid[i][j].setCoords(i, j);
		}
	}

	//cout << "new grid" << endl;

	for(int i = 0; i < this->ysize; i++) {
		this->theGrid[i][0].setThing(new Wall("vertical_wall"));
		this->theGrid[i][0].notifyDisplay(*(this->td));
		this->theGrid[i][this->xsize - 1].setThing(new Wall("vertical_wall"));
		this->theGrid[i][this->xsize - 1].notifyDisplay(*(this->td));
	}

	cout << "new grid" << endl;

	for(int i = 1; i < (this->xsize - 1); i++) {
		this->theGrid[0][i].setThing(new Wall("horizontal_wall"));
		this->theGrid[0][i].notifyDisplay(*(this->td));
		this->theGrid[this->ysize - 1][i].setThing(new Wall("horizontal_wall"));
		this->theGrid[this->ysize - 1][i].notifyDisplay(*(this->td));
	}
}

ostream& operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}