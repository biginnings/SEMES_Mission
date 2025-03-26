#include <stdexcept>
#include <string>

#ifndef NON_NUMERIC_INPUT_EXCEPTION_H
#define NON_NUMERIC_INPUT_EXCEPTION_H

class NonNumericInputException : public std::runtime_error {
public:
    explicit NonNumericInputException(const std::string& type)
        : std::runtime_error("Invalid SelectNumber value: " + type),
        invalidValue(type) {
    }

    std::string getInvalidValue() const noexcept {
        return invalidValue;
    }

private:
    std::string invalidValue;
};

#endif