#include "Car.h"
#include "../../Parts/Engine/EngineFactory.cpp"
#include "../../Parts/Break/Break.cpp"
#include "../../Parts/Break/BreakFactory.cpp"
#include "../../Parts/Steering/SteeringFactory.cpp"
#include "../../CarAssembler/exception/InvalidSelectNumberException.h"
#define CLEAR_SCREEN "\033[H\033[2J"

int Car::selectEngine() {
	printf(CLEAR_SCREEN);
	printf("� ������ ž���ұ��?\n");
	printf("0. �ڷΰ���\n");
	printf("1. GM\n");
	printf("2. TOYOTA\n");
	printf("3. WIA\n");
	printf("4. ���峭 ����\n");
	std::cout << "�Է� : ";
	std::string input;
	std::getline(std::cin, input);
	int selectNumber = std::stoi(input);
	if (selectNumber == 0) return 0;
    
	EngineType selectEngineType = static_cast<EngineType>(selectNumber);
    engine = EngineFactory::createEngine(selectEngineType);
	engineType = selectEngineType;

	std::cout << std::endl << selectEngineType << " ������ �����ϼ̽��ϴ�.\n";
	waitForEnter();
	return selectNumber;
}

int Car::selectBreakSystem() {
	printf(CLEAR_SCREEN);
	printf("� ������ġ�� �����ұ��?\n");
	printf("0. �ڷΰ���\n");
	printf("1. MANDO\n");
	printf("2. CONTINENTAL\n");
	printf("3. BOSCH\n");
	std::cout << "�Է� : ";
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
	printf("� ������ġ�� �����ұ��?\n");
	printf("0. �ڷΰ���\n");
	printf("1. BOSCH\n");
	printf("2. MOBIS\n");
	std::cout << "�Է� : ";
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
		std::cout << "������ ���峵���ϴ�.\n";
		std::cout << "�ڵ����� �������� �ʽ��ϴ�.\n";
	}
	else {
		std::cout << "�ڵ����� ���۵˴ϴ�\n";
	}
}

void Car::testProducedCar() {
	std::cout << std::endl;
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
	else if (getBreakType() == BreakType::BOSCH_B && getSteeringType() != SteeringType::BOSCH) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�.\n";
	}
	else if (getBreakType() != BreakType::BOSCH_B && getSteeringType() == SteeringType::BOSCH) {
		std::cout << "�ڵ��� �׽�Ʈ ��� : FAIL\n";
		std::cout << "������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�.\n";
	}
	else {
		std::cout << "�ڵ��� �׽�Ʈ ��� : PASS\n";
	}
}

void Car::waitForEnter() {
	std::cout << "���͸� ������ ����մϴ�...";
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