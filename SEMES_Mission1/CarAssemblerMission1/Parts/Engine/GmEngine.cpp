#ifndef GM_ENGINE_H
#define GM_ENGINE_H

#include <iostream>
#include "../../include.h"

class GmEngine : public Engine {
public:
    GmEngine() {}
    ~GmEngine() {}

    std::string getBrandName() const override {
        return "GM";
    }
};

#endif