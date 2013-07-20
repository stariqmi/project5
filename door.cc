#include <string>
#include "door.h"
using namespace std;

const string type = "door";

Door::Door() : NonLivingThing(type) {}
Door::~Door() {}