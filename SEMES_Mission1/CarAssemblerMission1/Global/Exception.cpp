#pragma once
//
//#include <string>
//#include <stdexcept>
//
//class Exception :public std::exception {
//public:
//	const char* what() const noexcept override {
//		return "Input error occurred";
//	}
//
//	void length(std::string s) {
//		if (s.length() > 1) {
//			throw std::runtime_error("Input length exceeds 1");
//		}
//	}
//
//	void isNum(char c) {
//		if (isdigit(c)) {
//			throw std::runtime_error("Input is not number");
//		}
//	}
//
//	virtual void isValidNum(int num) = 0;
//};