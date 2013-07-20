#include <string>
#include "ground.h"
using namespace std;

const string type = "ground";

Ground::Ground() : NonLivingThing(type) {}
Ground::~Ground() {}