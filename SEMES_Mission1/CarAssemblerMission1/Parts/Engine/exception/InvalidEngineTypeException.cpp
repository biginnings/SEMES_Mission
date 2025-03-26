#include <stdexcept>
#include <string>
#include "../../../include.h"

#ifndef INVALID_ENGINE_TYPE_EXCEPTION_H
#define INVALID_ENGINE_TYPE_EXCEPTION_H

class InvalidEngineTypeException : public std::runtime_error {
public:
    explicit InvalidEngineTypeException(const EngineType& type)
        : std::runtime_error("Invalid EngineType value: " + std::to_string(type)),
        invalidValue(type) {
    }

    int getInvalidValue() const noexcept {
        return invalidValue;
    }

private:
    int invalidValue;
};

#endif