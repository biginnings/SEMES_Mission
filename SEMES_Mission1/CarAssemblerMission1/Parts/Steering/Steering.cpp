#pragma once

#include <string>

class Steering {
public:

	virtual ~Steering() {};
	virtual std::string getBrandName() const = 0;
};