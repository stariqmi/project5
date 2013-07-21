#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include "textdisplay.h"
#include "nonlivingthing.h"

class Tile {
  
  int r, c;                             // r indicates row, c indicates column
public:
  Tile();                               // Default constructor
  Thing* thing;
  void setCoords(int r, int c);         // Sets the grid coordinates for the cell
  void notifyDisplay(TextDisplay &t);   // Notifies the text display, i.e changes the character at coordinates 
  void setThing(Thing* thing);
};

#endif