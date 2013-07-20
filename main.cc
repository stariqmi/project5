#include <iostream>
#include <string>

#include "grid.h"
#include "textdisplay.h"
#include "tile.h"
#include "thing.h"
#include "wall.h"

using namespace std;

const int xsize = 80;
const int ysize = 25;

int main() {
	TextDisplay* td = new TextDisplay(xsize, ysize);
	Grid* grid = new Grid(td, xsize, ysize);

	


	grid->init();
	cout << *grid;
	



	delete grid;
}