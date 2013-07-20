#include <string>
#include "passage.h"
using namespace std;

const string type = "passage";

Passage::Passage() : NonLivingThing(type) {}
Passage::~Passage() {}