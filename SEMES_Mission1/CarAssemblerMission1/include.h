#ifndef INCLUDE_H
#define INCLUDE_H

#include <string>


// === Enums ===
#include "Domain/Enum/CarType.cpp"
#include "Domain/Enum/BreakType.cpp"
#include "Domain/Enum/SteeringType.cpp"
#include "Domain/Enum/EngineType.cpp"

#include "Domain/Car/exception/InvalidCarTypeException.h"
// === Parts ===
#include "Parts/Engine/Engine.cpp"
#include "Parts/Engine/GmEngine.cpp"
#include "Parts/Engine/ToyotaEngine.cpp"
#include "Parts/Engine/WiaEngine.cpp"
#include "Parts/Engine/exception/InvalidEngineTypeException.cpp"

#include "Parts/Break/Break.cpp"

#include "Parts/Steering/Steering.cpp"
#include "Parts/Steering/MobisSteering.cpp"
#include "Parts/Steering/BoschSteering.cpp"
#include "Parts/Steering/SteeringFactory.cpp"
#include "Parts/Steering/SteeringException.cpp"

// === Domain / Car ===
#include "Domain/Car/Car.h"
#include "Domain/Car/Sedan.cpp"
#include "Domain/Car/Suv.cpp"
#include "Domain/Car/Truck.cpp"
#include "Domain/Car/CarFactory.cpp"

// === Application ===
#include "CarAssembler/CarAssembler.h"

// === Exceptoin ===
#include "Global/Exception.cpp"

#endif // INCLUDE_H
