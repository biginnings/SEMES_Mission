#include "../../include.h"

#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

class CarFactory {
public:
    static Car* createCar(const CarType& type) {
        if (type == CarType::SEDAN) return new Sedan();
        else if (type == CarType::SUV) return new Suv();
        else if (type == CarType::TRUCK) return new Truck();
        else throw InvalidCarTypeException(type);
    }
};

#endif