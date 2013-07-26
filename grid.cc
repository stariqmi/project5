#include "grid.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Grid::Grid(TextDisplay* td, int x, int y): theGrid(NULL), td(td), xsize(x), ysize(y), level(1), charFactory(new CharacterFactory), itemFactory(new ItemFactory) {}

Grid::~Grid() {
	this->clearGrid();
	delete this->td;
	delete charFactory;
	delete itemFactory;
	delete combatMediator;
}



void Grid::clearGrid() {
	// for(int i = 0; i < this->ysize; i++) {
	// 	for(int j = 0; j < this->xsize; j++) {
	// 		if(theGrid[i][j].thing) {
	// 			delete theGrid[i][j].thing;
	// 		}
	// 	}
	// }
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
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '-') {
				theGrid[i][j].setThing(new Wall("horizontal_wall"));
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '+') {
				theGrid[i][j].setThing(new Door);
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '.') {
				theGrid[i][j].setThing(new Ground);
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '#') {
				theGrid[i][j].setThing(new Passage);
				theGrid[i][j].isOccupied = true;
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
		generateGold();
		generatePotions();
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
	Character* character;
	character = charFactory->makeCharacter(type);
	character->x = x;
	character->y = y;
	theGrid[x][y].setThing(character);
	character->grid = this; 
	theGrid[x][y].notifyDisplay(*(this->td));
	return character;
}

void Grid::generateStairway() {
	vector<Room> unoccupiedRooms; 
	
	for(int i = 0; i < 5; i++) {
		if(!rooms[i].isOccupied) {
			unoccupiedRooms.push_back(rooms[i]);
		}
	}

	srand(time(NULL));
	int pos = rand() % + unoccupiedRooms.size();
	srand(time(NULL));
	int pos2 = rand() % + unoccupiedRooms[pos].tiles.size();
	int x = unoccupiedRooms[pos].tiles[pos2]->x;
	int y = unoccupiedRooms[pos].tiles[pos2]->y;

	delete theGrid[x][y].thing;
	theGrid[x][y].setThing(new Stairway);
	theGrid[x][y].notifyDisplay(*td);
	theGrid[x][y].isOccupied = true;
}


Character* Grid::generateEnemies(){
	for(int i = 0; i < 20; i++) {
		string probString = "wwwwvvvgggggttxxmm";
		int typePos = rand() % + 18;
		//srand(time(NULL));
		int pos = rand() % + 5;
		//cout << pos << endl;
		//srand(time(NULL));
		int pos2 = rand() % + rooms[pos].tiles.size();
		//cout << pos2 << endl;
		int x = rooms[pos].tiles[pos2]->x;
		int y = rooms[pos].tiles[pos2]->y;
		if(theGrid[x][y].isOccupied) {
 			i--; 
			//continue;
		}
		else {
			delete theGrid[x][y].thing;
			Character* enemy = charFactory->makeCharacter(probString[typePos]);
			enemy->grid = this;
			theGrid[x][y].setThing(enemy);
			theGrid[x][y].isOccupied = true;
			theGrid[x][y].notifyDisplay(*td);
		}
	}
	
}

void Grid::generatePotions() {
	vector<string> potionTypes;
	potionTypes.push_back("RH");
	potionTypes.push_back("PH");
	potionTypes.push_back("BA");
	potionTypes.push_back("BD");
	potionTypes.push_back("WA");
	potionTypes.push_back("WD");

	for(int i = 0; i < 10; i++) {
		int pos = rand() % + potionTypes.size();
		int pos2 = rand() % + 5;
		int pos3 = rand() % + rooms[pos2].tiles.size();
		
		int x = rooms[pos2].tiles[pos3]->x;
		int y = rooms[pos2].tiles[pos3]->y;
		if(theGrid[x][y].isOccupied) {
			i--; 
			//continue;
		}
		else {
			Item* potion;
			potion = itemFactory->makeItem(potionTypes[pos]);
			delete theGrid[x][y].thing;
			theGrid[x][y].setThing(potion);
			theGrid[x][y].isOccupied = true;
			theGrid[x][y].notifyDisplay(*td);
		}
	}

}

Coordinates* Grid::evalDirection(string direction, int i, int j) {
	Coordinates* c;
	if(direction == "no") {
		c = new Coordinates(i - 1, j);
	}
	else if(direction == "so") {
		c = new Coordinates(i + 1, j);
	}
	else if(direction == "we") {
		c = new Coordinates(i, j - 1);
	}
	else if(direction == "ea") {
		c = new Coordinates(i, j + 1);
	}
	else if(direction == "sw") {
		c = new Coordinates(i + 1, j - 1);
	}
	else if(direction == "se") {
		c = new Coordinates(i + 1, j + 1);
	}
	else if(direction == "nw") {
		c = new Coordinates(i - 1, j - 1);
	}
	else if(direction == "ne") {
		c = new Coordinates(i - 1, j + 1);
	}
	return c;
}

