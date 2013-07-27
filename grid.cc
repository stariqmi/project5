#include "grid.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Grid::Grid(TextDisplay* td, int x, int y): layout("floor.txt"), theGrid(NULL), td(td), xsize(x), ysize(y), level(1), charFactory(new CharacterFactory), itemFactory(new ItemFactory) {}

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

void Grid::setGold() {
	string directions[4] = {"we", "no", "ea", "so"};
	ifstream file(layout.c_str());
	for(int i = 0; i < 25; i++) {
		string line;
		getline(file, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == 'G') {
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(new Treasure(0, "gold"));
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
		}
	}
	int dragonCount = 0;
	file.close();
	ifstream file2(layout.c_str());
	for(int i = 0; i < 25; i++) {
		string line;
		getline(file2, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == 'D') {
				dragonCount++;
				delete theGrid[i][j].thing;
				Character* enemy = charFactory->makeCharacter('r');
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
				bool toProtect = true;
				int z = 0;
				while(toProtect) {
					Coordinates* c = evalDirection(directions[z], i, j);
					if(theGrid[c->x][c->y].thing->type == "gold") {
						Treasure* treasure = dynamic_cast<Treasure*>(theGrid[c->x][c->y].thing);
						if(treasure->treasureType == "gold") {
							toProtect = false;
							delete theGrid[c->x][c->y].thing;
							Item* treasure2 = itemFactory->makeItem("DH");
							theGrid[c->x][c->y].setThing(treasure2);
							DragonHorde* dh = dynamic_cast<DragonHorde*>(treasure2);
							dh->protector = &(theGrid[i][j]);
							theGrid[c->x][c->y].isOccupied = true;
							theGrid[c->x][c->y].notifyDisplay(*td);
							Dragon* dragon = dynamic_cast<Dragon*>(enemy);
							dragon->treasureLocation = &(theGrid[c->x][c->y]);
						}
					}
					delete c;
					z++;
				}
			}
		}
	}
	file2.close();
	ifstream file3(layout.c_str());
	vector<string> goldTypes;
	goldTypes.push_back("DH");
	goldTypes.push_back("SH");
	goldTypes.push_back("SH");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	for (int i = 0; i < 25; i++) {
		string line;
		getline(file3, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == 'G') {
				Treasure* t = dynamic_cast<Treasure*>(theGrid[i][j].thing);
				if(t->treasureType == "gold") {
					bool find = true;
					while(find) {
						srand(time(0));
						int pos = rand() % + goldTypes.size();
						if(goldTypes[pos] != "DH") {
							delete theGrid[i][j].thing;
							theGrid[i][j].setThing(itemFactory->makeItem(goldTypes[pos]));
							theGrid[i][j].isOccupied = true;
							theGrid[i][j].notifyDisplay(*td);
							find = false;
						}
					}
				}
			}
		}
	}
}

void Grid::setPotions() {
	vector<string> potionTypes;
	potionTypes.push_back("RH");
	potionTypes.push_back("PH");
	potionTypes.push_back("BA");
	potionTypes.push_back("BD");
	potionTypes.push_back("WA");
	potionTypes.push_back("WD");

	vector<string> potions;
	for(int i = 0; i < 10; i++) {
		int pPos = rand() % + potionTypes.size();
		//cout << potionTypes[pPos] << endl;
		potions.push_back(potionTypes[pPos]);
	}
	//cout << "potions selected" << endl;
	ifstream file(layout.c_str());
	for(int i = 0; i < 25; i++) {
		string line;
		getline(file, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == 'P') {
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(itemFactory->makeItem(potions[potions.size() - 1]));
				potions.pop_back();
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
		}
	}
	file.close();
}

