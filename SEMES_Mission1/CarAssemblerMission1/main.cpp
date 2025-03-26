#include <iostream>
#include "include.h"
#include "CarAssembler/CarAssembler.h"

int main() {
	CarAssembler::getInstance()->start();
	return 0;
}