#pragma once

#include "../../include.h"

class MobisSteering : public Steering {
public:
	MobisSteering() {};
	~MobisSteering() {};

	std::string getBrandName() const override {
		return "Mobis";
	}
};