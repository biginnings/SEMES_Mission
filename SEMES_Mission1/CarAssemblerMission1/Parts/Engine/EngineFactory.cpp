#include "../../include.h"

#ifndef EngineFactory_H
#define EngineFactory_H

class EngineFactory {
public:
    static Engine* createEngine(const EngineType& type) {
        if (type == EngineType::GM) return new GmEngine();
        else if (type == EngineType::TOYOTA) return new ToyotaEngine();
        else if (type == EngineType::WIA) return new WiaEngine();
        else if (type == EngineType::BROKEN) return nullptr;
        else throw InvalidEngineTypeException(type);
    }
};

#endif