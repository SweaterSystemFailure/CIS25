#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace gradebook {

	unsigned unsignedValidator(const std::string& prompt, unsigned min, unsigned max);
	std::string stringValidator(const std::string& prompt);
	bool userCheck();
	char charValidator(const std::string& prompt, const std::vector<char>& validOptions);
	float floatValidator(const std::string& prompt, float min, float max);
	float scorer();

}