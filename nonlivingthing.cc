#include "nonlivingthing.h"
#include <iostream>
#include <string>

using namespace std;

NonLivingThing::NonLivingThing(std::string type) : Thing(type) {}
NonLivingThing::~NonLivingThing() {}