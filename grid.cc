#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid(TextDisplay* td, int x, int y): td(td), xsize(x), ysize(y) {
	//this->rooms = new Room*[5];
}

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


	// set coordinates
	for(int i = 0; i < this->ysize; i++) {
		for(int j = 0; j < this->xsize; j++) {
			this->theGrid[i][j].setCoords(i, j);
		}
	}

	// Boundary vertical walls
	for(int i = 0; i < this->ysize; i++) {
		this->theGrid[i][0].setThing(new Wall("vertical_wall"));
		this->theGrid[i][0].notifyDisplay(*(this->td));
		this->theGrid[i][this->xsize - 1].setThing(new Wall("vertical_wall"));
		this->theGrid[i][this->xsize - 1].notifyDisplay(*(this->td));
	}

	// Boundary horizontal walls
	for(int i = 1; i < (this->xsize - 1); i++) {
		this->theGrid[0][i].setThing(new Wall("horizontal_wall"));
		this->theGrid[0][i].notifyDisplay(*(this->td));
		this->theGrid[this->ysize - 1][i].setThing(new Wall("horizontal_wall"));
		this->theGrid[this->ysize - 1][i].notifyDisplay(*(this->td));
	}

	// Room-1
		// Vertical walls
		for(int i = 2; i < 8; i++) {
			this->theGrid[i][2].setThing(new Wall("vertical_wall"));
			this->theGrid[i][2].notifyDisplay(*(this->td));
			this->theGrid[i][27].setThing(new Wall("vertical_wall"));
			this->theGrid[i][27].notifyDisplay(*(this->td));
		}
		
		// Door Right
		delete this->theGrid[4][27].thing;
		this->theGrid[4][27].setThing(new Door);
		this->theGrid[4][27].notifyDisplay(*(this->td));

		// Hrozontal walls
		for(int i = 3; i < 27; i++) {
			this->theGrid[2][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[2][i].notifyDisplay(*(this->td));
			this->theGrid[7][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[7][i].notifyDisplay(*(this->td));	
		}

		//this->rooms[0] = new Room(26);
		for(int i = 3; i < 7; i++) {
			for(int j = 3; j < 27; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				//cout << i << "," << j << endl;
				//this->rooms[0]->addContent(this->theGrid[i][j]);
			}	
		}

		// Door bottom
		delete this->theGrid[7][13].thing;
		this->theGrid[7][13].setThing(new Door);
		this->theGrid[7][13].notifyDisplay(*(this->td));





	// Room-2
		// Vertical walls
		for(int i = 14; i < 23; i++) {
			this->theGrid[i][3].setThing(new Wall("vertical_wall"));
			this->theGrid[i][3].notifyDisplay(*(this->td));
			this->theGrid[i][23].setThing(new Wall("vertical_wall"));
			this->theGrid[i][23].notifyDisplay(*(this->td));	
		}

		// Door Right
		delete this->theGrid[20][23].thing;
		this->theGrid[20][23].setThing(new Door);
		this->theGrid[20][23].notifyDisplay(*(this->td));

		// Hrozontal walls
		for(int i = 4; i < 23; i++) {
			this->theGrid[14][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[14][i].notifyDisplay(*(this->td));
			this->theGrid[22][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[22][i].notifyDisplay(*(this->td));	
		}

		//this->rooms[0] = new Room(26);
		for(int i = 15; i < 22; i++) {
			for(int j = 4; j < 23; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				//cout << i << "," << j << endl;
				//this->rooms[0]->addContent(this->theGrid[i][j]);
			}	
		}

		// Door Top
		delete this->theGrid[14][12].thing;
		this->theGrid[14][13].setThing(new Door);
		this->theGrid[14][13].notifyDisplay(*(this->td));




	// Room-3
		// Vertical walls
		for(int i = 9; i < 14; i++) {
			this->theGrid[i][35].setThing(new Wall("vertical_wall"));
			this->theGrid[i][35].notifyDisplay(*(this->td));
			this->theGrid[i][47].setThing(new Wall("vertical_wall"));
			this->theGrid[i][47].notifyDisplay(*(this->td));
		}

		// Hrozontal walls
		for(int i = 36; i < 47; i++) {
			this->theGrid[9][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[9][i].notifyDisplay(*(this->td));
			this->theGrid[13][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[13][i].notifyDisplay(*(this->td));	
		}

		//this->rooms[0] = new Room(26);
		for(int i = 10; i < 13; i++) {
			for(int j = 36; j < 47; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				//cout << i << "," << j << endl;
				//this->rooms[0]->addContent(this->theGrid[i][j]);
			}	
		}
}

ostream& operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}