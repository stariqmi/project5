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
	else if(type == 'v') {
		c = new Vampire;
	}
	else if(type == 't') {
		c = new Troll;
	}
	else if(type == 'g') {
		c = new Goblin;
	}
	else if(type == 'm') {
		c = new Merchant;
	}
	else if(type == 'p') {
		c = new Phoenix;
	}
	else if(type == 'r') {
		c = new Dragon;
	}
	return c;
}