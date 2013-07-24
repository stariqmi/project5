#include "smallhorde.h"

SmallHorde::SmallHorde() : Treasure(2, "smallhorde") {}

int SmallHorde::giveGold() { return gold; }