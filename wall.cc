#include "wall.h"
#include <iostream>
#include <string>

using namespace std;

Wall::Wall(string type) : NonLivingThing(type) {}
Wall::~Wall() {}