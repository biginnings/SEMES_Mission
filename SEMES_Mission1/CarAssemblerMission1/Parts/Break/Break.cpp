#ifndef BREAK_INTERFACE_H
#define BREAK_INTERFACE_H

#include<string>

class Break {
private:

public:
	virtual ~Break() {}
	virtual std::string getBrandName() const = 0;
};

#endif