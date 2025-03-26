#pragma once

#include "../../include.h"

class BoschSteering : public Steering {
public:
	BoschSteering() {};
	~BoschSteering() {};

	std::string getBrandName() const override {
		return "Bosch";
	}
};