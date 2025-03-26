#include "../../include.h"

class Sedan : public Car {
public:
	CarType getCarType() {
		return CarType::SEDAN;
	};
};