void Grid::generateGold() {
	vector<string> goldTypes;
	goldTypes.push_back("DH");
	goldTypes.push_back("SH");
	goldTypes.push_back("NG");
	for (int i = 0; i < 10; i++) {
		int pos = rand() % + goldTypes.size();
		int pos2 = rand() % + 5;
		int pos3 = rand() % + rooms[pos2].tiles.size();

		int x = rooms[pos2].tiles[pos3]->x;
		int y = rooms[pos2].tiles[pos3]->y;
		if(theGrid[x][y].isOccupied) {
			i--; 
			//continue;
		}
		else {
		
			if(goldTypes[pos] == "DH") {
				//cout << goldTypes[pos] << endl;
				vector<string> radius;
				radius.push_back("no");
				radius.push_back("so");
				radius.push_back("ea");
				radius.push_back("we");
				bool found = false;
				bool check = true;
				Coordinates* coords;
				int xc;
				int yc;
				while(check && radius.size()) {
					int npos = rand() % + radius.size();
					coords = evalDirection(radius[npos], x, y);
					xc = coords->x;
					yc = coords->y;
					radius.erase(radius.begin() + npos);
					if(!(theGrid[coords->x][coords->y].isOccupied)) {
						// cout << "dragon" << endl;
						// std::cout << "not isOccupied" << std::endl;
						// cout << x << "," << y <<  endl;
						// cout << coords->x << "," << coords->y <<  endl;
 						delete theGrid[coords->x][coords->y].thing;
 						Character* dragon = charFactory->makeCharacter('r');
 						dragon->grid = this;
						theGrid[coords->x][coords->y].setThing(dragon);
						theGrid[coords->x][coords->y].isOccupied = true;
						theGrid[coords->x][coords->y].notifyDisplay(*td);
						found = true;
						check = false;
					}
					else {
						//std::cout << "isOccupied" << std::endl;							
					}
					delete coords;
				}
				if(!found) {
					i--;
				}
				else {
					//cout << "dragon hoard" << endl;
					Item* gold;
					gold = itemFactory->makeItem(goldTypes[pos]);
					DragonHorde* dh = dynamic_cast<DragonHorde*>(gold);
					dh->protector = &(theGrid[xc][yc]);
					delete theGrid[x][y].thing;
					theGrid[x][y].setThing(gold);
					theGrid[x][y].isOccupied = true;
					theGrid[x][y].notifyDisplay(*td);		
				}
				//delete coords;
			}
			else {
				//cout << goldTypes[pos] << endl;
				Item* gold;
				gold = itemFactory->makeItem(goldTypes[pos]);
				delete theGrid[x][y].thing;
				theGrid[x][y].setThing(gold);
				theGrid[x][y].isOccupied = true;
				theGrid[x][y].notifyDisplay(*td);
			}
		}	
	}	
}

void Grid::enemyAI() {
	int counter = 0;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if(	theGrid[i][j].thing != NULL && 
				theGrid[i][j].thing->type != "vertical_wall" && 
				theGrid[i][j].thing->type != "horizontal_wall" && 
				theGrid[i][j].thing->type != "character" && 
				theGrid[i][j].thing->type != "ground" && 
				theGrid[i][j].thing->type != "potion" && 
				theGrid[i][j].thing->type != "dragon" && 
				theGrid[i][j].thing->type != "gold" && 
				theGrid[i][j].thing->type != "door" &&
				theGrid[i][j].thing->type != "stairway" && 
				theGrid[i][j].thing->type != "passage"
			) {
				Character* enemy = dynamic_cast<Character*>(theGrid[i][j].thing);
				if(enemy->isMoved) {
					enemy->isMoved = false;
				}
				else{
					vector<string> radius;
					radius.push_back("no");
					radius.push_back("ne");
					radius.push_back("nw");
					radius.push_back("so");
					radius.push_back("se");
					radius.push_back("sw");
					radius.push_back("ea");
					radius.push_back("we");
					bool found = false;
					bool check = true;
					Coordinates* coords;
					int z = 0;
					while(check && radius.size()) {
						//cout << " " << z << " ";
						//cout << theGrid[i][j].thing->type;
						int npos = rand() % + radius.size();
						coords = evalDirection(radius[npos], i, j);
						radius.erase(radius.begin() + npos);
						if(!(theGrid[coords->x][coords->y].isOccupied)) {
							enemy->isMoved = true;
							//cout << " check1";
							//cout << " check2";
							string originalType = theGrid[coords->x][coords->y].thing->type;
							delete theGrid[coords->x][coords->y].thing;
							//cout << " check3";
							theGrid[coords->x][coords->y].setThing(theGrid[i][j].thing);
							//cout << " check4 ";
							theGrid[i][j].setThing(new Ground);
							enemy->standingOn = originalType;
							//cout << " check6";
							theGrid[coords->x][coords->y].isOccupied = true;
							theGrid[i][j].isOccupied = false;
							theGrid[i][j].notifyDisplay(*(td));
							theGrid[coords->x][coords->y].notifyDisplay(*td);
							//found = true;
							check = false;
							z++;
					}
					counter++;
					//cout << endl;
					delete coords;
					}
				}
			}
		}
	}
	cout << *this;
}	

ostream& operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	string race;
	switch(g.player->raceID) {
		case 'h':
			race = "Human";
			break;
		case 'e':
			race = "Elf";
			break;
		case 'o':
			race = "Orc";
			break;
		case 'd':
			race = "Dwarf";
			break;
	}
	out << "Race: " << race << " Gold: " << g.player->gold << "                                    Floor: " << g.level << endl;
	out << "HP: " << g.player->hp << endl;
	out << "Atk: " << g.player->atk << endl;
	out << "Def: " << g.player->def << endl;
	return out;
}