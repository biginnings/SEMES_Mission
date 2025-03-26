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
	if (getEngineType() == EngineType::BROKEN) {
		std::cout << "엔진이 고장났습니다.\n";
		std::cout << "자동차가 움직이지 않습니다.\n";
	}
	else {
		std::cout << "자동차가 동작됩니다\n";
	}
}

void Car::testProducedCar() {
	if (getCarType() == CarType::SEDAN && getBreakType() == BreakType::CONTINENTAL) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "Sedan은 Continental 제동장치를 쓸 수 없습니다\n";
	}
	else if (getCarType() == CarType::SUV && getEngineType() == EngineType::TOYOTA) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "SUV는 도요타 엔진을 쓸 수 없습니다.\n";
	}
	else if (getCarType() == CarType::TRUCK && getEngineType() == EngineType::WIA) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "Truck은 WIA 엔진을 쓸 수 없습니다.\n";
	}
	else if (getCarType() == CarType::TRUCK && getBreakType() == BreakType::MANDO) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "Truck은 MANDO 제동장치를 쓸 수 없습니다.\n";
	}
	else if (getBreakType() == BreakType::BOSCH_B && getSteeringType() != SteeringType::BOSCH_S) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "제동장치에 Bosch 제품을 썼다면, 조향장치도 Bosch 제품을 써야합니다.\n";
	}
	else if (getBreakType() != BreakType::BOSCH_B && getSteeringType() == SteeringType::BOSCH_S) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "조향장치에 Bosch 제품을 썼다면, 제동장치도 Bosch 제품을 써야합니다.\n";
	}
}