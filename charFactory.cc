#include "charFactory.h"

CharacterFactory::CharacterFactory() {}
CharacterFactory::~CharacterFactory() {}

Character* CharacterFactory::makeCharacter(char type) {
	Character* c;
	if(type == 'o') {
		c = new Orc;
	}
	else if(type == 'd') {
		c = new Dwarf;
	}
	else if(type == 'h') {
		c = new Human;
	}
	else if(type == 'e') {
		c = new Elf;
	}
	else if(type == 'w') {
		c = new Werewolf;
	}
	return c;
}