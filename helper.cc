#include "helper.h"

using namespace std;

Helper::Helper() {}

Coordinates* Helper::evalDirection(string direction, int i, int j) {
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

bool Helper::checkForPotion(Grid* grid, int x, int y) {
	if(grid->theGrid[x][y].thing != NULL && grid->theGrid[x][y].thing->type == "potion") {
		return true;
	}
	else {
		return false;
	}
}

string Helper::evaluateMove(Grid* grid, Character* player, string dir, int gold, string move) {
	if(move == "gold") {
		string result;
		int goldGained = player->gold - gold;
		ostringstream stream;
		stream << "Picked up " << goldGained << " gold";
		result = stream.str();
		return result;
	}
	else if(move  == "finish") {
		return "You have finished the game!";
	}
	else if(move == "empty") {
		return "Invalid move outside playable region";
	}
	else if(move == "invalid") {
		return "Invalid move (wall/enemy/potion)";
	}
	else {
		string direction;
		if(dir == "ea") direction = "East";
		if(dir == "we") direction = "West";
		if(dir == "so") direction = "South";
		if(dir == "no") direction = "North";
		if(dir == "ne") direction = "NorthEast";
		if(dir == "se") direction = "SouthEast";
		if(dir == "nw") direction = "NorthWest";
		if(dir == "sw") direction = "SouthWest";
		Coordinates* coords = evalDirection(dir, player->x, player->y);
		if(grid->theGrid[coords->x][coords->y].thing->type == "potion") {
			return "PC moved " + direction + ", sees an unknown potion";
		}
		// else if(grid->theGrid[coords->x][coords->y].thing->type != "ground") {
		// 	return "PC moved " + direction + ", sees a " + grid->theGrid[coords->x][coords->y].thing->type;	
		// }
		else {
			return "PC moved " + direction;
		}
	}
}
