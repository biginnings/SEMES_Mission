#include "Car.h"
#include "../../Parts/Engine/EngineFactory.cpp"
#include "../../Parts/Break/Break.cpp"
#define CLEAR_SCREEN "\033[H\033[2J"

int Car::selectEngine() {
	//printf(CLEAR_SCREEN);
	printf("� ������ ž���ұ��?\n");
	printf("0. �ڷΰ���\n");
	printf("1. GM\n");
	printf("2. TOYOTA\n");
	printf("3. WIA\n");
	printf("4. ���峭 ����\n");
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
	printf("� ������ġ�� �����ұ��?\n");
	printf("0. �ڷΰ���\n");
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
		std::cout << "������ ���峵���ϴ�.\n";
		std::cout << "�ڵ����� �������� �ʽ��ϴ�.\n";
	}
	else {
		std::cout << "�ڵ����� ���۵˴ϴ�\n";
	}
}

void Car::testProducedCar() {
	if (getCarType() == CarType::SEDAN && getBreakType() == BreakType::CONTINENTAL) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "Sedan�� Continental ������ġ�� �� �� �����ϴ�\n";
	}
	else if (getCarType() == CarType::SUV && getEngineType() == EngineType::TOYOTA) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "SUV�� ����Ÿ ������ �� �� �����ϴ�.\n";
	}
	else if (getCarType() == CarType::TRUCK && getEngineType() == EngineType::WIA) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "Truck�� WIA ������ �� �� �����ϴ�.\n";
	}
	else if (getCarType() == CarType::TRUCK && getBreakType() == BreakType::MANDO) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "Truck�� MANDO ������ġ�� �� �� �����ϴ�.\n";
	}
	else if (getBreakType() == BreakType::BOSCH_B && getSteeringType() != SteeringType::BOSCH_S) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�.\n";
	}
	else if (getBreakType() != BreakType::BOSCH_B && getSteeringType() == SteeringType::BOSCH_S) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�.\n";
	}
}