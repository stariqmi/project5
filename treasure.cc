#include "treasure.h"
using namespace std;

Treasure::Treasure(int gold, string treasureType) : gold(gold), treasureType(treasureType) { type = "gold"; }
int Treasure::giveGold() { return 0; }
Treasure::~Treasure() {}