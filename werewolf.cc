#include <iostream>
#include "werewolf.h"
#include "grid.h"
#include <string>
using namespace std;

Werewolf::Werewolf() {
	hp = 120;
	atk = 30;
	def = 5;
	isAttacked = False;
}

void Werewolf::attack(int x, int y) {} 

void Werewolf::setAttack(){}