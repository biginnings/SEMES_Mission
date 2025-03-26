#include <stdexcept>
#include <string>
#include "../../../include.h"

#ifndef INVALID_CAR_TYPE_EXCEPTION_H
#define INVALID_CAR_TYPE_EXCEPTION_H

class InvalidCarTypeException : public std::runtime_error {
public:
    explicit InvalidCarTypeException(const CarType& type)
        : std::runtime_error("Invalid CarType value: " + std::to_string(static_cast<int>(type))),
        invalidValue(static_cast<int>(type)) {
    }

    int getInvalidValue() const noexcept {
        return invalidValue;
    }

private:
    int invalidValue;
};

#endif