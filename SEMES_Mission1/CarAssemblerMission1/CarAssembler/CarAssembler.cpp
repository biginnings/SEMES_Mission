#include "CarAssembler.h"
#include "../Domain/Car/exception/NotFoundCarException.h"
#include "exception/InvalidSelectNumberException.h"
#include "exception/NonNumericInputException.h"
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

void CarAssembler::selectCarType() {
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
    while (true) {
        try {
            if(!car) selectCarType();
            if(!car->getEngineType()) car->selectEngine();
            //if(!car->getBreakType()) car->selectBreakSystem();
            //if (!car->getSteeringType()) car->selectSteeringSystem();
            break;
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
    
}
