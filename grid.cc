#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid(TextDisplay* td, int x, int y): td(td), xsize(x), ysize(y) {
	// this->rooms = new Room*[5];
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
	vector<Coordinates*>::iterator it = this->ground.begin();
	//cout << this->ground.size() << endl;
	while(it != this->ground.end()) {
		delete *it;
		it++;
	}
	this->ground.clear();
	delete[] this->theGrid;
}

void Grid::initializeFloor() {
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

		//this->rooms[0] = new Room(0);
		for(int i = 3; i < 7; i++) {
			for(int j = 3; j < 27; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[0];
				//cout << i << "," << j <<  endl; 
				this->ground.push_back(new Coordinates(i, j));
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
			this->theGrid[i][24].setThing(new Wall("vertical_wall"));
			this->theGrid[i][24].notifyDisplay(*(this->td));	
		}

		// Door Right
		delete this->theGrid[20][24].thing;
		this->theGrid[20][24].setThing(new Door);
		this->theGrid[20][24].notifyDisplay(*(this->td));

		// Hrozontal walls
		for(int i = 4; i < 24; i++) {
			this->theGrid[14][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[14][i].notifyDisplay(*(this->td));
			this->theGrid[22][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[22][i].notifyDisplay(*(this->td));	
		}

		//this->rooms[1] = new Room(1);
		for(int i = 15; i < 22; i++) {
			for(int j = 4; j < 24; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[1];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}

		// Door Top
		delete this->theGrid[14][13].thing;
		this->theGrid[14][13].setThing(new Door);
		this->theGrid[14][13].notifyDisplay(*(this->td));




	// Room-3
		// Vertical walls
		for(int i = 9; i < 14; i++) {
			this->theGrid[i][38].setThing(new Wall("vertical_wall"));
			this->theGrid[i][38].notifyDisplay(*(this->td));
			this->theGrid[i][51].setThing(new Wall("vertical_wall"));
			this->theGrid[i][51].notifyDisplay(*(this->td));
		}

		// Hrozontal walls
		for(int i = 39; i < 51; i++) {
			this->theGrid[9][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[9][i].notifyDisplay(*(this->td));
			this->theGrid[13][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[13][i].notifyDisplay(*(this->td));	
		}

		//this->rooms[2] = new Room(2);
		for(int i = 10; i < 13; i++) {
			for(int j = 39; j < 51; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[2];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}

		// Door Top
		delete this->theGrid[9][44].thing;
		this->theGrid[9][44].setThing(new Door);
		this->theGrid[9][44].notifyDisplay(*(this->td));

		// Door Bottom
		delete this->theGrid[13][44].thing;
		this->theGrid[13][44].setThing(new Door);
		this->theGrid[13][44].notifyDisplay(*(this->td));


	// Room-4
		// Vertical walls
		for(int i = 18; i < 23; i++) {
			this->theGrid[i][36].setThing(new Wall("vertical_wall"));
			this->theGrid[i][36].notifyDisplay(*(this->td));
			this->theGrid[i][77].setThing(new Wall("vertical_wall"));
			this->theGrid[i][77].notifyDisplay(*(this->td));
		}

		for(int i = 15; i < 18; i++) {
			this->theGrid[i][65].setThing(new Wall("vertical_wall"));
			this->theGrid[i][65].notifyDisplay(*(this->td));
			this->theGrid[i][77].setThing(new Wall("vertical_wall"));
			this->theGrid[i][77].notifyDisplay(*(this->td));
		}
		this->theGrid[18][65].setThing(new Wall("vertical_wall"));
		this->theGrid[18][65].notifyDisplay(*(this->td));

		// Hrozontal walls
		for(int i = 37; i < 65; i++) {
			this->theGrid[18][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[18][i].notifyDisplay(*(this->td));
			this->theGrid[22][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[22][i].notifyDisplay(*(this->td));	
		}

		for(int i = 66; i < 77; i++) {
			this->theGrid[15][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[15][i].notifyDisplay(*(this->td));
			this->theGrid[22][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[22][i].notifyDisplay(*(this->td));	
		}
		this->theGrid[22][65].setThing(new Wall("horizontal_wall"));
		this->theGrid[22][65].notifyDisplay(*(this->td));

		// Doors Top
		delete this->theGrid[18][44].thing;
		this->theGrid[18][44].setThing(new Door);
		this->theGrid[18][44].notifyDisplay(*(this->td));

		delete this->theGrid[15][70].thing;
		this->theGrid[15][70].setThing(new Door);
		this->theGrid[15][70].notifyDisplay(*(this->td));

		delete this->theGrid[20][36].thing;
		this->theGrid[20][36].setThing(new Door);
		this->theGrid[20][36].notifyDisplay(*(this->td));

		// Ground
		//this->rooms[3] = new Room(3);
		for(int i = 19; i < 22; i++) {
			for(int j = 37; j < 66; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[3];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}

		for(int i = 16; i < 22; i++) {
			for(int j = 66; j < 77; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[3];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}


	// // Room-5
		// Vertical walls
		for(int i = 2; i < 8; i++) {
			this->theGrid[i][39].setThing(new Wall("vertical_wall"));
			this->theGrid[i][39].notifyDisplay(*(this->td));
		}
		for(int i = 7; i < 14; i++) {
			this->theGrid[i][61].setThing(new Wall("vertical_wall"));
			this->theGrid[i][61].notifyDisplay(*(this->td));
			this->theGrid[i][77].setThing(new Wall("vertical_wall"));
			this->theGrid[i][77].notifyDisplay(*(this->td));
		}
		this->theGrid[6][74].setThing(new Wall("vertical_wall"));
		this->theGrid[6][74].notifyDisplay(*(this->td));
		this->theGrid[5][74].setThing(new Wall("vertical_wall"));
		this->theGrid[5][74].notifyDisplay(*(this->td));
		this->theGrid[5][71].setThing(new Wall("vertical_wall"));
		this->theGrid[5][71].notifyDisplay(*(this->td));
		this->theGrid[4][71].setThing(new Wall("vertical_wall"));
		this->theGrid[4][71].notifyDisplay(*(this->td));
		this->theGrid[6][77].setThing(new Wall("vertical_wall"));
		this->theGrid[6][77].notifyDisplay(*(this->td));
		for(int i = 2; i < 5; i++) {
			this->theGrid[i][63].setThing(new Wall("vertical_wall"));
			this->theGrid[i][63].notifyDisplay(*(this->td));
		}

		// Hrozontal walls
		for(int i = 40; i < 63; i++) {
			this->theGrid[2][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[2][i].notifyDisplay(*(this->td));
		}
		for(int i = 40; i < 61; i++) {
			this->theGrid[7][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[7][i].notifyDisplay(*(this->td));
		}
		for(int i = 62; i < 77; i++) {
			this->theGrid[13][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[13][i].notifyDisplay(*(this->td));
		}
		for(int i = 64; i < 71; i++) {
			this->theGrid[4][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[4][i].notifyDisplay(*(this->td));
		}
		for(int i = 72; i < 74; i++) {
			this->theGrid[5][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[5][i].notifyDisplay(*(this->td));
		}
		for(int i = 75; i < 77; i++) {
			this->theGrid[6][i].setThing(new Wall("horizontal_wall"));
			this->theGrid[6][i].notifyDisplay(*(this->td));
		}

		// Ground
		//this->rooms[4] = new Room(4);
		for(int i = 3; i < 7; i++) {
			for(int j = 40; j < 63; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[4];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}
		for(int i = 7; i < 13; i++) {
			for(int j = 62; j < 77; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[4];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}
		for(int i = 5; i < 7; i++) {
			for(int j = 63; j < 71; j++) {
				this->theGrid[i][j].setThing(new Ground);
				this->theGrid[i][j].notifyDisplay(*(this->td));
				this->theGrid[i][j].room = this->rooms[4];
				this->ground.push_back(new Coordinates(i, j));
			}	
		}
		for(int i = 71; i < 74; i++) {
			this->theGrid[6][i].setThing(new Ground);
			this->theGrid[6][i].notifyDisplay(*(this->td));	
			this->theGrid[6][i].room = this->rooms[4];
			this->ground.push_back(new Coordinates(6, i));
		}

		// Doors Bottom
		delete this->theGrid[13][70].thing;
		this->theGrid[13][70].setThing(new Door);
		this->theGrid[13][70].notifyDisplay(*(this->td));

		delete this->theGrid[7][44].thing;
		this->theGrid[7][44].setThing(new Door);
		this->theGrid[7][44].notifyDisplay(*(this->td));

		//Door Left
		delete this->theGrid[4][39].thing;
		this->theGrid[4][39].setThing(new Door);
		this->theGrid[4][39].notifyDisplay(*(this->td));
		
		delete this->theGrid[11][61].thing;
		this->theGrid[11][61].setThing(new Door);
		this->theGrid[11][61].notifyDisplay(*(this->td));



		// Passages
		for(int i = 8; i < 14; i++) {
			this->theGrid[i][13].setThing(new Passage);
			this->theGrid[i][13].notifyDisplay(*(this->td));			
		}
		for(int i = 14; i < 31; i++) {
			this->theGrid[11][i].setThing(new Passage);
			this->theGrid[11][i].notifyDisplay(*(this->td));			
		}
		for(int i = 8; i < 20; i++) {
			this->theGrid[i][31].setThing(new Passage);
			this->theGrid[i][31].notifyDisplay(*(this->td));			
		}
		for(int i = 25; i < 36; i++) {
			this->theGrid[20][i].setThing(new Passage);
			this->theGrid[20][i].notifyDisplay(*(this->td));			
		}
		for(int i = 32; i < 45; i++) {
			this->theGrid[8][i].setThing(new Passage);
			this->theGrid[8][i].notifyDisplay(*(this->td));			
		}
		for(int i = 5; i < 8; i++) {
			this->theGrid[i][33].setThing(new Passage);
			this->theGrid[i][33].notifyDisplay(*(this->td));			
		}
		for(int i = 28; i < 39; i++) {
			this->theGrid[4][i].setThing(new Passage);
			this->theGrid[4][i].notifyDisplay(*(this->td));			
		}
		for(int i = 32; i < 44; i++) {
			this->theGrid[16][i].setThing(new Passage);
			this->theGrid[16][i].notifyDisplay(*(this->td));			
		}
		for(int i = 45; i < 56; i++) {
			this->theGrid[16][i].setThing(new Passage);
			this->theGrid[16][i].notifyDisplay(*(this->td));			
		}
		for(int i = 14; i < 18; i++) {
			this->theGrid[i][44].setThing(new Passage);
			this->theGrid[i][44].notifyDisplay(*(this->td));			
		}
		for(int i = 11; i < 17; i++) {
			this->theGrid[i][56].setThing(new Passage);
			this->theGrid[i][56].notifyDisplay(*(this->td));			
		}
		for(int i = 57; i < 61; i++) {
			this->theGrid[11][i].setThing(new Passage);
			this->theGrid[11][i].notifyDisplay(*(this->td));			
		}
		this->theGrid[14][70].setThing(new Passage);
		this->theGrid[14][70].notifyDisplay(*(this->td));
}

Character* Grid::generateCharacter(char type) {
	int pos = rand() % this->ground.size();
	int x = this->ground[pos]->x;
	int y = this->ground[pos]->y;
	cout << x << "," << y << endl;
	this->theGrid[x][y].room.isOccupied = true;
	delete this->theGrid[x][y].thing;
	Orc* orc = new Orc;
	orc->x = x;
	orc->y = y;
	orc->grid = this; 
	this->theGrid[x][y].setThing(orc);
	this->theGrid[x][y].notifyDisplay(*(this->td));
	return orc;
}

ostream& operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}