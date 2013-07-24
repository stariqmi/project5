#include "merchanthorde.h"

MerchantHorde::MerchantHorde() : Treasure(4, "merchanthorde") {}

int MerchantHorde::giveGold() { return gold; }