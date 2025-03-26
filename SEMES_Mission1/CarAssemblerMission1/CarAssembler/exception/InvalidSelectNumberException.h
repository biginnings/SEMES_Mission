#include <stdexcept>
#include <string>

#ifndef INVALID_SELECT_NUMBER_EXCEPTION_H
#define INVALID_SELECT_NUMBER_EXCEPTION_H

class InvalidSelectNumberException : public std::runtime_error {
public:
    explicit InvalidSelectNumberException(const int& type)
        : std::runtime_error("Invalid SelectNumber value: " + std::to_string(type)),
        invalidValue(type) {
    }

    int getInvalidValue() const noexcept {
        return invalidValue;
    }

private:
    int invalidValue;
};

#endif