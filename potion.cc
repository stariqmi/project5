#include "potion.h"

using namespace std;

Potion::Potion(string effect, string effectOn, int magnitude) : effect(effect), effectOn(effectOn), magnitude(magnitude) {
	type = "potion";
}

string Potion::getEffect() {
	return effect;
}

Potion::~Potion() {}