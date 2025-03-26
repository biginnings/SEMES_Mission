#include "../../include.h"

#ifndef BREAK_FACTORY_H
#define BREAK_FACTORY_H

class BreakFactory {
public:
	static Break* createBreak(const BreakType& type) {
		if (type == BreakType::MANDO) return new MandoBreak();
		else if (type == BreakType::CONTINENTAL) return new ContinentalBreak();
		else if (type == BreakType::BOSCH_B) return new BoschBreak();
		else throw InvalidBreakTypeException(type);
	}
};

#endif