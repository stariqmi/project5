#include "textdisplay.h"
#include <iostream>

using namespace std;

/*
 * Constructor
 * @params n, a int representing the size of the grid
 */
TextDisplay::TextDisplay(int x, int y): xsize(x), ysize(y) {
	this->theDisplay = new char*[y];

	// Loop to initialize a grid of chars
	for(int i = 0; i < y; i++) {
		this->theDisplay[i] = new char[x];
		for(int j = 0; j < x; j++) {
			this->theDisplay[i][j] = ' ';	// Set the initial char to _, representing dead
		} // for
	} // for
}

// Destructor
TextDisplay::~TextDisplay() {
	for(int i = 0; i < this->ysize; i++) {
		delete[] this->theDisplay[i];
	} // for
	delete[] this->theDisplay;
}

/*
 * notifies the character grid to change a character
 * @params r, int for row
 * @params c, int for column
 * @params ch, char for status
 */
void TextDisplay::notify(int r, int c, char ch) {
	this->theDisplay[r][c] = ch;
}

void TextDisplay::clearDisplay() {
	for(int i = 0; i < this->ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			this->theDisplay[i][j] = ' ';
		}
	}
}

// overloading the output operator
ostream &operator<<(ostream& out, const TextDisplay &td) {
	
	// Loop to print out each character
	for(int i = 0; i < td.ysize; i++) {
		for(int j = 0; j < td.xsize; j++) {
			out << td.theDisplay[i][j];
		} // for
		out << endl;
	} // for
	return out;
}