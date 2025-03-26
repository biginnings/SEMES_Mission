#ifndef WIA_ENGINE_H
#define WIA_ENGINE_H

#include "../../include.h"
#include <iostream>

class WiaEngine : public Engine {
public:
    WiaEngine() {}
    ~WiaEngine() {}

    std::string getBrandName() const override {
        return "Wia";
    }
};

#endif