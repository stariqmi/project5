#include "grid.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Grid::Grid(TextDisplay* td, int x, int y): td(td), xsize(x), ysize(y), level(1) {
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
	//vector<Coordinates*>::iterator it = this->ground.begin();
	// //cout << this->ground.size() << endl;
	
	for (int i = 0; i < 5; i++) {
		rooms[i].isOccupied = false;
		vector<Coordinates*>::iterator it = rooms[i].tiles.begin();
		while(it != rooms[i].tiles.end()) {
			delete *it;
			it++;
		}
		rooms[i].tiles.clear();
	}
	delete[] this->theGrid;
}

void Grid::initializeFloor(char type) {
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

	ifstream file("floor.txt");
	for(int i = 0; i < 25; i++) {
		string line;
		getline(file, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == '|') {
				theGrid[i][j].setThing(new Wall("vertical_wall"));
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '-') {
				theGrid[i][j].setThing(new Wall("horizontal_wall"));
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '+') {
				theGrid[i][j].setThing(new Door);
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '.') {
				theGrid[i][j].setThing(new Ground);
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '#') {
				theGrid[i][j].setThing(new Passage);
				theGrid[i][j].notifyDisplay(*td);
			}
		}
	}

	

		this->rooms[0].roomNumber = 0;
		for(int i = 3; i < 7; i++) {
			for(int j = 3; j < 27; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[0].tiles.push_back(c);
			}	
		}

		this->rooms[1].roomNumber = 1;
		for(int i = 15; i < 22; i++) {
			for(int j = 4; j < 24; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[1].tiles.push_back(c);
			}	
		}



		this->rooms[2].roomNumber = 2;
		for(int i = 10; i < 13; i++) {
			for(int j = 39; j < 51; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[2].tiles.push_back(c);
			}	
		}

	// 	// Ground
		this->rooms[3].roomNumber = 3;
		for(int i = 19; i < 22; i++) {
			for(int j = 37; j < 66; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[3].tiles.push_back(c);
			}	
		}

		for(int i = 16; i < 22; i++) {
			for(int j = 66; j < 77; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[3].tiles.push_back(c);
			}	
		}

	// 	// Ground
		this->rooms[4].roomNumber = 4;
		for(int i = 3; i < 7; i++) {
			for(int j = 40; j < 63; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[4].tiles.push_back(c);
			}	
		}
		for(int i = 7; i < 13; i++) {
			for(int j = 62; j < 77; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[4].tiles.push_back(c);
			}	
		}
		for(int i = 5; i < 7; i++) {
			for(int j = 63; j < 71; j++) {
				Coordinates* c = new Coordinates(i, j);
				this->rooms[4].tiles.push_back(c);
			}	
		}
		for(int i = 71; i < 74; i++) {	
			Coordinates* c = new Coordinates(6, i);
			this->rooms[4].tiles.push_back(c);
		}

		player = generateCharacter(type);
		generateStairway();
		generateEnemies();
		cout<< *this;
}

Character* Grid::generateCharacter(char type) {
	srand(time(NULL));
	int pos = rand() % + 5;
	//cout << x << "," << y << endl;
	this->rooms[pos].isOccupied = true;
	srand(time(NULL));
	int pos2 = rand() % + this->rooms[pos].tiles.size();
	int x = rooms[pos].tiles[pos2]->x;
	int y = rooms[pos].tiles[pos2]->y;
	theGrid[x][y].isOccupied = true;
	delete theGrid[x][y].thing;
	switch (type) {
		case 'o': 	
					{Orc* orc = new Orc;
					orc->x = x;
					orc->y = y;
					this->theGrid[x][y].setThing(orc);
					orc->grid = this; 
					this->theGrid[x][y].notifyDisplay(*(this->td));
					return orc;}
		case 'h':	
					{Human* human = new Human;
					human->x = x;
					human->y = y;
					this->theGrid[x][y].setThing(human);
					human->grid = this; 
					this->theGrid[x][y].notifyDisplay(*(this->td));
					return human;}
		case 'e': 	{Elf* elf = new Elf;
					elf->x = x;
					elf->y = y;
					this->theGrid[x][y].setThing(elf);
					elf->grid = this; 
					this->theGrid[x][y].notifyDisplay(*(this->td));
					return elf;	}
		case 'd':	{Dwarf* dwarf = new Dwarf;
					dwarf->x = x;
					dwarf->y = y;
					this->theGrid[x][y].setThing(dwarf);
					dwarf->grid = this; 
					this->theGrid[x][y].notifyDisplay(*(this->td));
					return dwarf;}						
	}
	
}

void Grid::generateStairway() {
	vector<Room> unoccupiedRooms; 
	
	for(int i = 0; i < 5; i++) {
		if(!rooms[i].isOccupied) {
			//cout << "added" << endl;
			unoccupiedRooms.push_back(rooms[i]);
		}
	}

	srand(time(NULL));
	int pos = rand() % + 4;

	//cout << "passed" << endl;

	srand(time(NULL));
	int pos2 = rand() % + unoccupiedRooms[pos].tiles.size();
	
	//cout << "passed" << endl;	

	int x = unoccupiedRooms[pos].tiles[pos2]->x;
	int y = unoccupiedRooms[pos].tiles[pos2]->y;

	delete theGrid[x][y].thing;
	theGrid[x][y].setThing(new Stairway);
	theGrid[x][y].notifyDisplay(*td);
	theGrid[x][y].isOccupied = true;
}


Character* Grid::generateEnemies(){
	for(int i = 0; i < 20; i++) {
		//srand(time(NULL));
		int pos = rand() % + 5;
		//cout << pos << endl;
		//srand(time(NULL));
		int pos2 = rand() % + rooms[pos].tiles.size();
		//cout << pos2 << endl;
		int x = rooms[pos].tiles[pos2]->x;
		int y = rooms[pos].tiles[pos2]->y;
		if(theGrid[x][y].isOccupied) {
			//i--; 
			//continue;
		}
		else {
			delete theGrid[x][y].thing;
			theGrid[x][y].setThing(new Werewolf);
			theGrid[x][y].isOccupied = true;
			theGrid[x][y].notifyDisplay(*td);
		}
	}
	
}
ostream& operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	out << "                                                                      Floor: " << g.level << endl;
	out << "  HP: " << g.player->getHealth() << endl;
	return out;
}