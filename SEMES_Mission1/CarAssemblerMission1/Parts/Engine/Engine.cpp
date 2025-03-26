#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
public:
	virtual ~Engine() {}
	virtual std::string getBrandName() const = 0;
};

#endif