#include "../../include.h"

#ifndef CAR_INTERFACE_H
#define CAR_INTERFACE_H

class Car {
protected:
	EngineType engineType;
	BreakType breakType;
	SteeringType steeringType;

	Engine* engine = nullptr;
	Break* breakSystem = nullptr;
	Steering* steering = nullptr;

public:
	virtual ~Car() = default;
	int selectEngine();
	int selectBreakSystem();
	int selectSteeringSystem();
	void runProducedCar();
	void testProducedCar();
	EngineType getEngineType();
	BreakType getBreakType();
	SteeringType getSteeringType();
	virtual std::string getCarType() = 0;
};

#endif