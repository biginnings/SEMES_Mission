#include "CarAssembler.h"
#include "../Domain/Car/exception/NotFoundCarException.h"
#include "exception/InvalidSelectNumberException.h"
#include "exception/NonNumericInputException.h"
#include "../Domain/Enum/StepType.cpp"
#define CLEAR_SCREEN "\033[H\033[2J"

CarAssembler* CarAssembler::instance = nullptr;
CarFactory* CarAssembler::carFactory = nullptr;

CarAssembler* CarAssembler::getInstance() {
    if (instance == nullptr) {
        carFactory = new CarFactory();
        instance = new CarAssembler();
    }
    return instance;
}

void CarAssembler::destroyInstance() {
    delete instance;
    instance = nullptr;
    delete carFactory;
    carFactory = nullptr;
}

int CarAssembler::selectCarType() {
    printf(CLEAR_SCREEN);
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
    std::cout << "�Է� : ";
    std::string input;
    std::getline(std::cin, input);
    int selectNumber = std::stoi(input);
    if (selectNumber < 1 || selectNumber > 3) throw InvalidSelectNumberException(selectNumber);

    CarType inputCarType = static_cast<CarType>(selectNumber);
    car = carFactory->createCar(inputCarType);
    carType = inputCarType;
}

int CarAssembler::selectTestOrRun() {
    printf(CLEAR_SCREEN);
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
    std::cout << "�Է� : ";
    std::string input;
    std::getline(std::cin, input);
    int selectNumber = std::stoi(input);
    if (selectNumber < 0 || selectNumber > 2) throw InvalidSelectNumberException(selectNumber);
    return selectNumber;
}

void CarAssembler::getCurrentStatus() {

}

Car* CarAssembler::getCar() {
    if (car == nullptr) throw NotFoundCarException();
    return car;
}

void CarAssembler::start() {
    StepType step = StepType::CarStep;
    int selectNumber = 0;
    while (step != StepType::End) {
        try {
            switch (step) {
            case StepType::CarStep: {
                selectNumber = selectCarType();
                step = StepType::EngineStep;
                break;
            }
            case StepType::EngineStep: {
                selectNumber = car->selectEngine();
                if (selectNumber == 0) {
                    step = StepType::CarStep;
                    break;
                }
                step = StepType::BreakStep;
                break;
            }
            case StepType::BreakStep: {
                selectNumber = car->selectBreakSystem();
                if (selectNumber == 0) {
                    step = StepType::EngineStep;
                    break;
                }
                step = StepType::SteeringStep;
                break;
            }
            case StepType::SteeringStep: {
                selectNumber = car->selectSteeringSystem();
                if (selectNumber == 0) {
                    step = StepType::BreakStep;
                    break;
                }
                step = StepType::RunTestStep;
                break;
            }
            case StepType::RunTestStep: {
                selectNumber = selectTestOrRun();
                if (selectNumber == 0) {
                    step = StepType::CarStep;
                    break;
                }
                else if (selectNumber == 1) {
                    car->runProducedCar();
                }
                else if (selectNumber == 2) {
                    car->testProducedCar();
                }
                step = StepType::End;
                break;
            }
            }

        }
        catch (const std::invalid_argument&) {
            std::cout << std::endl;
            std::cerr << "[CarAssembler] ���� �߻�: �ùٸ� ���� �Է����ּ���." << std::endl;
            waitForEnter();
        }
        catch (const InvalidSelectNumberException& ex) {
            std::cout << std::endl;
            std::cerr << "[CarAssembler] ���� �߻�: " << ex.what()
                << " (�Է°�: " << ex.getInvalidValue() << ")" << std::endl;
            waitForEnter();
        }
        catch (const InvalidCarTypeException& ex) {
            std::cout << std::endl;
            std::cerr << "[CarAssembler] ���� �߻�: " << ex.what()
                << " (�Է°�: " << ex.getInvalidValue() << ")" << std::endl;
            waitForEnter();
        }
        catch (const NotFoundCarException& ex) {
            std::cout << std::endl;
            std::cerr << "[CarAssembler] ���� �߻�: " << ex.what() << std::endl;
            waitForEnter();
        }
    }
    std::cout << std::endl;
    std::cout << "[Program Exit] Bye Bye~" << std::endl;
}

void CarAssembler::waitForEnter() {
    std::cout << "���͸� ������ ����մϴ�...";
    std::cin.get();
}

void CarAssembler::setParts(const int part[]) {
    carType = static_cast<CarType>(part[0]);
    if (car == nullptr) {
        car = carFactory->createCar(carType);
    }
    car->setParts(part);
}

int CarAssembler::socketRun() {
    return car->socketRun();
}

int CarAssembler::socketTest() {
    return car->socketTest();
}