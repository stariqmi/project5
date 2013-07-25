#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "thing.h"
#include "tile.h"
#include "wall.h"
#include "door.h"
#include "ground.h"
#include "passage.h"
#include "stairway.h"
#include "room.h"
#include "textdisplay.h"
#include "coordinates.h"
#include "combatMediator.h"
#include "charFactory.h"
#include "itemFactory.h"

class Grid {
public:
	Tile** theGrid;
	int xsize;
	int ysize;
	int level;
	CharacterFactory* charFactory;
	ItemFactory* itemFactory;
	TextDisplay* td;
	Room rooms[5];
	Character* player;
	CombatMediator* combatMediator;
	//std::vector<Coordinates*> ground;
	Grid(TextDisplay* td, int x, int y);
	~Grid();
	void clearGrid();
	void initializeFloor(char type);
	void generateStairway();
	Coordinates* evalDirection(std::string dir, int i, int j);
	Character* generateCharacter(char type);
	Character* generateEnemies();
	void generatePotions();
	void generateGold();
	friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif