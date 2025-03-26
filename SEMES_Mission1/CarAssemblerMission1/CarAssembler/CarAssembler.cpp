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
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
    std::cout << "입력 : ";
    std::string input;
    std::getline(std::cin, input);
    int selectNumber = std::stoi(input);
    if (selectNumber < 1 || selectNumber > 3) throw InvalidSelectNumberException(selectNumber);

    CarType inputCarType = static_cast<CarType>(selectNumber);
    car = carFactory->createCar(inputCarType);
    carType = inputCarType;
}

Car* CarAssembler::getCar() {
    if (car == nullptr) throw NotFoundCarException();
    return car;
}

void CarAssembler::start() {
    StepType step = StepType::CarStep;
    int selectNumber = 0;
    while (step!=StepType::End) {
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
                std::cout << "val=" << selectNumber << std::endl;
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
                car->runProducedCar();
                if (selectNumber == 0) {
                    step = StepType::SteeringStep;
                    break;
                }
                step = StepType::End;
                break;
            }
            }
            
        }
        catch (const std::invalid_argument&) {
            std::cerr << "[CarAssembler] 예외 발생: 올바른 수를 입력해주세요." << std::endl;
        }
        catch (const InvalidSelectNumberException& ex) {
            std::cerr << "[CarAssembler] 예외 발생: " << ex.what()
                << " (입력값: " << ex.getInvalidValue() << ")" << std::endl;
        }
        catch (const InvalidCarTypeException& ex) {
            std::cerr << "[CarAssembler] 예외 발생: " << ex.what()
                << " (입력값: " << ex.getInvalidValue() << ")" << std::endl;
        }
        catch (const NotFoundCarException& ex) {
            std::cerr << "[CarAssembler] 예외 발생: " << ex.what() << std::endl;
        }
    }
    std::cout << "test" << std::endl;
}
