#include "Car.h"
#include "../../Parts/Engine/EngineFactory.cpp"
#include "../../Parts/Break/Break.cpp"
#include "../../Parts/Break/BreakFactory.cpp"
#include "../../Parts/Steering/SteeringFactory.cpp"
#include "../../CarAssembler/exception/InvalidSelectNumberException.h"
#define CLEAR_SCREEN "\033[H\033[2J"

int Car::selectEngine() {
	printf(CLEAR_SCREEN);
	printf("어떤 엔진을 탑재할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. GM\n");
	printf("2. TOYOTA\n");
	printf("3. WIA\n");
	printf("4. 고장난 엔진\n");
	std::cout << "입력 : ";
	std::string input;
	std::getline(std::cin, input);
	int selectNumber = std::stoi(input);
	if (selectNumber == 0) return 0;
    
	EngineType selectEngineType = static_cast<EngineType>(selectNumber);
    engine = EngineFactory::createEngine(selectEngineType);
	engineType = selectEngineType;

	std::cout << std::endl << selectEngineType << " 엔진을 선택하셨습니다.\n";
	waitForEnter();
	return selectNumber;
}

int Car::selectBreakSystem() {
	printf(CLEAR_SCREEN);
	printf("어떤 제동장치를 선택할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. MANDO\n");
	printf("2. CONTINENTAL\n");
	printf("3. BOSCH\n");
	std::cout << "입력 : ";
	std::string input;
	std::getline(std::cin, input);
	int selectNumber = std::stoi(input);
	if (selectNumber == 0) return 0;
	if (selectNumber < 1 || selectNumber > 3) throw InvalidSelectNumberException(selectNumber);

	BreakType selectBreakType = static_cast<BreakType>(selectNumber);
	breakSystem = BreakFactory::createBreak(selectBreakType);
	breakType = selectBreakType;
	return selectNumber;
}

int Car::selectSteeringSystem() {
	printf(CLEAR_SCREEN);
	printf("어떤 조향장치를 선택할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. BOSCH\n");
	printf("2. MOBIS\n");
	std::cout << "입력 : ";
	std::string input;
	std::getline(std::cin, input);
	int selectNumber = std::stoi(input);
	if (selectNumber == 0) return 0;
	if (selectNumber < 1 || selectNumber > 2) throw InvalidSelectNumberException(selectNumber);

	SteeringType selectSteeringType = static_cast<SteeringType>(selectNumber);
	steering = SteeringFactory::createSteering(selectSteeringType);
	steeringType = selectSteeringType;
	return selectNumber;
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
	std::cout << std::endl;
	if (getEngineType() == EngineType::BROKEN) {
		std::cout << "엔진이 고장났습니다.\n";
		std::cout << "자동차가 움직이지 않습니다.\n";
	}
	else {
		std::cout << "자동차가 동작됩니다\n";
	}
}

void Car::testProducedCar() {
	std::cout << std::endl;
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
	else if (getBreakType() == BreakType::BOSCH_B && getSteeringType() != SteeringType::BOSCH) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "제동장치에 Bosch 제품을 썼다면, 조향장치도 Bosch 제품을 써야합니다.\n";
	}
	else if (getBreakType() != BreakType::BOSCH_B && getSteeringType() == SteeringType::BOSCH) {
		std::cout << "자동차 테스트 결과 : FAIL\n";
		std::cout << "조향장치에 Bosch 제품을 썼다면, 제동장치도 Bosch 제품을 써야합니다.\n";
	}
	else {
		std::cout << "자동차 테스트 결과 : PASS\n";
	}
}

void Car::waitForEnter() {
	std::cout << "엔터를 누르면 계속합니다...";
	std::cin.get();
}

void Car::setParts(const int part[]) {
	engineType = static_cast<EngineType>(part[1]);
	breakType = static_cast<BreakType>(part[2]);
	steeringType = static_cast<SteeringType>(part[3]);
}


int Car::socketRun() {
	if (getEngineType() == EngineType::BROKEN) {
		return 1;
	}
	else {
		return 2;
	}
}

int Car::socketTest() {
	if (getCarType() == CarType::SEDAN && getBreakType() == BreakType::CONTINENTAL) {
		return 1;
	}
	else if (getCarType() == CarType::SUV && getEngineType() == EngineType::TOYOTA) {
		return 2;
	}
	else if (getCarType() == CarType::TRUCK && getEngineType() == EngineType::WIA) {
		return 3;
	}
	else if (getCarType() == CarType::TRUCK && getBreakType() == BreakType::MANDO) {
		return 4;
	}
	else if (getBreakType() == BreakType::BOSCH_B && getSteeringType() != SteeringType::BOSCH) {
		return 5;
	}
	else if (getBreakType() != BreakType::BOSCH_B && getSteeringType() == SteeringType::BOSCH) {
		return 6;
	}
	else {
		return 7;
	}
}