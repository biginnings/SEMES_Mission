#ifndef Bosch_BREAK_H
#define Bosch_BREAK_H

#include "../../include.h"

class BoschBreak : public Break {
public:
	BoschBreak() {}
	~BoschBreak() {}

	std::string getBrandName() const override {
		return "Bosch";
	}
};

#endif