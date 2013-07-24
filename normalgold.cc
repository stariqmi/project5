#include "normalgold.h"

NormalGold::NormalGold() : Treasure(1, "normalgold") {}

int NormalGold::giveGold() { return gold; }