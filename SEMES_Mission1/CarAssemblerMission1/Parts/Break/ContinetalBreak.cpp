#ifndef Continetal_BREAK_H
#define Continental_BREAK_H

#include "../../include.h"

class ContinentalBreak : public Break {
public:
	ContinentalBreak() {}
	~ContinentalBreak() {}

	std::string getBrandName() const override {
		return "Continental";
	}
};

#endif