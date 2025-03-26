#pragma once
#include <stdexcept>
#include <string>
#include "../../../include.h"

#ifndef INVALID_BREAK_TYPE_EXCEPTION_H
#define INVALID_BREAK_TYPE_EXCEPTION_H

class InvalidBreakTypeException : public std::runtime_error {
public:
    explicit InvalidBreakTypeException(const BreakType& type)
        : std::runtime_error("Invalid BreakType value: " + std::to_string(static_cast<int>(type))),
        invalidValue(static_cast<int>(type)) {
    }

    int getInvalidValue() const noexcept {
        return invalidValue;
    }

private:
    int invalidValue;
};

#endif