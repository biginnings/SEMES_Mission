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
	printf(CLEAR_SCREEN);
	printf("어떤 조향장치를 선택할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. BOSCH\n");
	printf("2. MOBIS\n");

	int selectNumber;
	std::cin >> selectNumber;

	/*std::string cmd;
	std::cin >> cmd;

	SteeringException e;
	try {

	}
	e.length(cmd);
	int selectNumber = static_cast<int>(cmd);*/

	SteeringType selectSteeringType = static_cast<SteeringType>(selectNumber);
	steering = SteeringFactory::createSteering(selectSteeringType);
	steeringType = selectSteeringType;
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