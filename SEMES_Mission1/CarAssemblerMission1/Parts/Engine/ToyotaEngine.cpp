#ifndef TOYOTA_ENGINE_H
#define TOYOTA_ENGINE_H

#include "../../include.h"
#include <iostream>

class ToyotaEngine : public Engine {
public:
    ToyotaEngine() {}
    ~ToyotaEngine() {}

    std::string getBrandName() const override {
        return "Toyota";
    }
};

#endif