#ifndef __CHAR_FACTORY_H__
#define __CHAR_FACTORY_H__

#include "character.h"
#include "orc.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "werewolf.h"

class CharacterFactory {
public:
	CharacterFactory();
	Character* makeCharacter(char type);
	~CharacterFactory();
};

#endif