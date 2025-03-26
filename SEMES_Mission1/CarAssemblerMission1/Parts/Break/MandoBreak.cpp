#ifndef MANDO_BREAK_H
#define MANDO_BREAK_H

#include "../../include.h"

class MandoBreak : public Break {
public:
	MandoBreak() {}
	~MandoBreak() {}

	std::string getBrandName() const override {
		return "Mando";
	}
};

#endif