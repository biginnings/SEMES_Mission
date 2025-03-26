#include "../include.h"
#include <iostream>

#ifndef CARASSEMBLER_H
#define CARASSEMBLER_H


class CarAssembler {
private:
    static CarAssembler* instance;
    static CarFactory* carFactory;

    CarAssembler() {}
    Car* car = nullptr;
    CarType carType;

public:
    static CarAssembler* getInstance();
    void destroyInstance();
    void start();
    int selectCarType();
    Car* getCar();
    int selectTestOrRun();
    void getCurrentStatus();
    void waitForEnter();
    void setParts(const int part[]);
    int socketRun();
    int socketTest();
};

#endif
