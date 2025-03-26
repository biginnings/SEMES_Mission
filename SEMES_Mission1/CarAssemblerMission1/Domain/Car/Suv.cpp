#include "../../include.h"

class Suv : public Car {
public:
	CarType getCarType() {
		return CarType::SUV;
	};
};