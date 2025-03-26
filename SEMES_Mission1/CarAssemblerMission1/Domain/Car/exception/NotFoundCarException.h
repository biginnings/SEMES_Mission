#include <stdexcept>
#include <string>

#ifndef NOT_FOUNT_CAR_EXCEPTION_H
#define NOT_FOUNT_CAR_EXCEPTION_H

class NotFoundCarException : public std::runtime_error {
public:
    explicit NotFoundCarException()
        : std::runtime_error("Not Found Car Exception") {
    }
};

#endif