void Grid::setLayout(char type) {
	ifstream file(layout.c_str());
	for(int i = 0; i < 25; i++) {
		string line;
		getline(file, line);
		for(int j = 0; j < 80; j++) {
			if(line[j] == 'N') {
				Character* enemy = charFactory->makeCharacter('g');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == 'X') {
				Character* enemy = charFactory->makeCharacter('x');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == 'W') {
				Character* enemy = charFactory->makeCharacter('w');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == 'V') {
				Character* enemy = charFactory->makeCharacter('v');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == 'T') {
				Character* enemy = charFactory->makeCharacter('t');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '/') {
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(new Stairway);
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == 'M') {
				Character* enemy = charFactory->makeCharacter('m');
				delete theGrid[i][j].thing;
				theGrid[i][j].setThing(enemy);
				enemy->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			else if(line[j] == '@') {
				delete theGrid[i][j].thing;
				player =  charFactory->makeCharacter(type);
				theGrid[i][j].setThing(player);
				player->x = i;
				player->y = j;
				player->grid = this;
				theGrid[i][j].isOccupied = true;
				theGrid[i][j].notifyDisplay(*td);
			}
			//file.close();
			//setPotions();
			//setGold();
		}
	}
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

		if(layout == "floor.txt") {		
			//cout << "normal layout" << endl;
			player = generateCharacter(type);
			generateStairway();
			generateGold();
			generatePotions();
			generateEnemies();
		}
		else {
			//cout << "command line layout" << endl;
			setLayout(type);
			setPotions();
			setGold();
		}
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
	goldTypes.push_back("SH");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
	goldTypes.push_back("NG");
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
				Character* dragon;
				while(check && radius.size()) {
					int npos = rand() % + radius.size();
					coords = evalDirection(radius[npos], x, y);
					xc = coords->x;
					yc = coords->y;
					radius.erase(radius.begin() + npos);
					if(!(theGrid[coords->x][coords->y].isOccupied)) {
 						delete theGrid[coords->x][coords->y].thing;
 						dragon = charFactory->makeCharacter('r');
 						dragon->grid = this;
						theGrid[coords->x][coords->y].setThing(dragon);
						theGrid[coords->x][coords->y].isOccupied = true;
						theGrid[coords->x][coords->y].notifyDisplay(*td);
						found = true;
						check = false;
					}
					else {}
					delete coords;
				}
				if(!found) {
					i--;
				}
				else {
					Item* gold;
					gold = itemFactory->makeItem(goldTypes[pos]);
					DragonHorde* dh = dynamic_cast<DragonHorde*>(gold);
					dh->protector = &(theGrid[xc][yc]);
					delete theGrid[x][y].thing;
					theGrid[x][y].setThing(gold);
					theGrid[x][y].isOccupied = true;
					theGrid[x][y].notifyDisplay(*td);		
					Dragon* protector = dynamic_cast<Dragon*>(dragon);
					protector->treasureLocation = &(theGrid[x][y]);
				}
			}
			else {
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

string Grid::enemyAI() {
	int counter = 0;
	string s;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (theGrid[i][j].thing != NULL && 
				theGrid[i][j].thing->type != "vertical_wall" && 
				theGrid[i][j].thing->type != "horizontal_wall" && 
				theGrid[i][j].thing->type != "character" && 
				theGrid[i][j].thing->type != "ground" && 
				theGrid[i][j].thing->type != "potion" && 
				theGrid[i][j].thing->type != "dragon" && 
				theGrid[i][j].thing->type != "gold" && 
				theGrid[i][j].thing->type != "door" &&
				theGrid[i][j].thing->type != "stairway" && 
				theGrid[i][j].thing->type != "passage")
			 {
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
					int damage;
					for(int k=0; k < radius.size(); k++) {
							coords = evalDirection(radius[k],i,j);
							int cx = coords->x;
							int cy = coords->y;
							delete coords;
							if((theGrid[cx][cy].thing->type) == "character") {
								if(enemy->type == "merchant"){
									Merchant* merchant = dynamic_cast<Merchant*>(enemy);
									srand(time(NULL));
									int hit = rand() % + 2;
									
									if(merchant->isHostile == true && hit){
										damage = merchant->attack(cx, cy);
										ostringstream os;
										os <<"Update:"<< enemy->raceID << " deals " << damage << " damage to PC";
										s = os.str();
										cout << s << endl;
										cout << *this;
										return s;
									}
								}
							else {	srand(time(NULL));
									int hit = rand() % + 2;
									if(hit) {
												damage = enemy->attack(cx, cy);
												ostringstream os;
												os <<"Update: " << enemy->raceID << " deals " << damage << " damage to PC";
												s = os.str();
												cout << s << endl;
												cout << *this;
												return s;
											} 
								}					
							}	
						}
					
					while(check && radius.size()) {
						//cout << " " << z << " ";
						//cout << theGrid[i][j].thing->type;
						int npos = rand() % + radius.size();
						coords = evalDirection(radius[npos], i, j);
						int cx = coords->x;
						int cy = coords->y;
						delete coords;
						radius.erase(radius.begin() + npos);
						if(!(theGrid[cx][cy].isOccupied)) {
							enemy->isMoved = true;
							string originalType = theGrid[cx][cy].thing->type;
							delete theGrid[cx][cy].thing;
							//cout << " check3";
							theGrid[cx][cy].setThing(theGrid[i][j].thing);
							//cout << " check4 ";
							theGrid[i][j].setThing(new Ground);
							enemy->standingOn = originalType;
							//cout << " check6";
							theGrid[cx][cy].isOccupied = true;
							theGrid[i][j].isOccupied = false;
							theGrid[i][j].notifyDisplay(*(td));
							theGrid[cx][cy].notifyDisplay(*td);
							//found = true;
							check = false;
							z++;
						}
					counter++;
					}
				}
			}
		}
	}
	cout << *this;
	return s;
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