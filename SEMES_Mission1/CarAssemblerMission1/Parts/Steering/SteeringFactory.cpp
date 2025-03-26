#pragma once

#include "../../include.h"

class SteeringFactory {
public:
	static Steering* createSteering(SteeringType steeringType) {
		if (steeringType == SteeringType::MOBIS) return new MobisSteering();
		else if (steeringType == SteeringType::BOSCH) return new BoschSteering();
	}
};