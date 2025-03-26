#include "Car.h"
#include "../../Parts/Engine/EngineFactory.cpp"
#include "../../Parts/Break/Break.cpp"
#define CLEAR_SCREEN "\033[H\033[2J"

int Car::selectEngine() {
	//printf(CLEAR_SCREEN);
	printf("어떤 엔진을 탑재할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. GM\n");
	printf("2. TOYOTA\n");
	printf("3. WIA\n");
	printf("4. 고장난 엔진\n");
	int selectNumber;
	std::cin >> selectNumber;
	if (selectNumber == 0) return 0;
    
	EngineType selectEngineType = static_cast<EngineType>(selectNumber);
    engine = EngineFactory::createEngine(selectEngineType);
	engineType = selectEngineType;
	return selectNumber;
}

int Car::selectBreakSystem() {
	return 0;
}

int Car::selectSteeringSystem() {
	return 0;
}

EngineType Car::getEngineType() {
	return engineType;
}

BreakType Car::getBreakType() {
	return breakType;
}

SteeringType Car::getSteeringType() {
	return steeringType;
}

void Car::runProducedCar() {
}

void Car::testProducedCar() {
}