#include "../../include.h"

class Truck : public Car {
public:
	CarType getCarType() {
		return CarType::TRUCK;
	};
};