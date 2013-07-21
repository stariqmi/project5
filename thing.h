#ifndef __THING_H__
#define __THING_H__

#include <string>

class Thing
{
public:
	std::string type;
	Thing();
	virtual ~Thing();
};

#endif