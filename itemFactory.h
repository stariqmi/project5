#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__

#include "boostattack.h"
#include "boostdefence.h"
#include "woundattack.h"
#include "wounddefence.h"
#include "boosthealth.h"
#include "poisonhealth.h"
#include "merchanthorde.h"
#include "smallhorde.h"
#include "dragonhorde.h"
#include "normalgold.h"
#include <string>

class ItemFactory {
public:
	ItemFactory();
	Item* makeItem(std::string type);
	~ItemFactory();
};

#endif